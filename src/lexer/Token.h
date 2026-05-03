#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H

#include "TokenTypeEnum.h"
#include <ostream>
#include <string>

class Token {
  public:
    std::string text;

    double convert_to_double() const;

    TokenTypeEnum type;

    Token(TokenTypeEnum type, std::string text);

    friend std::ostream &operator<<(std::ostream &os, const Token &token);
};

#endif // CALCULATOR_TOKEN_H
