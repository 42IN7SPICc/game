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
            int _maxPenetrating;
            BulletType _bulletType;

        public:
            explicit BulletBehaviour(BulletType bulletType, const spic::Point& direction, double maxRange, int maxPenetrating = 1);

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

#endif //SPIC_GAME_BULLETBEHAVIOUR_HPP
