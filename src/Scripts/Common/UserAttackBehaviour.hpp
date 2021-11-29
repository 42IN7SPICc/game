#ifndef SPIC_GAME_USERATTACKBEHAVIOUR_HPP
#define SPIC_GAME_USERATTACKBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include "Point.hpp"

namespace game
{
    class UserAttackBehaviour : public spic::BehaviourScript
    {
        private:
            int _damage;
            double _velocityMultiplier;

        public:
            explicit UserAttackBehaviour(int damage, double velocityMultiplier);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_USERATTACKBEHAVIOUR_HPP
