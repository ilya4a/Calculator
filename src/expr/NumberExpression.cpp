//
// Created by ilya on 10/30/25.
//

#include <ios>
#include <iomanip>
#include <cmath>
#include "NumberExpression.h"

double NumberExpression::eval() const {

    return value;
}

std::string NumberExpression::to_string(double value, int n) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(n) << value;
    return oss.str();
}

std::string NumberExpression::get_string() const{
    if(fabs(value) < 1){
        return to_string(value, 4);
    }else{
        return to_string(value, 2);
    }
}

NumberExpression::NumberExpression(double value) : value(value){}

NumberExpression::~NumberExpression() = default;
