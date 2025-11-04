#ifndef CALCULATOR_TOKENTYPEENUM_H
#define CALCULATOR_TOKENTYPEENUM_H

enum class TokenTypeEnum{
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

#endif //CALCULATOR_TOKENTYPEENUM_H
