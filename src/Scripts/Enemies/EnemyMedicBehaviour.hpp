#ifndef SPIC_GAME_ENEMYMEDICBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYMEDICBEHAVIOUR_HPP

#include "../Common/CoolDownBehaviour.hpp"

#include "BehaviourScript.hpp"
#include "GameObject.hpp"

#include <memory>

namespace game
{
    /**
     * @brief A behaviour that heals other enemies in a certain range.
     */
    class EnemyMedicBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<CoolDownBehaviour> _healCoolDownBehaviour;
            int _healPercentage;
            double _healRange;
            int _healCoolDown;

        public:
            /**
             * @brief Constructs a new instance of a EnemyMedicBehaviour with given settings.
             * @param healPercentage The percentage the targets will be healed (between 1 and 100).
             * @param healRange The range the targets have to be in to be healed.
             * @param healCoolDown The times it takes to heal again (in seconds).
             */
            EnemyMedicBehaviour(int healPercentage, double healRange, int healCoolDown);

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

#endif //SPIC_GAME_ENEMYMEDICBEHAVIOUR_HPP
