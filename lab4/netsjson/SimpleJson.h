//
// Created by nagianna on 20.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>

namespace nets{

    class JsonValue{
        public:
            JsonValue();
            JsonValue(int calkowita);
            JsonValue(float zmiennoprzecinkowa);
            JsonValue(std::string lancuch);
            JsonValue(bool logiczna);
            ~JsonValue();


            std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
            std::string ToString() const;


        private:
            int calkowita_;
            float zmiennoprzecinkowa_;
            std::string lancuch_;
            bool logiczna_;

    };

}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
