//
// Created by ilya on 10/30/25.
//

#include "UnaryExpression.h"

double UnaryExpression::eval() const {
    if (operation == '-') {
        return -expr1->eval();
    } else {
        return expr1->eval();
    }
    return 0;
}

std::string UnaryExpression::get_string() const {
    return operation + expr1->get_string();
}

UnaryExpression::~UnaryExpression() = default;

UnaryExpression::UnaryExpression(char operation, std::unique_ptr<Expression> e) :
        operation(operation), expr1(std::move(e)) {}
