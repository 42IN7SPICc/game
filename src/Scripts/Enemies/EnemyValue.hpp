#ifndef SPIC_GAME_ENEMYVALUE_HPP
#define SPIC_GAME_ENEMYVALUE_HPP

#include <BehaviourScript.hpp>

namespace game
{
    /**
     * @brief A component that stores the worth of a enemy.
     */
    class EnemyValue : public spic::BehaviourScript
    {
        private:
            int _value;

        public:
            /**
             * @brief Construct a new instance of an EnemyValue with a given value.
             * @param value The worth of the enemy.
             */
            explicit EnemyValue(int value);

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

            /**
             * @brief The worth of the value.
             * @return The current value.
             */
            const int& Value() const;
    };
}

#endif //SPIC_GAME_ENEMYVALUE_HPP
