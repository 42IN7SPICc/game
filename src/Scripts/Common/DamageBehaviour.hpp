#ifndef SPIC_GAME_DAMAGEBEHAVIOUR_HPP
#define SPIC_GAME_DAMAGEBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "HealthBehaviour.hpp"

#include <string>

namespace game
{
    class DamageBehaviour : public spic::BehaviourScript
    {
        private:
            std::string _targetTag;
            int _damage;
            int _radius;
            int _objectsDamaged;

        public:
            explicit DamageBehaviour(int damage, const std::string& targetTag = "", int radius = 0);

            void Damage(const std::shared_ptr<game::HealthBehaviour>& gameObject);

            [[nodiscard]] int Damage() const;

            void Damage(int damage);

            [[nodiscard]] const std::string& TargetTag() const;

            void TargetTag(const std::string& targetTag);

            [[nodiscard]] int Radius() const;

            void Radius(int radius);

            [[nodiscard]] int ObjectsDamaged() const;

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif //SPIC_GAME_DAMAGEBEHAVIOUR_HPP
