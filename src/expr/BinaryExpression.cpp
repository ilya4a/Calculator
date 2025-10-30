//
// Created by ilya on 10/30/25.
//

#include "BinaryExpression.h"

std::string BinaryExpression::get_string() const {
    return expr1->get_string() + operation + expr2->get_string();
}

double BinaryExpression::eval() const {
    switch (operation) {
        case '-': return expr1->eval() - expr2->eval();
        case '*': return expr1->eval() * expr2->eval();
        case '/': return expr1->eval() / expr2->eval();
        default: return expr1->eval() + expr2->eval();
    }
    return 0;
}

BinaryExpression::BinaryExpression(char operation, std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2)
: operation(operation), expr1(std::move(e1)), expr2(std::move(e2)){}

BinaryExpression::~BinaryExpression() = default;