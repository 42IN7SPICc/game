#ifndef SPIC_GAME_BACKGROUNDPREFABFACTORY_HPP
#define SPIC_GAME_BACKGROUNDPREFABFACTORY_HPP

#include "../Enums/BackgroundName.hpp"

#include "GameObject.hpp"

#include <memory>

namespace game
{
    class BackgroundPrefabFactory
    {
        public:
            static std::shared_ptr<spic::GameObject> CreateBackground(BackgroundName backgroundName);
    };
}

#endif //SPIC_GAME_BACKGROUNDPREFABFACTORY_HPP
