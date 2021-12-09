#ifndef SPIC_GAME_INCREASETOWERRANGEABILITY_HPP
#define SPIC_GAME_INCREASETOWERRANGEABILITY_HPP

#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"
#include "../Common/HealthBehaviour.hpp"

namespace game
{
    /**
     * @brief A script for handling the Tower Range ability for Franklin D Roosevelt
     */
    class IncreaseTowerRangeAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            std::shared_ptr<game::HealthBehaviour> _healthBehaviour;
            bool _abilityActivated;

        public:
            /**
             * @brief Constructor for the IncreaseTowerRangeAbilityBehaviour
             */
            IncreaseTowerRangeAbilityBehaviour();

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


#endif
