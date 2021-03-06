#ifndef JIMP2_SIMPLETEMPLATEENGINE_H
#define JIMP2_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>
#include <sstream>

namespace nets {
    class View {
    public:
        View (std::string template_str);
        std::string GetTemplateStr() const;
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        std::string template_str;
    };
}

#endif //JIMP2_SIMPLETEMPLATEENGINE_H
