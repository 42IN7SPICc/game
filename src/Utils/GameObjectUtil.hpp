#ifndef SPIC_GAME_GAMEOBJECTUTIL_HPP
#define SPIC_GAME_GAMEOBJECTUTIL_HPP

#include <memory>
#include "GameObject.hpp"

namespace game {
    class GameObjectUtil
    {
        public:
            static void LinkComponent(std::shared_ptr<spic::GameObject> gameObject, std::shared_ptr<spic::Component> component);
    };
}


#endif
