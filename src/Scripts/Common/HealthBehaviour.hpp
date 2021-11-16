#ifndef SPIC_GAME_HEALTHBEHAVIOUR_HPP
#define SPIC_GAME_HEALTHBEHAVIOUR_HPP

#include <BehaviourScript.hpp>

namespace game
{
    class HealthBehaviour : public spic::BehaviourScript
    {
        private:
            int _health;
            int _maxHealth;
        public:
            explicit HealthBehaviour(int maxHealth);

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
