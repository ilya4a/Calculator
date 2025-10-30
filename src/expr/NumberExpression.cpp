//
// Created by ilya on 10/30/25.
//

#include "NumberExpression.h"

double NumberExpression::eval() const {

    return value;
}

std::string NumberExpression::get_string() const{
    return std::to_string(value);
}

NumberExpression::NumberExpression(double value) : value(value){}

NumberExpression::~NumberExpression() = default;
