//
// Created by Ania on 2018-04-05.
//

#include "TextPool.h"

using namespace pool;

TextPool::TextPool(std::initializer_list<std::string> kawalek){
    for (const auto &iterator : kawalek) {
        this->napisy.insert(iterator);
    }
}

std::experimental::string_view TextPool::Intern(const std::string &str) {
    for(const auto &iterator : napisy) {
        if(iterator==str) {
            return iterator;
        }
    }
    napisy.insert(str);
    return str;
}

size_t TextPool::StoredStringCount() const {
    size_t rozmiar=napisy.size();
    return rozmiar;
}

TextPool::TextPool(TextPool &&other) noexcept {
    std::swap(napisy, other.napisy);
}

TextPool & TextPool::operator=(TextPool &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    else {
        napisy=std::move(other.napisy);
        return *this;
    }
}