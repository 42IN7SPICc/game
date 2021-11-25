#ifndef SPIC_GAME_ANIMATORUTIL_HPP
#define SPIC_GAME_ANIMATORUTIL_HPP

#include "Sprite.hpp"

#include <memory>
#include <string>
#include <vector>

namespace game
{
    namespace types
    {
        using sprite_vector = std::vector<std::shared_ptr<spic::Sprite>>;
    }

    class AnimatorUtil
    {
        public:
            static types::sprite_vector CreateSpriteVector(int max, const std::string& prefix, int sortingLayer = 0, const std::string& extension = ".png", bool flipX = false, bool flipY = false, int orderLayer = 0);
    };
}

#endif //SPIC_GAME_ANIMATORUTIL_HPP
