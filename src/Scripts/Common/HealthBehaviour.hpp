#ifndef SPIC_GAME_HEALTHBEHAVIOUR_HPP
#define SPIC_GAME_HEALTHBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include <memory>
#include <Animator.hpp>

namespace game
{
    /**
     * @brief A script to handle health on a entity.
     */
    class HealthBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<spic::Animator> _diedAnimator;
            int _health;
            int _maxHealth;
            double _despawnDuration;
            double _despawnTime;
            bool _invincibility;
            int _diedCount;

        public:
            /**
             * @brief Constructs a new instance of a HealthBehaviour with given settings.
             * @param diedAnimator The animator to play when the entity died.
             * @param maxHealth The health of the entity.
             * @param despawnTime The time it takes to despawn after dying (0 to disable).
             */
            HealthBehaviour(std::shared_ptr<spic::Animator> diedAnimator, int maxHealth, double despawnTime);

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
             * @brief The health of the entity.
             * @return The current value.
             */
            [[nodiscard]] int Health() const;

            /**
             * @brief The health of the entity.
             * @param health The desired value.
             */
            void Health(int health);

            /**
             * @brief The max health of the entity.
             * @return The current value.
             */
            [[nodiscard]] int MaxHealth() const;

            /**
             * @brief The max health of the entity.
             * @param damage The desired value.
             */
            void Damage(int damage);

            /**
             * @brief Whether the entity is invincible.
             * @return The current value.
             */
            bool Invincibility() const;

            /**
             * @brief Whether the entity is invincible.
             * @param invincibility The desired value.
             */
            void Invincibility(bool invincibility);
    };
}

#endif
