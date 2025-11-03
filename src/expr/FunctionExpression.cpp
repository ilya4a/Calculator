//
// Created by ilya on 11/3/25.
//

#include "FunctionExpression.h"

#include <utility>
#include <iostream>

FunctionExpression::FunctionExpression(std::shared_ptr<Plugin> plugin, std::vector<std::unique_ptr<Expression>> function_args) {
    this->plugin = std::move(plugin);
    this->args = std::move(function_args);
}

std::string FunctionExpression::get_string() const {
    std::string res = plugin->name;
    res += "(";
    for(auto &i: args){
        res += i->get_string();
        res += ", ";
    }
    res.pop_back();
    res.pop_back();
    res += ")";
    return res;
}

double FunctionExpression::eval() const {
    double res = 0;
    int size = args.size();

    if(size != plugin->num_of_args){
        std::string err = "FunctionExpression incorrect number of args of function: ";
        err += plugin->name;
        throw std::runtime_error(err);
    }

    double* num_args = new double[size];

    for (int i = 0; i < size; i++) {
        num_args[i] = args[i]->eval();
    }

    int eval_res = plugin->eval(num_args, size, &res);
    if(eval_res == 1){
        std::string err = "FunctionExpression error in call of function: ";
        err += plugin->name;
        delete[] num_args;
        throw std::runtime_error(err);

    }else if(eval_res == 2){
        delete[] num_args;
        std::string err = "FunctionExpression invalid agrs in function: ";
        err += plugin->name;
        throw std::runtime_error(err);
    }

    delete[] num_args;
    return res;
}

FunctionExpression::~FunctionExpression() = default;
