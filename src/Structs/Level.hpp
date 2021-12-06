#ifndef SPIC_GAME_LEVEL_HPP
#define SPIC_GAME_LEVEL_HPP

#include <string>
#include <map>
#include "../Enums/TileType.hpp"
#include "TilesAmount.hpp"

namespace game
{
    /**
     * @brief A model for storing level data.
     */
    struct Level
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Title, Description, UnlockThreshold, AmountsGiven);
        }

        std::string Title;
        std::string Description;
        int UnlockThreshold;
        std::string File;
        TilesAmount AmountsGiven;
    };
}

#endif
