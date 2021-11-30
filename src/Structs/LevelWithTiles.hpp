#ifndef SPIC_GAME_LEVELWITHTILES_HPP
#define SPIC_GAME_LEVELWITHTILES_HPP

#include "Level.hpp"
#include "Tile.hpp"

#include <vector>

namespace game
{
    /**
     * @brief A model for storing level data including tiles.
     */
    struct LevelWithTiles
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Title, Description, UnlockThreshold, Tiles);
        }

        std::string Title;
        std::string Description;
        int UnlockThreshold;
        std::vector<Tile> Tiles;
        std::string File;
    };
}

#endif //SPIC_GAME_LEVELWITHTILES_HPP
