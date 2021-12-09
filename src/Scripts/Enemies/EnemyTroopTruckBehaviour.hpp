#ifndef SPIC_GAME_ENEMYTROOPTRUCKBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYTROOPTRUCKBEHAVIOUR_HPP

#include "../Common/HealthBehaviour.hpp"
#include "../../Enums/EnemyName.hpp"

#include "BehaviourScript.hpp"
#include "GameObject.hpp"

namespace game
{
    /**
     * @brief A behaviour script that spawns a given amount of enemies when the current entity dies.
     */
    class EnemyTroopTruckBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<HealthBehaviour> _healthBehaviour;
            EnemyName _enemyName;
            int _count;

        public:
            /**
             * @brief Constructs a new instance of an EnemyTroopTruckBehaviour with given settings.
             * @param enemyName The name of the enemy to spawn.
             * @param count The amount of enemies to spawn.
             */
            EnemyTroopTruckBehaviour(EnemyName enemyName, int count);

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

#endif //SPIC_GAME_ENEMYTROOPTRUCKBEHAVIOUR_HPP
