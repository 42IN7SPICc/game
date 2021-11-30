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
    /**
     * @brief A script to handle movement for the enemy.
     */
    class EnemyMovementBehaviour : public spic::BehaviourScript
    {
        private:
            float _velocity;
            std::map<std::string, game::MapNode> _graph;
            std::queue<std::string> _path;
            std::shared_ptr<spic::Animator> _walkingAnimator;
            std::shared_ptr<HealthBehaviour> _healthBehaviour;
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::shared_ptr<spic::Sprite> _sprite;

        public:
            /**
             * @brief Constructs a new instance of an EnemyMovementBehaviour with a given walking animator.
             * @param walkingAnimator The animator to when walking.
             * @param velocity The velocity the enemy moves at.
             */
            EnemyMovementBehaviour(std::shared_ptr<spic::Animator> walkingAnimator, float velocity);

            /**
             * @brief Triggers when the scripts starts for the first time.
             */
            void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;

            /**
             * @brief Triggers when the script collides with a collider.
             * @param collider The collider that collided.
             */
            void OnTriggerEnter2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers when the script stopped colliding with a collider.
             * @param collider The collider that stop colliding.
             */
            void OnTriggerExit2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers while an collider is colliding with a collider.
             * @param collider The collider is colliding.
             */
            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_ENEMYMOVEMENTBEHAVIOUR_HPP
