//
// Created by ilya on 10/30/25.
//

#ifndef CALCULATOR_BINARYEXPRESSION_H
#define CALCULATOR_BINARYEXPRESSION_H

#include <memory>
#include "Expression.h"

class BinaryExpression : public Expression {
    char operation;
    std::unique_ptr<Expression> expr1, expr2;

public:
    BinaryExpression(char operation, std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2);

    std::string get_string() const override;

    double eval() const override;

    ~BinaryExpression() override;

};


#endif //CALCULATOR_BINARYEXPRESSION_H
