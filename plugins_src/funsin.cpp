//
// Created by ilya on 11/1/25.
//

#include <cmath>
#include "../plugin_interface.h"

int eval(const double* args, int nargs, double* out){
    if(nargs != 1) return 1;
    double deg = args[0];
    // double rad = deg * M_PI / 180.0;
    *out = sin(deg);
    return 0;
}

extern "C" Plugin * create_plugin(){
    Plugin* p = new Plugin;
    p->num_of_args = 1;
    p->name = "sin";
    p->eval = eval;
    return p;
}

extern "C" void destroy_plugin(Plugin* plugin) {
    delete plugin;
}