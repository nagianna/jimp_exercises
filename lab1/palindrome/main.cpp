#include <iostream>
#include <string>
#include "Palindrome.h"

int main(){
    int wybor_opcji;
    std::cout<<"Program sprawdza, czy dany wyraz jest palindromem."<<std::endl;
    std::cout<<"wybierz 1 lub 2."<<std::endl;
    std::cout<<"[1]-wyjscie,  [2]-sprawdz palindrom"<<std::endl;
    std::cin>>wybor_opcji;
    if(wybor_opcji==1){
        exit(0);
    }
    if(wybor_opcji==2){
        std::string str;
        std::cout<<"Podaj wyraz: "<<std::endl;
        std::cin>>str;
        std::cout<<"Czy to palindrom?"<<std::endl;
        if(is_palindrome(str)==true){
            std::cout<<"Ten wyraz jest palindromem.";
        }
        if(is_palindrome(str)==false){
            std::cout<<"Ten wyraz nie jest palindromem."<<std::endl;
        }
    }
    return 0;
}






