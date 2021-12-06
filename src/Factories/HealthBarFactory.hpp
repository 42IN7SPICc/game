#ifndef SPIC_GAME_HEALTHBARFACTORY_HPP
#define SPIC_GAME_HEALTHBARFACTORY_HPP

#include "GameObject.hpp"

#include "../Scripts/Common/HealthBehaviour.hpp"

#include <memory>

namespace game
{
    /**
     * @brief Factory for health bars
     */
    class HealthBarFactory
    {
        public:
            static std::shared_ptr<spic::GameObject> CreateHealthBar(std::shared_ptr<spic::GameObject> target);
    };
}

#endif //SPIC_GAME_HEALTHBARFACTORY_HPP
