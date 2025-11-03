//
// Created by ilya on 11/2/25.
//

#pragma once

#ifdef _WIN32
#define PLUGIN_EXPORT __declspec(dllexport)
#else
#define PLUGIN_EXPORT
#endif

struct Plugin {
    const char*  name;
    int num_of_args;
    int (*eval)(const double *args, int nargs, double *out);
};

extern "C" Plugin* create_plugin();
extern "C" void destroy_plugin(Plugin* plugin);
