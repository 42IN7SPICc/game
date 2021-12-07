#ifndef SPIC_GAME_ENEMYSUICIDEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYSUICIDEABILITYBEHAVIOUR_HPP

#include "BehaviourScript.hpp"

namespace game {
    class EnemySuicideAbilityBehaviour : public spic::BehaviourScript
    {
        public:
            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}


#endif
