#ifndef SPIC_GAME_CAMERAPREFABFACTORY_HPP
#define SPIC_GAME_CAMERAPREFABFACTORY_HPP

#include "Camera.hpp"

#include <memory>

namespace game
{
    /**
     * @brief A factory to create cameras.
     */
    class CameraPrefabFactory
    {
        public:
            /**
             * @brief Construct a new instance of a camera based on the engine config.
             * @param backgroundColor The background color of the camera.
             * @return The camera.
             */
            static std::shared_ptr<spic::Camera> CreateCamera(const spic::Color& backgroundColor);
    };
}

#endif //SPIC_GAME_CAMERAPREFABFACTORY_HPP
