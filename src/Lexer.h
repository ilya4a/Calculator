#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H


#include <string>
#include <utility>
#include <vector>
#include <utility>
#include <array>
#include "TokenTypeEnum.h"
#include "Token.h"

class Lexer {
    constexpr static std::array<char, 7> OPERATOR_CHARS = {
            '+', '-', '*', '/', '(', ')', '^'
    };

    constexpr static std::array<TokenTypeEnum, 7> OPERATOR_TOKENS = {
            TokenTypeEnum::PLUS, TokenTypeEnum::MINUS, TokenTypeEnum::STAR,
            TokenTypeEnum::SLASH, TokenTypeEnum::LPAREN, TokenTypeEnum::RPAREN, TokenTypeEnum::CARET
    };

    static_assert(OPERATOR_CHARS.size() == OPERATOR_TOKENS.size(),
                  "OPERATOR_CHARS and OPERATOR_TOKENS must have the same size");

    const std::string input;
    const int input_length;
    std::vector<Token> tokens;
    int current_position{};

    void add_token(TokenTypeEnum type, std::string text);
    void add_token(TokenTypeEnum type);
    char peek(int relative_position);
    char next();

    void tokenize_number();
    bool is_operator(char cur);
    void tokenize_operator();

    bool check_number(std::string &num);
    bool is_letter();
    void tokenize_function();


public:
    explicit Lexer(const std::string& input);
    std::vector<Token> tokenize();



};

#endif //CALCULATOR_LEXER_H
