#include "plugin_interface.h"
#include <cmath>
#include <numbers>

int eval(const double *args, int nargs, double *out) {
    if (nargs != 1 || args == nullptr || out == nullptr) {
        return 1;
    }

    constexpr double PI = std::numbers::pi;

    *out = args[0] * PI / 180.0;

    if (std::isnan(*out) || !std::isfinite(*out)) {
        return 2;
    }

    return 0;
}

extern "C" Plugin *create_plugin() {
    Plugin *p = new Plugin;
    p->num_of_args = 1;
    p->name = "deg";
    p->eval = eval;
    return p;
}

extern "C" void destroy_plugin(Plugin *plugin) {
    delete plugin;
}
