//
// Created by nagianna on 20.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <regex>
#include <sstream>

namespace nets {

    class JsonValue {
    public:
        JsonValue();

        JsonValue(int calkowita);

        JsonValue(double zmiennoprzecinkowa);

        JsonValue(std::string lancuch);

        JsonValue(bool logiczna);

        JsonValue(std::vector<JsonValue> tablica);

        JsonValue(std::map<std::string, JsonValue> mapa);

        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;


    private:
        std::experimental::optional<int> calkowita_;
        std::experimental::optional<double> zmiennoprzecinkowa_;
        std::experimental::optional<std::string> lancuch_;
        std::experimental::optional<bool> logiczna_;
        std::experimental::optional<std::vector<JsonValue>> tablica_;
        std::experimental::optional<std::map<std::string, JsonValue>> mapa_;
    };


}
    #endif //JIMP_EXERCISES_SIMPLEJSON_H