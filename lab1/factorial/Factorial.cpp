//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {

    if (value == 0 || value == 1) {
        return 1;
    }

    if (1 < value < 13) {
        return value * factorial(value - 1);
    }
    else {
    return 0;
    }
}
