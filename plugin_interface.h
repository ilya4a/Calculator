//
// Created by ilya on 11/2/25.
//

#ifndef CALCULATOR_PLUGIN_INTERFACE_H
#define CALCULATOR_PLUGIN_INTERFACE_H

#include <string>

struct Plugin {
    std::string name;
    int num_of_args;
    using PluginFunction = int (*)(const double *, int, double *);
    PluginFunction eval = nullptr;
};

#ifdef _WIN32
#ifdef PLUGIN_EXPORT
        #define PLUGIN_API __declspec(dllexport)
    #else
        #define PLUGIN_API __declspec(dllimport)
    #endif
#else
#define PLUGIN_API
#endif

extern "C" {
PLUGIN_API Plugin* create_plugin();
PLUGIN_API void destroy_plugin(Plugin*);
}


#endif //CALCULATOR_PLUGIN_INTERFACE_H
