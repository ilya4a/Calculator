#include "Token.h"

Token::Token(TokenTypeEnum type, std::string text) : type(type), text(std::move(text)) {}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    std::string t = "not defined";
    if (token.type == TokenTypeEnum::RPAREN) t = ">)<";
    if (token.type == TokenTypeEnum::LPAREN) t = ">(<";
    if (token.type == TokenTypeEnum::SLASH) t = "/";
    if (token.type == TokenTypeEnum::STAR) t = "*";
    if (token.type == TokenTypeEnum::PLUS) t = "+";
    if (token.type == TokenTypeEnum::MINUS) t = "-";
    if (token.type == TokenTypeEnum::NUMBER) t = "NUMBER";
    if (token.type == TokenTypeEnum::FUNCTION) t = "FUNCTION";
    if (token.type == TokenTypeEnum::COMMA) t = "COMMA";
    if (token.type == TokenTypeEnum::END_OF_FILE) t = "END_OF_FILE";
    os << "Token(" << t << ", \"" << token.text << "\")";
    return os;
}

double Token::convert_to_double() const {
    if (type != TokenTypeEnum::NUMBER) {
        printf("ERROR in Token::convert_to_double; token type is not a number");
        return 0;
    }
    return std::stod(text);
}
