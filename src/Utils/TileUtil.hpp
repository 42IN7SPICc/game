#ifndef SPIC_GAME_TILEUTIL_HPP
#define SPIC_GAME_TILEUTIL_HPP

#include <string>
#include "../Enums/TileType.hpp"

namespace game
{
    class TileUtil
    {
        public:
            static std::string GetSprite(const game::TileType& tileType);

            static game::TileType GetTileType(const std::string& sprite);
    };
}

#endif