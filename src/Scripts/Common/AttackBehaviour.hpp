#ifndef SPIC_GAME_ATTACKBEHAVIOUR_HPP
#define SPIC_GAME_ATTACKBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "CoolDownBehaviour.hpp"
#include "HealthBehaviour.hpp"
#include "../../Enums/BulletType.hpp"

#include "Animator.hpp"
#include "Point.hpp"

#include <string>

namespace game
{
    /**
     * @brief A script to attack other game objects containing a health script.
     */
    class AttackBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            std::shared_ptr<game::HealthBehaviour> _healthBehaviour;

            std::string _targetTag;
            game::BulletType _bulletType;
            int _range;
            int _damage;
            double _bulletSpeed;
            int _maxPenetrating;
            double _damageRadius;
            bool _followTarget;
            std::shared_ptr<spic::Animator> _animator;

        public:
            /**
             * @brief Constructs a new instance of an AttackBehaviour with given settings.
             * @param targetTag The tag to target.
             * @param bulletType The type of bullets to shoot.
             * @param fireRate The duration between shooting a bullet (in seconds).
             * @param range The maximum distance a bullet can travel.
             * @param damage The damage the bullet does on impact.
             * @param bulletSpeed The speed to bullet travels at.
             * @param maxPenetrating How many enemies a single bullet can passthrough before disappearing
             * @param damageRadius The radius a bullet does damage in (only bulletType = bomb).
             * @param followTarget Whether to rotate the game object to face the nearest target.
             * @param animator The animator used when shooting.
             */
            AttackBehaviour(const std::string& targetTag, game::BulletType bulletType, double fireRate, int range, int damage, double bulletSpeed, int maxPenetrating = 1, double damageRadius = 0, bool followTarget = false, std::shared_ptr<spic::Animator> animator = {});

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

            /**
             * @brief Shoot a bullet towards a duration from a given position.
             * @param direction The direction the bullets shoots in.
             * @param position The start position of the bullet.
             */
            void Shoot(const spic::Point& direction, const spic::Point& position);

            /**
             * @brief The fire rate.
             * @return The current value.
             */
            [[nodiscard]] double FireRate() const;

            /**
             * @brief The fire rate.
             * @param fireRate The desired value.
             */
            void FireRate(double fireRate);

            /**
             * @brief The range of the bullet.
             * @return The current value.
             */
            [[nodiscard]] int Range() const;

            /**
             * @brief The range of the bullet.
             * @param range The desired value.
             */
            void Range(int range);

            /**
             * @brief The damage of the bullet.
             * @return The current value.
             */
            [[nodiscard]] int Damage() const;

            /**
             * @brief The damage of the bullet.
             * @param damage The desired value.
             */
            void Damage(int damage);

            /**
             * @brief The speed of the bullet.
             * @return The current value.
             */
            [[nodiscard]] double BulletSpeed() const;

            /**
             * @brief The speed of the bullet.
             * @param bulletSpeed The desired value.
             */
            void BulletSpeed(double bulletSpeed);

            /**
             * @brief The target tag of the bullet.
             * @return The current value.
             */
            [[nodiscard]] const std::string& TargetTag() const;

            /**
             * @brief The target tag of the bullet.
             * @param targetTag The desired value.
             */
            void TargetTag(const std::string& targetTag);

            /**
             * @brief The type of bullet.
             * @return The current value.
             */
            [[nodiscard]] game::BulletType BulletType() const;

            /**
             * @brief The type of bullet.
             * @param bulletType The desired value.
             */
            void BulletType(game::BulletType bulletType);

            /**
             * @brief The radius of the bullet damage.
             * @return The current value.
             */
            [[nodiscard]] double DamageRadius() const;

            /**
             * @brief The radius of the bullet damage.
             * @param damageRadius The desired value.
             */
            void DamageRadius(double damageRadius);

            /**
             * @brief Whether to follow the nearest target.
             * @return The current value.
             */
            [[nodiscard]] bool FollowTarget() const;

            /**
             * @brief Whether to follow the nearest target.
             * @param followTarget The desired value.
             */
            void FollowTarget(bool followTarget);

            /**
             * @brief The shooting animator.
             * @return The current value.
             */
            [[nodiscard]] std::shared_ptr<spic::Animator> Animator() const;

            /**
             * @brief The shooting animator.
             * @param animator The desired value.
             */
            void Animator(std::shared_ptr<spic::Animator> animator);
    };
}

#endif
