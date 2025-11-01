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

std::vector<Token> Lexer::tokenize() {
    while(current_position < input_length){
        char current_char = peek(0);
        if(std::isdigit(static_cast<unsigned char>(current_char))) tokenize_number();
        else if(is_operator(current_char)){
            tokenize_operator();
        }else{
            next();
        }
    }
    add_token(TokenType::END_OF_FILE);
    return tokens;
}

bool Lexer::check_number(std::string &num) {

    if(num[0] == '.') return false;
    if(num[num.size() - 1] == '.') num.erase(num.size() - 1, 1);

    int num_of_points = 0;
    for(int i = 1; i < num.size(); i++){
        if(num[i] == '.') num_of_points++;
    }

    return num_of_points <= 1;
}

void Lexer::tokenize_number() {
    std::string str = "";

    char cur = peek(0);
    while(std::isdigit(static_cast<unsigned char>(cur)) || cur == '.'){ // throw exception 2.4. 3..4 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        str += cur;
        cur = next();
    }
    if(!check_number(str)){
        throw std::runtime_error("invalid format of number");
    }
    add_token(TokenType::NUMBER, std::move(str));
}

bool Lexer::is_operator(char cur) {
    for(char i: OPERATOR_CHARS){
        if(cur == i) return true;
    }
    return false;
}

void Lexer::tokenize_operator() {
    char cur = peek(0);
    int j = 0;
    for(char i: OPERATOR_CHARS){
        if(cur == i){
            add_token(OPERATOR_TOKENS[j]);
            next();
            return;
        }
        j++;
    }
}


