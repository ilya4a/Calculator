#include <iostream>
#include "src/Lexer.h"
#include "src/Parser.h"
#include "src/simple_calculator_tests.h"
#include "src/PluginManager.h"

void start(){
//    Lexer a(" pow(2 + 3*cos(0), 3) - 25*sin(3.14/2 + 1 *0) ");
    Lexer a(" ln( 2) * pow(2, 1.5 *2) + 0.12");
    std::vector<Token> v = a.tokenize();
    for(auto &i: v){
        std::cout << i << std::endl;
    }

    Parser p(v);

    try{
        auto exprs = p.parse();
        for (std::unique_ptr<Expression> &i: exprs) {
            printf("\n%s = %f", i->get_string().c_str(), i->eval());
        }
    }catch(const std::runtime_error& e){
        std::cerr<<e.what()<<std::endl;
    }
}


int main() {
//    simple_calc_tests();
    start();
//    PluginManager pm;
//    pm.load_all_plugins("plugins");
//    std::shared_ptr<Plugin> plugin = pm.get_plugin("cos");
//    double args[1] = {3.14};
//    double res;
//    plugin->eval(args, 1, &res);
//    std::cout<<res<<std::endl;
}
