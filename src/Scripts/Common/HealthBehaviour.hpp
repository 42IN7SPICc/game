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

        public:
            [[nodiscard]] int Health() const;

            [[nodiscard]] int MaxHealth() const;

            void Health(int health);

            void Damage(int damage);

            HealthBehaviour(std::shared_ptr<spic::Animator> diedAnimator, int maxHealth);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            void Health(int health);

            int Health() const;
    };
}

#endif
