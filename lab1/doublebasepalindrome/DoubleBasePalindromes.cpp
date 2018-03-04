//
// Created by annanagi on 02.03.18.
//

#include "DoubleBasePalindromes.h"

bool is_palindrome(std::string str){
    const int size=str.size()/2;

    int j=0;
    if(str.size()%2==0){
        j=size*2-1;
    }
    if(str.size()%2==1){
        j=size*2;
    }

    for(int i=0; i < size; i++){
        if(str[i]!=str[j]) {
            return false;
        }
        j--;
    }
    return true;
}

uint64_t DoubleBasePalindrome(int max_value_exculsive){
    uint64_t rem, i=1;
    uint64_t binary=0;
    while (max_value_exculsive!=0)
    {
        rem=max_value_exculsive%2;
        max_value_exculsive/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

