#ifndef SPIC_GAME_BACKGROUNDPREFABFACTORY_HPP
#define SPIC_GAME_BACKGROUNDPREFABFACTORY_HPP

#include "../Enums/BackgroundName.hpp"

#include "GameObject.hpp"

#include <memory>

namespace game
{
    /**
     * @brief Factory for backgrounds.
     */
    class BackgroundPrefabFactory
    {
        public:
            /**
             * @brief Create a GameObject with a Sprite that contains a given background.
             * @param backgroundName The name of the background.
             * @return The game object with the background.
             */
            static std::shared_ptr<spic::GameObject> CreateBackground(BackgroundName backgroundName);
    };
}

#endif //SPIC_GAME_BACKGROUNDPREFABFACTORY_HPP
