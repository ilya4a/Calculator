#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H


#include <string>
#include <utility>
#include <vector>
#include <utility>
#include <array>
#include "TokenType.h"
#include "Token.h"

class Lexer {
    constexpr static std::array<char, 6> OPERATOR_CHARS = {
            '+', '-', '*', '/', '(', ')'
    };

    constexpr static std::array<TokenType, 6> OPERATOR_TOKENS = {
            TokenType::PLUS, TokenType::MINUS, TokenType::STAR,
            TokenType::SLASH, TokenType::LPAREN, TokenType::RPAREN
    };

    static_assert(OPERATOR_CHARS.size() == OPERATOR_TOKENS.size(),
                  "OPERATOR_CHARS and OPERATOR_TOKENS must have the same size");

    const std::string input;
    const int input_length;
    std::vector<Token> tokens;
    int current_position{};

    void add_token(TokenType type, std::string text);
    void add_token(TokenType type);
    char peek(int relative_position);
    char next();

    void tokenize_number();
    bool is_operator(char cur);
    void tokenize_operator();

    bool check_number(std::string &num);


public:
    explicit Lexer(const std::string& input);
    std::vector<Token> tokenize();



};

#endif //CALCULATOR_LEXER_H
