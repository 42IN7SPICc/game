#ifndef SPIC_GAME_TILEUTIL_HPP
#define SPIC_GAME_TILEUTIL_HPP

#include <string>
#include "TileType.hpp"

namespace game
{
    class TileUtil
    {
        public:
            static std::string GetSprite(const game::TileType& tileType);
    };
}

#endif