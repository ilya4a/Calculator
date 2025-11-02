//
// Created by ilya on 11/1/25.
#include <filesystem>
#include <iostream>
#include "PluginManager.h"
#include "../plugin_interface.h"

bool PluginManager::check_entry(std::filesystem::directory_entry entry) {
    if (!entry.is_regular_file()) return false;
    if (!entry.is_regular_file()) return false;
    return entry.path().extension() == LIB_EXT;
}

PluginManager::LibraryHandle PluginManager::load_library(const std::string& path) {
#ifdef _WIN32
    return LoadLibraryA(path.c_str());
#else
    return dlopen(path.c_str(), RTLD_LAZY);
#endif
}

void PluginManager::close_library(LibraryHandle handle) {
#ifdef _WIN32
    if (handle) FreeLibrary(handle);
#else
    if (handle) dlclose(handle);
#endif
}

void* PluginManager::get_symbol(LibraryHandle handle, const std::string& symbol_name) {
#ifdef _WIN32
    return (void*)GetProcAddress(handle, symbol_name.c_str());
#else
    return dlsym(handle, symbol_name.c_str());
#endif
}

void PluginManager::load_all_plugins(const std::string &dir) {
    const std::filesystem::path path(dir);
    for (auto &entry: std::filesystem::directory_iterator(path)) {

        if(!check_entry(entry)) continue;
        LibraryHandle handle = load_library(entry.path().string());

        using CreatePluginFunc = Plugin* (*)();
        auto create_plugin = reinterpret_cast<CreatePluginFunc>(
                get_symbol(handle, "create_plugin")
        );
//        if(create_plugin == nullptr) {
//            std::cerr << "Cannot load symbol create_plugin from "<< entry.path()  << std::endl;
//            continue;
//        }

        using DestroyPluginFunc = void (*)(Plugin*);
        auto destroy_plugin = reinterpret_cast<DestroyPluginFunc>(
                get_symbol(handle, "destroy_plugin")
        );
//        if(destroy_plugin == nullptr) {
//            std::cerr << "Cannot load symbol destroy_plugin from "<< entry.path()  << std::endl;
//            continue;
//        }

        Plugin* raw_plugin = create_plugin();
        if(raw_plugin){
            auto plugin_deleter = [destroy_plugin, handle](Plugin* p) {
                if (destroy_plugin) {
                    destroy_plugin(p);
                } else {
                    delete p;
                }
                #ifdef _WIN32
                    FreeLibrary(handle);
                #else
                    dlclose(handle);
                #endif
            };
            std::shared_ptr<Plugin> plugin(raw_plugin, plugin_deleter);
            plugins.push_back(plugin);
        }else{
            close_library(handle);
        }
    }
}


std::shared_ptr<Plugin> PluginManager::get_plugin(const std::string &name) {
    for(const auto& p: plugins){
        if(name == p->name) return p;
    }
    return nullptr;
}

