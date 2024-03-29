#ifndef SPIC_GAME_ABILITYBEHAVIOUR_HPP
#define SPIC_GAME_ABILITYBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"
#include "../Common/HealthBehaviour.hpp"

namespace game {
    /**
     * @brief An abstract class for hero abilities
     */
    class AbilityBehaviour : public spic::BehaviourScript
    {
        protected:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            std::shared_ptr<game::HealthBehaviour> _healthBehaviour;

        public:
            /**
             * @brief Constructor for a empty ability behaviour
             * @param coolDown the coolDown time of the ability
             */
            explicit AbilityBehaviour(double coolDown);

            /**
             * @brief Triggers when the scripts starts for the first time.
             */
            virtual void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            virtual void OnUpdate() override;

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

            /**
             * Getter for the _coolDownBehaviour field
             * @return the coolDownBehaviour
             */
            std::shared_ptr<game::CoolDownBehaviour>& GetCoolDownBehaviour();
    };
}


#endif //SPIC_GAME_ABILITYBEHAVIOUR_HPP
