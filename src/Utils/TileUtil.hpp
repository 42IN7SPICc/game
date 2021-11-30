#ifndef SPIC_GAME_TILEUTIL_HPP
#define SPIC_GAME_TILEUTIL_HPP

#include <string>
#include "../Enums/TileType.hpp"

namespace game
{
    /**
     * @brief A util to handle tiles.
     */
    class TileUtil
    {
        public:
            /**
             * @brief Get the sprite corresponding to a given tile type.
             * @param tileType The type of tile.
             * @return A path to the sprite.
             */
            static std::string GetSprite(const game::TileType& tileType);

            /**
             * @brief Get the tile type corresponding to a given sprite.
             * @param sprite The path to the sprite.
             * @return The type of the tile.
             */
            static game::TileType GetTileType(const std::string& sprite);
    };
}

#endif