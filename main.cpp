#include <iostream>
#include "src/Lexer.h"
#include "src/Parser.h"
#include "src/simple_calculator_tests.h"
#include "src/PluginManager.h"

void start(){
    Lexer a(" 1 1");
    std::vector<Token> v = a.tokenize();
    for(auto &i: v){
        std::cout << i << std::endl;
    }

    Parser p(v);
    auto exprs = p.parse();
    for (std::unique_ptr<Expression> &i: exprs) {
        printf("\n%s = %f", i->get_string().c_str(), i->eval());
    }
}


int main() {
//    simple_calc_tests();
//    start();
    PluginManager pm;
    pm.load_all_plugins("plugins");

}
