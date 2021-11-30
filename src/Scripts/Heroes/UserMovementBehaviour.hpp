#ifndef SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP

#include <memory>
#include <BehaviourScript.hpp>
#include <RigidBody.hpp>
#include <Animator.hpp>
#include "../Common/HealthBehaviour.hpp"

namespace game
{
    class UserMovementBehaviour : public spic::BehaviourScript
    {
        private:
            float _velocity;
            bool _controllable;
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::shared_ptr<spic::Animator> _idleAnimator;
            std::shared_ptr<spic::Animator> _walkingAnimator;
            std::shared_ptr<game::HealthBehaviour> _healthBehaviour;
        public:
            explicit UserMovementBehaviour(float velocity, std::shared_ptr<spic::Animator> idleAnimator, std::shared_ptr<spic::Animator> walkingAnimator, std::shared_ptr<game::HealthBehaviour> healthBehaviour);

            [[nodiscard]] bool Controllable() const;

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
    };
}

#endif //SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
