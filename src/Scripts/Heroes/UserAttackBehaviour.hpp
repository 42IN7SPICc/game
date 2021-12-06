#ifndef SPIC_GAME_USERATTACKBEHAVIOUR_HPP
#define SPIC_GAME_USERATTACKBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include "Point.hpp"
#include "../Common/HealthBehaviour.hpp"
#include "../Common/CoolDownBehaviour.hpp"
#include "../../Enums/LevelMode.hpp"

namespace game
{
    /**
     * @brief A script to let the user attack.
     */
    class UserAttackBehaviour : public spic::BehaviourScript
    {
        private:
            int _damage;
            double _velocityMultiplier;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;
            std::shared_ptr<CoolDownBehaviour> _coolDownBehaviour;

        public:
            /**
             * @brief Creates a new instance of a UserAttackBehaviour with given settings.
             * @param damage The damage the bullets give on impact.
             * @param velocityMultiplier The speed multiplier of the bullets.
             * @param healthBehaviour The health of the enemy.
             */
            explicit UserAttackBehaviour(int damage, double velocityMultiplier, std::shared_ptr<game::HealthBehaviour> healthBehaviour);

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

#endif //SPIC_GAME_USERATTACKBEHAVIOUR_HPP
