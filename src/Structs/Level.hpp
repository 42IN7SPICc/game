#ifndef SPIC_GAME_LEVEL_HPP
#define SPIC_GAME_LEVEL_HPP

#include <string>

namespace game {
    struct Level
    {
        std::string Title;
        std::string Description;
        std::string File;
        int UnlockThreshold;
    };
}

#endif
