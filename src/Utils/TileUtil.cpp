#include "TileUtil.hpp"
#include <stdexcept>

using namespace game;

std::string TileUtil::GetSprite(const game::TileType& tileType)
{
    switch (tileType)
    {
        case Bridge:
            return "resources/sprites/tiles/bridge.png";
        case Grass:
            return "resources/sprites/tiles/grass.png";
        case Rocks:
            return "resources/sprites/tiles/rocks.png";
        case Sand:
            return "resources/sprites/tiles/sand.png";
        case Street:
            return "resources/sprites/tiles/street.png";
        case Water:
            return "resources/sprites/tiles/water.png";
        case Start:
            return "resources/sprites/tiles/start.png";
        case End:
            return "resources/sprites/tiles/end.png";
        case Bushes:
        default:
            return "resources/sprites/tiles/bushes.png";
    }
}

game::TileType TileUtil::GetTileType(const std::string& sprite)
{
    if(sprite == "resources/sprites/tiles/bridge.png") return TileType::Bridge;
    else if(sprite == "resources/sprites/tiles/grass.png") return TileType::Grass;
    else if(sprite == "resources/sprites/tiles/rocks.png") return TileType::Rocks;
    else if(sprite == "resources/sprites/tiles/sand.png") return TileType::Sand;
    else if(sprite == "resources/sprites/tiles/street.png") return TileType::Street;
    else if(sprite == "resources/sprites/tiles/water.png") return TileType::Water;
    else if(sprite == "resources/sprites/tiles/start.png") return TileType::Start;
    else if(sprite == "resources/sprites/tiles/end.png") return TileType::End;
    else if(sprite == "resources/sprites/tiles/bushes.png") return TileType::Bushes;

    throw std::runtime_error("Couldn't find a TileType for sprite: " + sprite);
}
