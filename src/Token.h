
#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H


#include <string>
#include <utility>
#include "TokenType.h"

class Token {
    TokenType type;
    std::string text;

public:
    Token(TokenType type, std::string text);
};


#endif //CALCULATOR_TOKEN_H
