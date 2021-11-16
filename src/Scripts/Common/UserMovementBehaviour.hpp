#ifndef SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP

#include <memory>
#include <BehaviourScript.hpp>
#include <RigidBody.hpp>
#include <Animator.hpp>

namespace game
{
    class UserMovementBehaviour : public spic::BehaviourScript
    {
        private:
            float _velocity;
            std::shared_ptr<spic::GameObject> _parent;
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::shared_ptr<spic::Animator> _idleAnimator;
            std::shared_ptr<spic::Animator> _walkingAnimator;
        public:
            explicit UserMovementBehaviour(float velocity, std::shared_ptr<spic::Animator> idleAnimator, std::shared_ptr<spic::Animator> walkingAnimator);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP