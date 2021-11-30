#ifndef SPIC_GAME_TILE_HPP
#define SPIC_GAME_TILE_HPP

#include "../Enums/TileType.hpp"

namespace game
{
    /**
     * @brief A model for storing data about a tile.
     */
    struct Tile
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Type, X, Y);
        }

        int Type;
        int X;
        int Y;

        /**
         * @brief The type of the tile.
         * @return The type of the tile.
         */
        [[nodiscard]] game::TileType TileType() const;
    };
}


#endif //SPIC_GAME_TILE_HPP
