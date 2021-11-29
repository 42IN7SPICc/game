#ifndef SPIC_GAME_ATTACKBEHAVIOUR_HPP
#define SPIC_GAME_ATTACKBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "CoolDownBehaviour.hpp"
#include "../../Enums/BulletType.hpp"

#include "Point.hpp"

#include <string>

namespace game
{
    class AttackBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;

            std::string _targetTag;
            BulletType _bulletType;
            int _range;
            int _damage;
            bool _multiTargeting;
            double _bulletSpeed;
            double _damageRadius;

        public:
            AttackBehaviour(const std::string& targetTag, BulletType bulletType, double fireRate, int range, int damage, bool multiTargeting, double bulletSpeed, double damageRadius = 0);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            void Shoot(const spic::Point& direction, const spic::Point& position);

            [[nodiscard]] double FireRate() const;

            void FireRate(double fireRate);

            [[nodiscard]] double Range() const;

            void Range(double range);

            [[nodiscard]] int Damage() const;

            void Damage(int damage);

            [[nodiscard]] bool MultiTargeting() const;

            void MultiTargeting(bool multiTargeting);

            [[nodiscard]] double BulletSpeed() const;

            void BulletSpeed(double bulletSpeed);

            const std::string& TargetTag() const;

            void TargetTag(const std::string& targetTag);

            BulletType BulletType() const;

            void BulletType(BulletType bulletType);

            double DamageRadius() const;

            void DamageRadius(double damageRadius);
    };
}

#endif
