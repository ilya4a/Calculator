//
// Created by ilya on 11/1/25.
//

#ifndef CALCULATOR_SIMPLE_CALCULATOR_TESTS_H
#define CALCULATOR_SIMPLE_CALCULATOR_TESTS_H


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <iomanip>

#include "Lexer.h"
#include "Parser.h"

bool approx_eq(double a, double b, double eps = 1e-9);
int simple_calc_tests();


#endif //CALCULATOR_SIMPLE_CALCULATOR_TESTS_H
