#include "Token.h"

Token::Token(TokenType type, std::string text) : type(type), text(std::move(text)){}