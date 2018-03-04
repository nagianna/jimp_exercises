//
// Created by annanagi on 02.03.18.
//

#include <iostream>
#include "DoubleBasePalindromes.h"


int main(){
    int g;
    int suma=0;
    for(g=0; g<1000000; g++){
        std::ostringstream s1;
        s1<<g;
        std::string str=s1.str();
        if(is_palindrome(str)==true){
            std::ostringstream s2;
            s2<<DoubleBasePalindrome(g);
            std::string str=s2.str();
            if(is_palindrome(str)==true){
                std::cout<<"Liczba w obu wariantach jest palindromem.";
                std::cout<<str;
                suma+=g;
            }
        }
    }
    std::cout<<"Suma liczb, ktore sa podwojnymi palindromami wynosi: "<<suma;

    return 0;
}

