#ifndef SPIC_GAME_TILE_HPP
#define SPIC_GAME_TILE_HPP

#include "../Enums/TileType.hpp"

namespace game
{
    struct Tile
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Type, X, Y);
        }

        TileType Type;
        int Y;
        int X;
    };
}


#endif //SPIC_GAME_TILE_HPP
