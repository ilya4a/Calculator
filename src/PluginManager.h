//
// Created by ilya on 11/1/25.
//
#ifndef CALCULATOR_PLUGINMANAGER_H
#define CALCULATOR_PLUGINMANAGER_H

#include <dlfcn.h>
#include <string>
#include <unordered_map>

#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#include <vector>
#include "../plugin_interface.h"

#endif
//    #ifdef _WIN32
//        HMODULE handle = nullptr;
//    #else
//        void* handle = nullptr;
//    #endif
class PluginManager {

    std::unordered_map<std::string, Plugin> plugins;

public:

    PluginManager() = default;
    ~PluginManager();

    void load_all_plugins(const std::string& dir);
    bool has_plugin(const std::string &name);
    Plugin* get_plugin(const std::string &name);

    std::vector<std::string> list();
};

#endif //CALCULATOR_PLUGINMANAGER_H
