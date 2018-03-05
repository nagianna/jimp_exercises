//
// Created by annanagi on 05.03.18.
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

std::string DecimalToBinary (int g){
    std::string binary="";
    do{
        if((g&1)==0){
            binary+="0";
        }
        else{
            binary+="1";
        }
        g>>=1;
    } while(g);

    std::string reverse(binary.begin(),binary.end());
    return binary;
}
/*
uint64_t DecimalToBinary (int g){
    uint64_t rem, i=1;
    uint64_t binary=0;
    while (g!=0)
    {
        rem=g%2;
        g/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
} */


uint64_t DoubleBasePalindromes(int max_value_exculsive) {

    if( max_value_exculsive<0){
        return 0;
    }

    int g;
    uint64_t suma = 0;
    for (g = 0; g < max_value_exculsive; g++) {
        std::ostringstream s1;
        s1 << g;
        std::string str = s1.str();
        if (is_palindrome(str) == true) {
            /*std::ostringstream s2;
            s2 << DecimalToBinary(g);
            std::string str = s2.str();*/
            str=DecimalToBinary(g);
            if (is_palindrome(str) == true) {
                suma += g;
            }
        }
    }
    return suma;

}

