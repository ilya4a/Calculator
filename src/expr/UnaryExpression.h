#ifndef CALCULATOR_UNARYEXPRESSION_H
#define CALCULATOR_UNARYEXPRESSION_H

#include "Expression.h"
#include <memory>

class UnaryExpression : public Expression {
    char operation;
    std::unique_ptr<Expression> expr1;

  public:
    UnaryExpression(char operation, std::unique_ptr<Expression> e);

    std::string get_string() const override;

    double eval() const override;

    ~UnaryExpression() override;
};

#endif // CALCULATOR_UNARYEXPRESSION_H
