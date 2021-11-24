#ifndef SPIC_GAME_LEVELWITHTILES_HPP
#define SPIC_GAME_LEVELWITHTILES_HPP

#include "Level.hpp"
#include "Tile.hpp"

#include <vector>

namespace game
{
    struct LevelWithTiles : public Level
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(Title, Description, UnlockThreshold, Tiles);
        }

        std::vector<Tile> Tiles;
    };
}

#endif //SPIC_GAME_LEVELWITHTILES_HPP
