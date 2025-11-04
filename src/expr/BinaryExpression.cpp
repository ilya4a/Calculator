//
// Created by ilya on 10/30/25.
//

#include <valarray>
#include "BinaryExpression.h"
#include "stdexcept"

std::string BinaryExpression::get_string() const {
    return expr1->get_string() + " " + operation + " " + expr2->get_string();
}

double BinaryExpression::eval() const {
    switch (operation) {
        case '-': return expr1->eval() - expr2->eval();
        case '*': return expr1->eval() * expr2->eval();
        case '/': {
            double e2 = expr2->eval();
            if(fabs(e2) < 1e-14){
                throw std::runtime_error("division by zero");
            }

            double e1 = expr1->eval();
            return e1/e2;
        }
        case '^':{
            double res = std::pow(expr1->eval(), expr2->eval());

            if (std::isnan(res) || !std::isfinite(res)) {
                throw std::runtime_error("incorrect power arguments");
            }

            return std::pow(expr1->eval(), expr2->eval());
        }
        default: return expr1->eval() + expr2->eval();
    }
    return 0;
}

BinaryExpression::BinaryExpression(char operation, std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2)
: operation(operation), expr1(std::move(e1)), expr2(std::move(e2)){}

BinaryExpression::~BinaryExpression() = default;