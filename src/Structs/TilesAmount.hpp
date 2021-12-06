#ifndef SPIC_GAME_TILESAMOUNT_HPP
#define SPIC_GAME_TILESAMOUNT_HPP

#include <string>
#include "../Enums/TileType.hpp"

namespace game
{
    /**
     * @brief A model for storing level data.
     */
    struct TilesAmount
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Grass, Sand, Street);
        }

        int Grass;
        int Sand;
        int Street;
    };
}

#endif //SPIC_GAME_TILESAMOUNT_HPP
