#ifndef SPIC_GAME_ENEMYINVISIBLEBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYINVISIBLEBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "Sprite.hpp"

#include "../Common/CoolDownBehaviour.hpp"
#include "../Common/HealthBehaviour.hpp"

#include <memory>

namespace game
{
    class EnemyInvisibleBehaviour : public spic::BehaviourScript
    {
        private:
            int _effectTime;
            int _coolDownTime;

            std::shared_ptr<CoolDownBehaviour> _effectTimer;
            std::shared_ptr<CoolDownBehaviour> _effectCoolDown;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;
            std::shared_ptr<spic::Sprite> _sprite;

        public:
            EnemyInvisibleBehaviour(int effectTime, int coolDownTime);

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

#endif //SPIC_GAME_ENEMYINVISIBLEBEHAVIOUR_HPP
