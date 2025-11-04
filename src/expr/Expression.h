//
// Created by ilya on 10/30/25.
//

#ifndef CALCULATOR_EXPRESSION_H
#define CALCULATOR_EXPRESSION_H


#include <string>

class Expression {

public:
    virtual std::string get_string() const = 0;

    virtual double eval() const = 0;

    virtual ~Expression() = default;
};


#endif //CALCULATOR_EXPRESSION_H
