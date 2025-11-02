//
// Created by ilya on 11/1/25.
//
#ifndef CALCULATOR_PLUGINMANAGER_H
#define CALCULATOR_PLUGINMANAGER_H

#include <dlfcn.h>
#include <string>
#include <unordered_map>

#include <string>
#include <vector>
#include <memory>
#include <filesystem>
#include "../plugin_interface.h"

#ifdef _WIN32
#include <Windows.h>
    #define LIB_EXT ".dll"
#else
#include <dlfcn.h>
#define LIB_EXT ".so"
#endif

class PluginManager {

    #ifdef _WIN32
        using LibraryHandle = HMODULE;
    #else
        using LibraryHandle = void*;
    #endif


    LibraryHandle load_library(const std::string &path);
    void close_library(LibraryHandle handle);
    void *get_symbol(LibraryHandle handle, const std::string &symbol_name);
    std::vector<std::shared_ptr<Plugin>> plugins;
    bool check_entry(std::filesystem::directory_entry entry);
public:

    PluginManager() = default;

    void load_all_plugins(const std::string& dir);

    std::shared_ptr<Plugin> get_plugin(const std::string &name);

};

#endif //CALCULATOR_PLUGINMANAGER_H
