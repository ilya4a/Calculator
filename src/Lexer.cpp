#include "Lexer.h"

Lexer::Lexer(const std::string& input)  : input(input), input_length(input.size()){}

void Lexer::add_token(TokenType type, std::string text){
    tokens.emplace_back(type, std::move(text));
}

void Lexer::add_token(TokenType type){
    tokens.emplace_back(type, "");
}

char Lexer::peek(int relative_position) {
    int pos = current_position + relative_position;
    if(pos >= input_length) return '\0';
    return input[pos];
}

char Lexer::next() {
    current_position++;
    return peek(0);
}

