#ifndef SPIC_GAME_BULLETBEHAVIOUR_HPP
#define SPIC_GAME_BULLETBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include <Point.hpp>
#include <RigidBody.hpp>
#include <GameObject.hpp>

namespace game
{
    class BulletBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::unique_ptr<spic::Point> _direction;
            spic::Point _startPos;
            double _maxRange;

        public:
            explicit BulletBehaviour(const spic::Point& direction, double maxRange);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_BULLETBEHAVIOUR_HPP
