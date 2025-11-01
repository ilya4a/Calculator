cmake_minimum_required(VERSION 3.31)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Calculator main.cpp
        src/Lexer.cpp
        src/Lexer.h
        src/TokenType.h
        src/Token.cpp
        src/Token.h
        src/Parser.cpp
        src/Parser.h
        src/expr/Expression.h
        src/expr/NumberExpression.cpp
        src/expr/NumberExpression.h
        src/expr/UnaryExpression.cpp
        src/expr/UnaryExpression.h
        src/expr/BinaryExpression.cpp
        src/expr/BinaryExpression.h
        src/simple_calculator_tests.cpp
        src/simple_calculator_tests.h)
