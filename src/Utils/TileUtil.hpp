#ifndef SPIC_GAME_TILEUTIL_HPP
#define SPIC_GAME_TILEUTIL_HPP

#include <string>
#include "../Enums/TileType.hpp"

namespace game
{
    class TileUtil
    {
        public:
            static std::string GetSprite(const TileType& tileType);

            static TileType GetTileType(const std::string& sprite);
    };
}

#endif