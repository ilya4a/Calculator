//
// Created by ilya on 10/30/25.
//

#include <iostream>
#include "Parser.h"
#include "expr/NumberExpression.h"
#include "expr/BinaryExpression.h"


Parser::Parser(std::vector<Token> toks)
        : END_OF_FILE(Token(TokenType::END_OF_FILE, "")),
          tokens(std::move(toks)),
          size(static_cast<int>(tokens.size()))
{
    current_position = 0;
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
    printf("\n-----");
    std::cout<<tokens[0]<<std::endl;
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
    return primary();
}

std::unique_ptr<Expression> Parser::primary() {
    const Token cur = peek(0);
    if (math_token_with_current(TokenType::NUMBER)) {
        return std::make_unique<NumberExpression>(cur.convert_to_double());
    }
    throw std::runtime_error("Unexpected token in primary()");
}




