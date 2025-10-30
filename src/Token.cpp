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
    if(token.type == TokenType::END_OF_FILE) t = "END_OF_FILE";
    os << "Token(" << t << ", \"" << token.text << "\")";
    return os;
}

 double Token::convert_to_double() const {
    if(type != TokenType::NUMBER){
        printf("ERROR in Token::convert_to_double; token type is not a number");
        return 0;
    }
    return std::stod(text);
}
