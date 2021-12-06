#ifndef SPIC_GAME_COOLDOWNBEHAVIOUR_HPP
#define SPIC_GAME_COOLDOWNBEHAVIOUR_HPP

#include <BehaviourScript.hpp>

namespace game
{
    /**
     * @brief A script to handle a cool down for other scripts.
     */
    class CoolDownBehaviour : public spic::BehaviourScript
    {
        private:
            double _coolDown;
            double _minCoolDown;
            bool _cooledDown;

        public:
            /**
             * @brief Creates a new instance of a CoolDownBehaviour with a given cool down time.
             * @param coolDown The time it takes to cool down in seconds.
             */
            explicit CoolDownBehaviour(double coolDown);

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
             * @brief Whether the cool down is done.
             * @return The current value.
             */
            [[nodiscard]] bool CooledDown() const;

            /**
             * @brief Whether the cool down is done.
             * @param cooledDown The desired value.
             */
            void CooledDown(bool cooledDown);

            /**
             * @brief The time it takes to cool down.
             * @return The current value.
             */
            [[nodiscard]] double CoolDown() const;

            /**
             * @brief The time it takes to cool down.
             * @param coolDown The desired value.
             */
            void CoolDown(double coolDown);

            /**
             * @brief The time it takes to cool down from start to end.
             * @return The current value.
             */
            [[nodiscard]] double MinCoolDown() const;

            /**
             * @brief The time it takes to cool down from start to end.
             * @param minCoolDown The desired value.
             */
            void MinCoolDown(double minCoolDown);
    };
}


#endif
