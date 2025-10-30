#include "Token.h"

Token::Token(TokenType type, std::string text) : type(type), text(std::move(text)){}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    std::string t = "not defined";
    if(token.type == TokenType::RPAREN) t = ">)<";
    if(token.type == TokenType::LPAREN) t = ">(<";
    if(token.type == TokenType::SLASH) t = "/";
    if(token.type == TokenType::STAR) t = "*";
    if(token.type == TokenType::PLUS) t = "+";
    if(token.type == TokenType::MINUS) t = "-";
    if(token.type == TokenType::NUMBER) t = "NUMBER";
    os << "Token(" << t << ", \"" << token.text << "\")";
    return os;
}
