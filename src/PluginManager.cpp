//
// Created by ilya on 11/1/25.
#include <filesystem>
#include "PluginManager.h"
#include "../plugin_interface.h"

void PluginManager::load_all_plugins(const std::string &dir) {
    const std::filesystem::path path(dir);
    for (auto &entry: std::filesystem::directory_iterator(path)) {
//        printf("\n --<");
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
        double args[1] = {3.14};
        double res;
        double t = raw_plugin->eval(args, 1, &res);
        printf("\n----> %f", res);
    }
}

PluginManager::~PluginManager() {

}

bool PluginManager::has_plugin(const std::string &name) {
    return false;
}

Plugin *PluginManager::get_plugin(const std::string &name) {
    return nullptr;
}

std::vector<std::string> PluginManager::list() {
    return std::vector<std::string>();
}

