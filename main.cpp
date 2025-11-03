#include <iostream>
#include "src/Lexer.h"
#include "src/Parser.h"
#include "src/tests.h"
#include "src/PluginManager.h"

void start_program(){

    PluginManager pm;
    pm.load_all_plugins("plugins");

    std::string input;
    std::cout<<"to exit, enter the q"<<std::endl;
    std::cout<<"to show the list of available functions, enter the f"<<std::endl;

    while(true){
        std::cout<< std::endl << "enter the expression: ";
        std::getline(std::cin, input);
        if(input == "q") break;
        if(input == "f") {
            std::cout<<std::endl<<"available functions:"<<std::endl;
            for(auto &i: pm.get_list_of_function_names() ){
                std::cout<<i<<std::endl;
            }
            continue;
        }
        Lexer lexer(input);
        Parser p(lexer.tokenize(), pm);
        try{
            auto exprs = p.parse();
            for (std::unique_ptr<Expression> &i: exprs) {
                double val = i->eval();
                std::cout<<i->get_string()<< " = " << val << std::endl;
            }
        }catch(const std::runtime_error& e){
            std::cout<<"ERROR: "<<e.what()<<std::endl;
        }
    }
}


int main() {
//    start_program();
    test();
}
