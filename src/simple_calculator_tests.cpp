//
// Created by ilya on 11/1/25.
//

#include "simple_calculator_tests.h"

bool approx_eq(double a, double b, double eps) {
    return std::fabs(a - b) <= eps;
}

int simple_calc_tests() {
    std::cout << std::fixed << std::setprecision(12);

    // Пара: выражение -> ожидаемое значение
    std::vector<std::pair<std::string, double>> tests = {
            {"1+2", 3.0},
            {" 11.1 + (3-2)*(555 - 554)/(88 - 87) - (9/(9))", 11.1},
            {"0.5 + 1.5", 2.0},
            {"3.5*2", 7.0},
            {"2*(3+4)", 14.0},
            {"2*3+4", 10.0},
            {"7/2", 3.5},
            {"(1+(2*(3+(4/2))))", 11.0},
            {"  4 +    5\t-  6", 3.0},
            {"((2.25+0.75)/3)*6", 6.0}
    };

    size_t passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        const auto &expr = tests[i].first;
        double expected = tests[i].second;

        Lexer lexer(expr);
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        auto exprs = parser.parse();

        assert(!exprs.empty() && "parse() вернул пустой список выражений");

        double got = exprs.front()->eval();

        bool ok = approx_eq(got, expected);
        if (!ok) {
            std::cerr << "TEST FAILED [" << (i+1) << "]: \"" << expr << "\"\n";
            std::cerr << "  expected = " << expected << "\n";
            std::cerr << "  got      = " << got << "\n";
        }
        assert(ok && "Результат вычисления не совпадает с ожидаемым");

        std::cout << "[PASS] " << std::setw(2) << (i+1) << ") "
                  << std::left << std::setw(40) << ("\"" + expr + "\"")
                  << " = " << std::right << got << "\n";
        ++passed;
    }

    std::cout << "\nAll tests passed: " << passed << " / " << tests.size() << "\n";
    return 0;
}
