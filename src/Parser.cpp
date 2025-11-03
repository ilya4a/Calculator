//
// Created by ilya on 10/30/25.
//

#include <iostream>
#include "Parser.h"
#include "expr/NumberExpression.h"
#include "expr/BinaryExpression.h"
#include "expr/UnaryExpression.h"
#include "expr/FunctionExpression.h"


Parser::Parser(std::vector<Token> toks)
        : END_OF_FILE(Token(TokenType::END_OF_FILE, "")),
          tokens(std::move(toks)),
          size(static_cast<int>(tokens.size()))
{
    current_position = 0;
    pm.load_all_plugins("plugins");
}

Token Parser::peek(int relative_position) {
    int pos = current_position + relative_position;
    if (pos >= size) return END_OF_FILE;
    return tokens[pos];
}

bool Parser::math_token_with_current(TokenType type) {
    Token cur = peek(0);
    if(cur.type != type) return false;
    current_position++;
    return true;
}

std::vector<std::unique_ptr<Expression>> Parser::parse() {
    std::vector<std::unique_ptr<Expression>> result;
    while(!math_token_with_current(TokenType::END_OF_FILE)){
        result.push_back(std::move(expression()));
    }
    return result;
}

std::unique_ptr<Expression> Parser::expression() {
    return additive();
}

std::unique_ptr<Expression> Parser::additive() {
    std::unique_ptr<Expression> expr = multiplicative();

    while(true){
        if(math_token_with_current(TokenType::PLUS)) {
            expr = std::make_unique<BinaryExpression>('+', std::move(expr), std::move(multiplicative()));
            continue;
        }if(math_token_with_current(TokenType::MINUS)) {
            expr = std::make_unique<BinaryExpression>('-', std::move(expr), std::move(multiplicative()));
            continue;
        }
        break;
    }
    return expr;
}

std::unique_ptr<Expression> Parser::multiplicative() {
    std::unique_ptr<Expression> expr = unary();

    while(true){
        if(math_token_with_current(TokenType::STAR)) {
            expr = std::make_unique<BinaryExpression>('*', std::move(expr), std::move(unary()));
            continue;
        }if(math_token_with_current(TokenType::SLASH)) {
            expr = std::make_unique<BinaryExpression>('/', std::move(expr), std::move(unary()));
            continue;
        }
        break;
    }
    return expr;
}

std::unique_ptr<Expression> Parser::unary() {
    if(math_token_with_current(TokenType::PLUS)){
        return std::make_unique<UnaryExpression>('+', primary());
    }else if(math_token_with_current(TokenType::MINUS)){
        return std::make_unique<UnaryExpression>('-', primary());
    }
    return primary();
}

std::unique_ptr<Expression> Parser::parse_function() {

    std::string function_name = peek(-1).text;

    if(math_token_with_current(TokenType::LPAREN)){
        std::vector<std::unique_ptr<Expression>> function_args;
        bool last_comma = true;
        int size = 0;
        while(!math_token_with_current(TokenType::RPAREN)){

            if(!last_comma) throw std::runtime_error("Invalid function expression");

            function_args.push_back(std::move(expression()));
            size++;
            last_comma = math_token_with_current(TokenType::COMMA);
        }
        std::shared_ptr<Plugin> plugin = pm.get_plugin(function_name);
        if(plugin != nullptr){
            return std::make_unique<FunctionExpression>(plugin, std::move(function_args));
        }else{
            throw std::runtime_error("invalid name of function");
        }
    }
    else{
        throw std::runtime_error("Invalid bracket expression");
    }

}


std::unique_ptr<Expression> Parser::primary() {
    const Token cur = peek(0);
    if (math_token_with_current(TokenType::NUMBER)) {
        return std::make_unique<NumberExpression>(cur.convert_to_double());
    }else if(math_token_with_current(TokenType::FUNCTION)){

        return parse_function();

    }else if(math_token_with_current(TokenType::LPAREN)){
        std::unique_ptr<Expression> res = expression();
        if(math_token_with_current(TokenType::RPAREN)){
            return res;
        }else{
            throw std::runtime_error("Invalid bracket expression");
        }
    }
    throw std::runtime_error("Unexpected token in primary()");
}





