#ifndef SPIC_GAME_ATTACKBEHAVIOUR_HPP
#define SPIC_GAME_ATTACKBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "CoolDownBehaviour.hpp"
#include "../../Enums/BulletType.hpp"

#include "Animator.hpp"
#include "Point.hpp"

#include <string>

namespace game
{
    class AttackBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;

            std::string _targetTag;
            game::BulletType _bulletType;
            int _range;
            int _damage;
            double _bulletSpeed;
            double _damageRadius;
            bool _followTarget;
            std::shared_ptr<spic::Animator> _animator;

        public:
            AttackBehaviour(const std::string& targetTag, game::BulletType bulletType, double fireRate, int range, int damage, double bulletSpeed, double damageRadius = 0, bool followTarget = false, std::shared_ptr<spic::Animator> animator = {});

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

            void Shoot(const spic::Point& direction, const spic::Point& position);

            [[nodiscard]] double FireRate() const;

            void FireRate(double fireRate);

            [[nodiscard]] int Range() const;

            void Range(int range);

            [[nodiscard]] int Damage() const;

            void Damage(int damage);

            [[nodiscard]] double BulletSpeed() const;

            void BulletSpeed(double bulletSpeed);

            [[nodiscard]] const std::string& TargetTag() const;

            void TargetTag(const std::string& targetTag);

            [[nodiscard]] game::BulletType BulletType() const;

            void BulletType(game::BulletType bulletType);

            [[nodiscard]] double DamageRadius() const;

            void DamageRadius(double damageRadius);

            [[nodiscard]] bool FollowTarget() const;

            void FollowTarget(bool followTarget);

            [[nodiscard]] std::shared_ptr<spic::Animator> Animator() const;

            void Animator(std::shared_ptr<spic::Animator> animator);
    };
}

#endif
