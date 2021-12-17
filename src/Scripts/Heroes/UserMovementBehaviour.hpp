#ifndef SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP

#include <Animator.hpp>
#include <BehaviourScript.hpp>
#include <RigidBody.hpp>

#include "../Common/HealthBehaviour.hpp"
#include "../../Structs/MapNode.hpp"

#include <map>
#include <memory>

namespace game
{
    /**
     * @brief A script to allow the user to move the hero thru the level.
     */
    class UserMovementBehaviour : public spic::BehaviourScript
    {
        private:
            float _velocity;
            bool _controllable;
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::shared_ptr<spic::Animator> _idleAnimator;
            std::shared_ptr<spic::Animator> _walkingAnimator;
            std::shared_ptr<game::HealthBehaviour> _healthBehaviour;
            std::map<std::string, game::MapNode> _graph;
        public:
            /**
             * @brief Constructs a new instance of a UserMovementBehaviour with given settings.
             * @param velocity The speed the hero moves at.
             * @param idleAnimator The animator used when the hero is not moving.
             * @param walkingAnimator The animator used when the hero is moving.
             * @param healthBehaviour The health of the hero to disable movement on death.
             */
            explicit UserMovementBehaviour(float velocity, std::shared_ptr<spic::Animator> idleAnimator, std::shared_ptr<spic::Animator> walkingAnimator, std::shared_ptr<game::HealthBehaviour> healthBehaviour);

            /**
             * @brief Whether the player should be controllable.
             * @return The current value.
             */
            [[nodiscard]] bool Controllable() const;

            /**
             * @brief Whether the player should be controllable.
             * @param controllable The desired value.
             */
            void Controllable(bool controllable);

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

            /**
             * @brief Triggers after all Update functions have been called.
             */
            void OnLateUpdate() override;
    };
}

#endif //SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
