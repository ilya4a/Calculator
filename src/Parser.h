//
// Created by ilya on 10/30/25.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H


#include <vector>
#include <memory>
#include "Token.h"
#include "expr/Expression.h"
#include "PluginManager.h"

class Parser {
    const Token END_OF_FILE;
    const std::vector<Token> tokens;
    const int size;
    int current_position;

    Token peek(int relative_position);

    bool math_token_with_current(TokenTypeEnum type);

    std::unique_ptr<Expression> expression();
    std::unique_ptr<Expression> additive();
    std::unique_ptr<Expression> multiplicative();
    std::unique_ptr<Expression> unary();
    std::unique_ptr<Expression> primary();
    std::unique_ptr<Expression> parse_function();

    PluginManager pm;

    public:
        explicit Parser(std::vector<Token> toks, PluginManager &pluginManager);
        std::vector<std::unique_ptr<Expression>> parse();

    std::unique_ptr<Expression> power();
};


#endif //CALCULATOR_PARSER_H
