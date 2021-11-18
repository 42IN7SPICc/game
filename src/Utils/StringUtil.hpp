#ifndef SPIC_GAME_STRINGHELPER_H
#define SPIC_GAME_STRINGHELPER_H

#include <string>

namespace game
{
    class StringUtil
    {
        public:
            static bool EndsWith(const std::string& haystack, const std::string& needle);

            static bool StartsWith(const std::string& haystack, const std::string& needle);
    };
}

#endif
