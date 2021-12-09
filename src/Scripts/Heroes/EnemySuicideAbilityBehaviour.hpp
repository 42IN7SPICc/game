#ifndef SPIC_GAME_ENEMYSUICIDEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYSUICIDEABILITYBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"

namespace game {
    class EnemySuicideAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            bool _abilityActive;

        public:
            EnemySuicideAbilityBehaviour();

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}


#endif
