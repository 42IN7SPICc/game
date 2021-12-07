#ifndef SPIC_GAME_INCREASETOWERRANGEABILITY_HPP
#define SPIC_GAME_INCREASETOWERRANGEABILITY_HPP

#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"

namespace game
{
    class IncreaseTowerRangeAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            bool _abilityActivated;

        public:
            IncreaseTowerRangeAbilityBehaviour();

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}


#endif
