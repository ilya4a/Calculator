#include <iostream>
#include "src/Lexer.h"
#include "src/Parser.h"

int main() {
    Lexer a(" 11.1 + (3-2)*(555 - 554)/(88 - 87) - (9/(9))");
    std::vector<Token> v = a.tokenize();
//    for(auto &i: v){
//        std::cout << i << std::endl;
//    }

    Parser p(v);
    auto exprs = p.parse();
    for (std::unique_ptr<Expression> &i: exprs) {
        printf("\n%s = %f", i->get_string().c_str(), i->eval());
    }
}
