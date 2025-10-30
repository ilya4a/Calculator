#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H


#include <string>
#include <utility>
#include <vector>
#include <utility>
#include "TokenType.h"
#include "Token.h"

class Lexer {
    const std::string OPERATOR_CHARS = "+-*/()";
    const std::string input;
    const int input_length;
    std::vector<Token> tokens;
    int current_position{};

    void add_token(TokenType type, std::string text);
    void add_token(TokenType type);
    char peek(int relative_position);
    char next();
public:
    explicit Lexer(const std::string& input);
    std::vector<Token> tokenize();


};

#endif //CALCULATOR_LEXER_H
