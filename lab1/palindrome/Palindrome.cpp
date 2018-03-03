//
// Created by annanagi on 01.03.18.
//


#include "Palindrome.h"

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

