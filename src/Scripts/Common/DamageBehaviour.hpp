#ifndef SPIC_GAME_DAMAGEBEHAVIOUR_HPP
#define SPIC_GAME_DAMAGEBEHAVIOUR_HPP

#include "BehaviourScript.hpp"
#include "HealthBehaviour.hpp"

#include <string>

namespace game
{
    /**
     * @brief A script that handles damage on health scripts.
     */
    class DamageBehaviour : public spic::BehaviourScript
    {
        private:
            std::string _targetTag;
            int _damage;
            int _radius;
            int _objectsDamaged;

        public:
            /**
             * @brief Constructs a new instance of a DamageBehaviour with given values.
             * @param damage The damage to deal on impact.
             * @param targetTag The tag to deal damage to.
             * @param radius The radius to deal damage in.
             */
            explicit DamageBehaviour(int damage, const std::string& targetTag = "", int radius = 0);

            /**
             * @brief Give damage to a given health script.
             * @param gameObject The health script to give damage to.
             */
            void Damage(const std::shared_ptr<game::HealthBehaviour>& gameObject);

            /**
             * @brief The amount of damage to deal to the target.
             * @return The current value.
             */
            [[nodiscard]] int Damage() const;

            /**
             * @brief The amount of damage to deal to the target.
             * @param damage The desired value.
             */
            void Damage(int damage);

            /**
             * @brief The tag to give damage to.
             * @return The current value.
             */
            [[nodiscard]] const std::string& TargetTag() const;

            /**
             * @brief The tag to give damage to.
             * @param targetTag The desired value.
             */
            void TargetTag(const std::string& targetTag);

            /**
             * @brief The radius to deal damage in.
             * @return The current value.
             */
            [[nodiscard]] int Radius() const;

            /**
             * @brief The radius to deal damage in.
             * @param radius The desired value.
             */
            void Radius(int radius);

            /**
             * @brief The amount of objects that have been damaged.
             * @return The current value.
             */
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
