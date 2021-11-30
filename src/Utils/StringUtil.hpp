#ifndef SPIC_GAME_STRINGHELPER_H
#define SPIC_GAME_STRINGHELPER_H

#include <string>
#include <vector>

namespace game
{
    class StringUtil
    {
        public:
            static bool EndsWith(const std::string& haystack, const std::string& needle);

            static bool StartsWith(const std::string& haystack, const std::string& needle);

            static std::vector<std::string> Split(const std::string& string, const std::string& delimiter);
    };
}

#endif
