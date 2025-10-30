#include <iostream>
#include "src/Lexer.h"

int main() {
    Lexer a("1  + 2 - 9487 + 3.44*4  - (45) ");
    std::vector<Token> v = a.tokenize();
    for(auto &i: v){
        std::cout << i << std::endl;
    }
    return 0;
}
