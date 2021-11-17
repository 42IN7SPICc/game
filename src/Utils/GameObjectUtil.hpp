#ifndef SPIC_GAME_GAMEOBJECTUTIL_HPP
#define SPIC_GAME_GAMEOBJECTUTIL_HPP

#include <memory>
#include "GameObject.hpp"

namespace game
{
    class GameObjectUtil
    {
        public:
            static void LinkComponent(const std::shared_ptr<spic::GameObject>& gameObject, const std::shared_ptr<spic::Component>& component);

            static void LinkChild(const std::shared_ptr<spic::GameObject>& parent, const std::shared_ptr<spic::GameObject>& child);
    };
}

#endif
