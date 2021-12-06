#ifndef SPIC_GAME_TILESAMOUNT_HPP
#define SPIC_GAME_TILESAMOUNT_HPP

#include <string>
#include "../Enums/TileType.hpp"

namespace game
{
    /**
     * @brief A model for storing the maximum amount of tiles the player can use in a level.
     */
    struct TilesAmount
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Sand, Street, Grass);
        }

        int Sand;
        int Street;
        int Grass;
    };
}

#endif //SPIC_GAME_TILESAMOUNT_HPP
