//
// Created by ilya on 11/1/25.
//
extern "C" {

const char* plugin_name() { return "sin"; }
int num_of_args() { return 1; }

int eval(const double* args, int nargs, double* out, char* errbuf, int errlen) {

    return 0;
}

}
