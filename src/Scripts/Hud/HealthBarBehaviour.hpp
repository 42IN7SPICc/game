#ifndef SPIC_GAME_HEALTHBARBEHAVIOUR_HPP
#define SPIC_GAME_HEALTHBARBEHAVIOUR_HPP

#include "BehaviourScript.hpp"

#include "../Common/HealthBehaviour.hpp"

#include <memory>

namespace game
{
    class HealthBarBehaviour : public spic::BehaviourScript
    {
        private:
            double _prevHealth;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;

        public:
            explicit HealthBarBehaviour(std::shared_ptr<HealthBehaviour> healthBehaviour);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_HEALTHBARBEHAVIOUR_HPP
