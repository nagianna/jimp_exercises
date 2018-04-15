
//
// Created by Ania on 2018-04-05.
//
#ifndef JIMP_EXERCISES_TextPool_H
#define JIMP_EXERCISES_TextPool_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

#include <iostream>

namespace pool{
    class TextPool{

        std::set<std::string> napisy;

    public:
        TextPool()=default;  //konstruktor domyslny
        TextPool(std::initializer_list<std::string> kawalek); //konstruktor z lista inicjalizacyjna
        ~TextPool()=default;  //destruktor domyslny
        TextPool(TextPool &&other) noexcept ;  //konstruktor przenoszacy
        TextPool(const TextPool &other) = delete;  // konstruktor kopiujacy - usuwamy
        TextPool & operator=(const TextPool &other) = delete;  //operator przypisania - usuwamy
        TextPool & operator=(TextPool &&other) noexcept;  //operator przenoszacy

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    };
}
#endif //JIMP_EXERCISES_TextPool_H




