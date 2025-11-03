//
// Created by ilya on 11/1/25.
//

#include <cmath>
#include "../plugin_interface.h"

int eval(const double* args, int nargs, double* out){
    if(nargs != 2 || args == nullptr || out == nullptr) return 1;
    *out = pow(args[0], args[1]);
    return 0;
}

extern "C" Plugin * create_plugin(){
    Plugin* p = new Plugin;
    p->num_of_args = 2;
    p->name = "pow";
    p->eval = eval;
    return p;
}

extern "C" void destroy_plugin(Plugin* plugin) {
    delete plugin;
}
