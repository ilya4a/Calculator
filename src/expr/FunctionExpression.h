#ifndef CALCULATOR_FUNCTIONEXPRESSION_H
#define CALCULATOR_FUNCTIONEXPRESSION_H

#include "Expression.h"
#include "plugin_interface.h"
#include <memory>
#include <vector>

class FunctionExpression : public Expression {
    std::shared_ptr<Plugin> plugin;
    std::vector<std::unique_ptr<Expression>> args;

  public:
    FunctionExpression(std::shared_ptr<Plugin> plugin, std::vector<std::unique_ptr<Expression>> function_args);

    std::string get_string() const override;

    double eval() const override;

    ~FunctionExpression() override;
};

#endif // CALCULATOR_FUNCTIONEXPRESSION_H
