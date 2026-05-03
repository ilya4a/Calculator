//
// Created by ilya on 11/4/25.
//
#include "tests.h"

static bool approxEqual(double a, double b) {
    return std::fabs(a - b) <= 1e-5;
}

void test() {
    auto evalExpr = [](const std::string &s) -> double {
        Lexer lexer(s);
        std::vector<Token> tokens = lexer.tokenize();
        PluginManager pm;
        pm.load_all_plugins("plugins");
        Parser parser(tokens, pm);
        auto exprs = parser.parse();
        assert(!exprs.empty());
        double res = exprs.front()->eval();
//        std::cout<<res<<"  result"<<std::endl;
        return res;
    };

    assert(approxEqual(evalExpr("(2 + 3) * 4"), 20.0));

    std::cout << "1--------------" << std::endl;
    assert(approxEqual(evalExpr("(-2) ^ 2"), 4.0));

    std::cout << "2--------------" << std::endl;
    assert(approxEqual(evalExpr("-2 ^ (-3) ^ 2"), -512.0));

    std::cout << "3--------------" << std::endl;
    assert(approxEqual(evalExpr("pow(2, 3)"), 8.0));

    std::cout << "4--------------" << std::endl;
    assert(approxEqual(evalExpr("pow(2, pow(1 + 1, 2))"), 16.0));

    std::cout << "5--------------" << std::endl;
    assert(approxEqual(evalExpr("cos(0*3 - 0 + sin(0) )"), 1.0));

    std::cout << "6--------------" << std::endl;
    assert(approxEqual(evalExpr("sin(3.141592653589793 / 2)"), 1.0));

    std::cout << "7--------------" << std::endl;
    assert(approxEqual(evalExpr("ln(2.718281828459045)"), 1.0));

    std::cout << "8--------------" << std::endl;
    assert(approxEqual(evalExpr("pow(2 + 3 * cos(0), 2) - sin(1*0 - 1 + 1)"), 25.0));

    std::cout << "9--------------" << std::endl;
    assert(approxEqual(evalExpr(" pow(2 + 3*cos(0), 3) - 25*sin(3.14/2 +1 *0 )"), 100.0));

    std::cout << "10--------------" << std::endl;
    assert(approxEqual(evalExpr(" -1^1^(-1)^-1^2^2 "), -1.0));

    std::cout << "11--------------" << std::endl;
    assert(approxEqual(evalExpr("(-2) ^ (1 + 3) * pow(2, -3) + sin(0)"), 2.0));

    std::cout << "12--------------" << std::endl;
    assert(approxEqual(evalExpr("pow(2, pow(1 + 1, pow(1 + 1^--2, 1)))"), 16.0));

    std::cout << "13--------------" << std::endl;
    assert(approxEqual(evalExpr("2 ^ - (1 + 2^---1 + 0.5 + 1)"), 0.125));

    std::cout << "14--------------" << std::endl;
    assert(approxEqual(evalExpr("pow(pow(2, 3) + pow(1 + 1, 3), 2) - cos(0)"), 255.0));

    std::cout << "15--------------" << std::endl;
    assert(approxEqual(evalExpr("pow( (sin(3.141592653589793 / 6) + cos(3.141592653589793 / 3)), 2)"), 1.0));

    std::cout << "16--------------" << std::endl;
    assert(approxEqual(evalExpr("(deg(180^--1) ^ 2) ^0.5"), 3.141592653589793));

    std::cout << "All tests passed." << std::endl;
}
