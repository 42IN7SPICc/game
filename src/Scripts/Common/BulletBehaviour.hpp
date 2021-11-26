#ifndef SPIC_GAME_BULLETBEHAVIOUR_HPP
#define SPIC_GAME_BULLETBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include <Point.hpp>
#include <RigidBody.hpp>
#include <GameObject.hpp>

#include "../../Enums/BulletType.hpp"

#include "DamageBehaviour.hpp"

namespace game
{
    class BulletBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<spic::RigidBody> _rigidBody;
            std::shared_ptr<DamageBehaviour> _damageBehaviour;
            std::unique_ptr<spic::Point> _direction;
            spic::Point _startPos;
            double _maxRange;
            BulletType _bulletType;

        public:
            explicit BulletBehaviour(BulletType bulletType, const spic::Point& direction, double maxRange);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_BULLETBEHAVIOUR_HPP
