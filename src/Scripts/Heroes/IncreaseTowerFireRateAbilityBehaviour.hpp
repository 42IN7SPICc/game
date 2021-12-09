#ifndef SPIC_GAME_INCREASETOWERFIRERATEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_INCREASETOWERFIRERATEABILITYBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"

namespace game {
    /**
     * @brief A script for handling the Tower Fire Rate Ability for Winston Churchill
     */
    class IncreaseTowerFireRateAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            bool _abilityActivated;

        public:
            /**
             * @brief Constructor for the IncreaseTowerFireRateAbilityBehaviour
             */
            IncreaseTowerFireRateAbilityBehaviour();

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
