//
// Created by nagianna on 20.03.18.
//
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""s;

namespace nets{
    JsonValue::JsonValue(int calkowita){
        calkowita_=calkowita;
    }
    JsonValue::JsonValue(float zmiennoprzecinkowa){
        zmiennoprzecinkowa_=zmiennoprzecinkowa;
    }
    JsonValue::JsonValue(std::string lancuch){
        lancuch_=lancuch;
    }
    JsonValue::JsonValue(bool logiczna){
        logiczna_=logiczna;
    }


    JsonValue::~JsonValue(){

    }

    std::experimental::optional<JsonValue> ValueByName(const std::string &name) {

    }

    std::string ToString() {

    }


};

