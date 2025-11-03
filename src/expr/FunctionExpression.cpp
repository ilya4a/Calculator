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
        std::cerr << "incorrect number if args of function: " << plugin->name << std::endl;
        return 0;
    }

    double* num_args = new double[size];

    for (int i = 0; i < size; i++) {
        num_args[i] = args[i]->eval();
    }

    int eval_res = plugin->eval(num_args, size, &res);
    if(eval_res == 1){
        std::cerr << "error in call of function: " << plugin->name << std::endl;
        delete[] num_args;
        return 0;

    }else if(eval_res == 2){
        std::cerr << "invalid agrs in function: " << plugin->name << std::endl;
        delete[] num_args;
        return 0;
    }



    delete[] num_args;
    return res;
}

FunctionExpression::~FunctionExpression() = default;
