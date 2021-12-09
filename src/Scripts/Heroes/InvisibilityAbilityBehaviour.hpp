#ifndef SPIC_GAME_INVISIBILITYABILITYBEHAVIOUR_HPP
#define SPIC_GAME_INVISIBILITYABILITYBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"
#include "../Common/HealthBehaviour.hpp"

namespace game {
    class InvisibilityAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;
            std::shared_ptr<spic::Sprite> _sprite;
            bool _abilityActive;

        public:
            InvisibilityAbilityBehaviour();

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}


#endif
