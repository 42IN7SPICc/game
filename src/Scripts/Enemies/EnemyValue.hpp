#ifndef SPIC_GAME_ENEMYVALUE_HPP
#define SPIC_GAME_ENEMYVALUE_HPP

#include <BehaviourScript.hpp>

namespace game
{
    class EnemyValue : public spic::BehaviourScript
    {
        private:
            int _value;

        public:
            explicit EnemyValue(int value);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            const int& Value() const;
    };
}

#endif //SPIC_GAME_ENEMYVALUE_HPP
