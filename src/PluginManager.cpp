//
// Created by ilya on 11/1/25.
#include <filesystem>
#include <iostream>
#include "PluginManager.h"
#include "../plugin_interface.h"

void PluginManager::load_all_plugins(const std::string &dir) {
    const std::filesystem::path path(dir);
    for (auto &entry: std::filesystem::directory_iterator(path)) {

        if (!entry.is_regular_file()) continue;
        if (entry.path().extension() != ".so") continue;

        void* handle = dlopen(entry.path().c_str(), RTLD_LAZY);

        using CreatePluginFunc = Plugin* (*)();

        auto create_plugin = reinterpret_cast<CreatePluginFunc>(
                dlsym(handle, "create_plugin")
        );
        
        using DestroyPluginFunc = void (*)(Plugin*);
        auto destroy_plugin = reinterpret_cast<DestroyPluginFunc>(
                dlsym(handle, "destroy_plugin")
        );

        Plugin* raw_plugin = create_plugin();
        if(raw_plugin){
            auto plugin_deleter = [destroy_plugin, handle](Plugin* p) {
                if (destroy_plugin) {
                    destroy_plugin(p);
                } else {
                    delete p;
                }
                dlclose(handle);
            };
            std::shared_ptr<Plugin> plugin(raw_plugin, plugin_deleter);
            plugins.push_back(plugin);
        }else{
            dlclose(handle);
        }
    }
}


std::shared_ptr<Plugin> PluginManager::get_plugin(const std::string &name) {
    for(const auto& p: plugins){
        if(name == p->name) return p;
    }
    return nullptr;
}


