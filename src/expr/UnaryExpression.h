//
// Created by ilya on 10/30/25.
//

#ifndef CALCULATOR_UNARYEXPRESSION_H
#define CALCULATOR_UNARYEXPRESSION_H


#include <memory>
#include "Expression.h"

class UnaryExpression : Expression {
    char operation;
    std::unique_ptr<Expression> expr1;

public:
    UnaryExpression(char operation,  std::unique_ptr<Expression> e);
    std::string get_string() const override;
    double eval() const override;
    ~UnaryExpression() override;
};


#endif //CALCULATOR_UNARYEXPRESSION_H
