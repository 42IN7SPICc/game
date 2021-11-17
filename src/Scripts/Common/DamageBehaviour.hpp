#ifndef SPIC_GAME_DAMAGEBEHAVIOUR_HPP
#define SPIC_GAME_DAMAGEBEHAVIOUR_HPP


#include <BehaviourScript.hpp>

namespace game
{

    class DamageBehaviour : public spic::BehaviourScript
    {
        private:
            int _damage;

        public:
            explicit DamageBehaviour(int damage);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };

}
#endif //SPIC_GAME_DAMAGEBEHAVIOUR_HPP
