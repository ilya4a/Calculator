//
// Created by ilya on 11/3/25.
//

#include "FunctionExpression.h"

#include <utility>

FunctionExpression::FunctionExpression(std::shared_ptr<Plugin> plugin, std::vector<std::unique_ptr<Expression>> function_args) {
    this->plugin = std::move(plugin);
    this->args = std::move(function_args);
}

std::string FunctionExpression::get_string() const {
    return plugin->name;
}

double FunctionExpression::eval() const {
    double res = 0;
    int size = args.size();
    // check !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    double* num_args = new double[size];

    for (int i = 0; i < size; i++) {
        num_args[i] = args[i]->eval();
    }

    plugin->eval(num_args, size, &res);

    delete[] num_args;
    return res;
}

FunctionExpression::~FunctionExpression() = default;
