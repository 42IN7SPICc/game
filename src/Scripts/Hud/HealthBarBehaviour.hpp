#ifndef SPIC_GAME_HEALTHBARBEHAVIOUR_HPP
#define SPIC_GAME_HEALTHBARBEHAVIOUR_HPP

#include "BehaviourScript.hpp"

#include "../Common/HealthBehaviour.hpp"

#include <memory>

namespace game
{
    /**
     * @brief A script to render a health bar linked to a health behaviour.
     */
    class HealthBarBehaviour : public spic::BehaviourScript
    {
        private:
            double _prevHealth;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;

        public:
            /**
             * @brief Constructs a new instance of an health bar script for a given health behaviour.
             * @param healthBehaviour The health behaviour to link to.
             */
            explicit HealthBarBehaviour(std::shared_ptr<HealthBehaviour> healthBehaviour);

            /**
             * @brief Triggers when the scripts starts for the first time.
             */
            void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;

            /**
             * @brief Triggers when the script collides with a collider.
             * @param collider The collider that collided.
             */
            void OnTriggerEnter2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers when the script stopped colliding with a collider.
             * @param collider The collider that stop colliding.
             */
            void OnTriggerExit2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers while an collider is colliding with a collider.
             * @param collider The collider is colliding.
             */
            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_HEALTHBARBEHAVIOUR_HPP
