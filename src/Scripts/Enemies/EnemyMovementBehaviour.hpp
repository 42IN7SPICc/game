#ifndef SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP

#include "../../Structs/MapNode.hpp"
#include "../Common/HealthBehaviour.hpp"

#include "Animator.hpp"
#include "BehaviourScript.hpp"
#include "RigidBody.hpp"
#include "Sprite.hpp"

#include <string>
#include <map>
#include <queue>

namespace game
{
    class EnemyMovementBehaviour : public spic::BehaviourScript
    {
        private:
            std::map<std::string, game::MapNode> _graph;
            std::queue<std::string> _path;
            std::shared_ptr<spic::Animator> _walkingAnimator;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::shared_ptr<spic::Sprite> _sprite;

        public:
            EnemyMovementBehaviour(std::shared_ptr<spic::Animator> walkingAnimator);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
