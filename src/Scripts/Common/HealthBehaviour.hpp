#ifndef SPIC_GAME_HEALTHBEHAVIOUR_HPP
#define SPIC_GAME_HEALTHBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include <memory>
#include <Animator.hpp>

namespace game
{
    class HealthBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<spic::Animator> _diedAnimator;
            int _health;
            int _maxHealth;
            double _despawnDuration;
            double _despawnTime;
            bool _invincibility;

        public:
            [[nodiscard]] int Health() const;

            [[nodiscard]] int MaxHealth() const;

            void Health(int health);

            void Damage(int damage);

            HealthBehaviour(std::shared_ptr<spic::Animator> diedAnimator, int maxHealth, double despawnTime = 0);

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

            void Invincibility(bool invincibility);

            bool Invincibility() const;
    };
}

#endif
