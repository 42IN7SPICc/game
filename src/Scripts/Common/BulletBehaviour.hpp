#ifndef SPIC_GAME_BULLETBEHAVIOUR_HPP
#define SPIC_GAME_BULLETBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include <Point.hpp>

namespace game
{
    class BulletBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<spic::GameObject> _parent;
            std::unique_ptr<spic::Point> _direction;

        public:
            explicit BulletBehaviour(const spic::Point& direction);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_BULLETBEHAVIOUR_HPP
