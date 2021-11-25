#include "AnimatorUtil.hpp"

using namespace game;

std::vector<std::shared_ptr<spic::Sprite>> AnimatorUtil::CreateSpriteVector(int max, const std::string& prefix, int sortingLayer, const std::string& extension, bool flipX, bool flipY, int orderLayer)
{
    types::sprite_vector sprites{};

    for (int i = 1; i <= max; ++i)
    {
        sprites.push_back(std::make_shared<spic::Sprite>(prefix + std::to_string(i) + extension, flipX, flipY, sortingLayer, orderLayer));
    }

    return sprites;
}
