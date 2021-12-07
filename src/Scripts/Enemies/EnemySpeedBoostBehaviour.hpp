#ifndef SPIC_GAME_ENEMYSPEEDBOOSTBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYSPEEDBOOSTBEHAVIOUR_HPP

#include "BehaviourScript.hpp"

#include "../Common/CoolDownBehaviour.hpp"

#include <memory>

namespace game
{
    /**
     * @brief A behaviour script to boost other enemies in a certain range.
     */
    class EnemySpeedBoostBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<CoolDownBehaviour> _coolDownBehaviour;
            int _boostCoolDown;
            double _speedBoost;
            int _boostTime;
            double _boostRange;

        public:
            /**
             * @brief Constructs a new instance of a EnemySpeedBoostBehaviour with given settings.
             * @param boostCoolDown The time it takes to boost again (in seconds).
             * @param speedBoost The multiplier for the speed of the enemy.
             * @param boostTime The time the boost effect lasts (in seconds).
             * @param boostRange The range enemies have to be in to get the effect.
             */
            EnemySpeedBoostBehaviour(int boostCoolDown, double speedBoost, int boostTime, double boostRange);

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

#endif //SPIC_GAME_ENEMYSPEEDBOOSTBEHAVIOUR_HPP
