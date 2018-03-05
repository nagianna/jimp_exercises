//
// Created by annanagi on 05.03.18.
//



#include <iostream>
#include "DoubleBasePalindromes.h"


int main() {
    int max_value_exculsive;
    std::cout << "Podaj liczbe mniejsza lub rowna 1000000: " << std::endl;
    std::cin >> max_value_exculsive;
    if (max_value_exculsive > 1000000) {
        std::cout << "Podaj liczbe mniejsza od 1000000: " << std::endl;
        std::cin >> max_value_exculsive;
    }
    else {
    int suma = DoubleBasePalindromes(max_value_exculsive);
    std::cout << "Suma liczb, ktore sa podwojnymi palindromami wynosi: " << suma;
    }

    return 0;
}