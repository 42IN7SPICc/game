#include "Tile.hpp"

game::TileType game::Tile::TileType() const
{
    return static_cast<game::TileType>(Type);
}
