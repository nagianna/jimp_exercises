//
// Created by annanagi on 12.03.18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::find;
using std::vector;
using std::string;



int main() {

    std::vector<char> cryptogram = {24, 38, 45, 18, 1};


    std::vector<int> liczbowy_cryptogram;

    for (int v: cryptogram) {

        liczbowy_cryptogram.push_back(v);
    }


    std::vector<int> liczby_odszyfrowane;


    vector<string> wszystkie_kody;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                string nowy_kod = "";
                nowy_kod += i;
                nowy_kod += j;
                nowy_kod += k;
                wszystkie_kody.push_back(nowy_kod);
            }
        }
    }




    std::string dzialajace="";
    std::string rozszyfrowane="";

    for (int v: liczbowy_cryptogram) {
        for (string v1: wszystkie_kody) {

            auto j = find(liczbowy_cryptogram.begin(), liczbowy_cryptogram.end(), v);
            long i = distance(liczbowy_cryptogram.begin(), j);
            if (i % 3 == 0) {
                int a=v-v1[0];
                liczby_odszyfrowane.push_back(a);
                if (a < 0) {
                    liczby_odszyfrowane.erase(liczby_odszyfrowane.end() - 1);
                    a=-v+v1[0];
                    liczby_odszyfrowane.push_back(a);
                }
                if (a < 97 || a > 123) {
                    liczby_odszyfrowane.erase(liczby_odszyfrowane.begin(), liczby_odszyfrowane.end()-1);
                    continue;
                }
            }

            if (i % 3 == 1) {
                int b=v-v1[0];
                liczby_odszyfrowane.push_back(b);
                if (b < 0) {
                    liczby_odszyfrowane.erase(liczby_odszyfrowane.end() - 1);
                    b=-v+v1[1];
                    liczby_odszyfrowane.push_back(b);
                }
                if (b< 97 || b> 123) {
                    liczby_odszyfrowane.erase(liczby_odszyfrowane.begin(), liczby_odszyfrowane.end()-1);

                    continue;
                }
            }
            if (i % 3 == 2) {
                int c=v-v1[2];
                liczby_odszyfrowane.push_back(c);
                if (c < 0) {
                    liczby_odszyfrowane.erase(liczby_odszyfrowane.end() - 1);
                    c=-v+v1[2];
                    liczby_odszyfrowane.push_back(c);
                }
                if (c < 97 || c > 123) {
                    liczby_odszyfrowane.erase(liczby_odszyfrowane.begin(), liczby_odszyfrowane.end()-1);

                    continue;
                }

            }


               for( int z: liczby_odszyfrowane) {
                 rozszyfrowane+=z + ", ";
            }

            dzialajace+= v1 +", ";

        }
    }


std::cout << rozszyfrowane;







    return 0;
}