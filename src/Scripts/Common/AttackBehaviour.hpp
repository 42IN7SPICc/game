#ifndef SPIC_GAME_ATTACKBEHAVIOUR_HPP
#define SPIC_GAME_ATTACKBEHAVIOUR_HPP

#include <BehaviourScript.hpp>

namespace game
{
    class AttackBehaviour : public spic::BehaviourScript
    {
        private:
            double _fireRate;
            double _range;
            double _damage;
            bool _multiTargeting;
            double _bulletSpeed;

        public:
            AttackBehaviour(double fireRate, double range, double damage, bool multiTargeting, double bulletSpeed);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            [[nodiscard]] double FireRate() const;

            void FireRate(double fireRate);

            [[nodiscard]] double Range() const;

            void Range(double range);

            [[nodiscard]] double Damage() const;

            void Damage(double damage);

            [[nodiscard]] bool MultiTargeting() const;

            void MultiTargeting(bool multiTargeting);

            [[nodiscard]] double BulletSpeed() const;

            void BulletSpeed(double bulletSpeed);
    };
}

#endif
