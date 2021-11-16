#ifndef SPIC_GAME_HEALABILITYBEHAVIOUR_HPP
#define SPIC_GAME_HEALABILITYBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include "CoolDownBehaviour.hpp"

namespace game
{
    class HealAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            game::CoolDownBehaviour _coolDownBehaviour;
        public:
            HealAbilityBehaviour();

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif
