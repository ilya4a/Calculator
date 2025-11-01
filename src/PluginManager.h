//
// Created by ilya on 11/1/25.
//

#ifndef CALCULATOR_PLUGINMANAGER_H
#define CALCULATOR_PLUGINMANAGER_H

#include <dlfcn.h>
#include <string>
#include <unordered_map>

struct Plugin {
    std::string name;
    int num_of_args;
    using PluginFunction = int (*)(const double *, int, double *, char *, int);
    PluginFunction eval = nullptr;
};

class PluginManager {
    PluginManager() = default;
    ~PluginManager();

    void load_all_plugins();
    void has_plugin(const std::string &name);
    Plugin get_plagin(const std::string &name);

private:
    std::unordered_map<std::string, Plugin> plugins;
};


#endif //CALCULATOR_PLUGINMANAGER_H
