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

#endif //CALCULATOR_PLUGIN_INTERFACE_H
