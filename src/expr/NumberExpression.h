//
// Created by ilya on 10/30/25.
//

#ifndef CALCULATOR_NUMBEREXPRESSION_H
#define CALCULATOR_NUMBEREXPRESSION_H


#include "Expression.h"

class NumberExpression : public Expression {
    double value;
    static std::string to_string(double value, int n);
public:
    NumberExpression(double value);
    std::string get_string() const override;
    double eval() const override;
    ~NumberExpression() override;
};


#endif //CALCULATOR_NUMBEREXPRESSION_H
