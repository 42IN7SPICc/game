#ifndef SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
#define SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP

#include <BehaviourScript.hpp>

namespace game {
    class UserMovementBehaviour : public spic::BehaviourScript {
    private:
        float _velocity;
    public:
        explicit UserMovementBehaviour(float velocity);

        void OnStart() override;

        void OnUpdate() override;

        void OnTriggerEnter2D(const spic::Collider &collider) override;

        void OnTriggerExit2D(const spic::Collider &collider) override;

        void OnTriggerStay2D(const spic::Collider &collider) override;
    };
}

#endif //SPIC_GAME_USERMOVEMENTBEHAVIOUR_HPP
