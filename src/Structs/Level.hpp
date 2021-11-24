#ifndef SPIC_GAME_LEVEL_HPP
#define SPIC_GAME_LEVEL_HPP

#include <string>
#include "../Utils/TileType.hpp"

namespace game
{
    struct Level
    {
        std::string Title;
        std::string Description;
        std::string File;
        int UnlockThreshold;
        std::map<game::TileType, size_t> AmountOfTiles;
    };
}

#endif
