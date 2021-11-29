#ifndef SPIC_GAME_MAPNODE_HPP
#define SPIC_GAME_MAPNODE_HPP

#include <vector>
#include <memory>
#include "GameObject.hpp"
#include "../Enums/TileType.hpp"

namespace game
{
    struct MapNode
    {
        std::vector<std::string> NeighbourStrings {};
        int X;
        int Y;
        TileType OriginalTileType;
        game::TileType TileType;
        std::shared_ptr<spic::GameObject> TileObject;
        bool Visited;
    };
}

#endif
