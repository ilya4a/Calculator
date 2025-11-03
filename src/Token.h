
#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H

#include <ostream>
#include <string>
#include <utility>
#include "TokenType.h"

class Token {

public:
    std::string text;
    double convert_to_double() const;
    TokenType type;
    Token(TokenType type, std::string text);
    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};


#endif //CALCULATOR_TOKEN_H
