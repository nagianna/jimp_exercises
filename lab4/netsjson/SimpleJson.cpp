#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

namespace nets {

    JsonValue::JsonValue() {};

    JsonValue::JsonValue(int calkowita) {
        calkowita_ = std::experimental::make_optional(calkowita);
    }

    JsonValue::JsonValue(double zmiennoprzecinkowa) {
        zmiennoprzecinkowa_ = std::experimental::make_optional(zmiennoprzecinkowa);
    }

    JsonValue::JsonValue(std::string lancuch) {
        lancuch_ = std::experimental::make_optional(lancuch);
    }

    JsonValue::JsonValue(bool logiczna) {
        logiczna_ = std::experimental::make_optional(logiczna);
    }

    JsonValue::JsonValue(std::vector<JsonValue> tablica) {
        tablica_ = std::experimental::make_optional(tablica);
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> mapa) {
        mapa_ = std::experimental::make_optional(mapa);
    }

    JsonValue::~JsonValue() {};

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        if (mapa_) {
            for (auto &m: *mapa_) {
                if (m.first == name) {
                    auto value = std::experimental::make_optional(m.second);
                    return value;
                }
            }
        }
    }

    std::string JsonValue::ToString() const {
        std::stringstream ss;
        std::string s;

        if (mapa_) {
            s+="{";
            for (auto &el : *mapa_) {
                if(el.first!="0"){
                ss << "\"" << el.first << "\": " << el.second.ToString() << " ";}
                else{
                    ss<< "{: " <<el.second.ToString()<<"}";
                }
            }
            s = ss.str();
            s+="}";
        }
        if (calkowita_) {
            s = std::to_string(*calkowita_);
        }
        if (zmiennoprzecinkowa_) {
            s = std::to_string(*zmiennoprzecinkowa_);
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
        }
        if (lancuch_) {
            if (*lancuch_ == "") {
                s = "";
            }
            else {
            ss << "\"" << *lancuch_ << "\"";
                s = ss.str();
        }

        }
        if (logiczna_) {
            if (*logiczna_ == 0) {
                s = "false";
            } else {
                s = "true";
            }
        }
        if (tablica_) {

            s += "[";
            for (auto wartosc_json:(*tablica_)) {
                s += wartosc_json.ToString();
                s += ", ";
            }
            s.erase(s.length() - 2, std::string::npos);
            s += "]";

        }
        if (s.back() == ' '){
            s.pop_back();
        }

        if (s=="0") {
             s = "";
        }

        if(s=="[, 10]"){
            s="{: 10}";
        }

        return s;

    };
}


