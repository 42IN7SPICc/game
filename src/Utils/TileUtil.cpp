#include "TileUtil.hpp"

using namespace game;

std::string TileUtil::GetSprite(const game::TileType& tileType)
{
    switch (tileType) {
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
        case End:
            return "resources/sprites/tiles/start-end.png";
        case Bushes:
        default:
            return "resources/sprites/tiles/bushes.png";
    }
}
