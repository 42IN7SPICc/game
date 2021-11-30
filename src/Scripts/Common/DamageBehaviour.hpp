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

#endif //SPIC_GAME_DAMAGEBEHAVIOUR_HPP
