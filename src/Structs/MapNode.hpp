#ifndef SPIC_GAME_MAPNODE_HPP
#define SPIC_GAME_MAPNODE_HPP

#include <vector>
#include <memory>
#include "GameObject.hpp"
#include "../Enums/TileType.hpp"

namespace game
{
    /**
     * @brief A model for storing information about a node on the map.
     */
    class MapNode
    {
        public:
            std::vector<std::string> NeighbourStrings{};
            int X;
            int Y;
            game::TileType OriginalTileType;
            game::TileType TileType;
            std::shared_ptr<spic::GameObject> TileObject;
            std::shared_ptr<spic::GameObject> TowerObject;
            bool Visited;

            /**
             * @brief Compare two MapNodes by X and Y
             * @return Boolean if they are the same.
             */
            bool operator==(const MapNode& other) const;

            /**
             * @brief MapNode to valid x-y coords
             * @return Valid x-y coords
             */
            [[nodiscard]] std::string ToString() const;
    };
}

#endif
