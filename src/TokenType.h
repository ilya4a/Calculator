#ifndef CALCULATOR_TOKENTYPE_H
#define CALCULATOR_TOKENTYPE_H

enum class TokenType{
    NUMBER,

    PLUS,
    MINUS,
    STAR,
    SLASH,
    CARET,

    LPAREN, // (
    RPAREN, // )

    FUNCTION,
    COMMA,
    END_OF_FILE
};

#endif //CALCULATOR_TOKENTYPE_H
