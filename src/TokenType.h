#ifndef CALCULATOR_TOKENTYPE_H
#define CALCULATOR_TOKENTYPE_H

enum class TokenType{
    NUMBER,
    HEX_NUMBER,

    PLUS,
    MINUS,
    STAR,
    SLASH,

    LPAREN, // (
    RPAREN, // )

    FUNCTION,
    COMMA,
    END_OF_FILE
};

#endif //CALCULATOR_TOKENTYPE_H
