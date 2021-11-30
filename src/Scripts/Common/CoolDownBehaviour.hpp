#ifndef SPIC_GAME_COOLDOWNBEHAVIOUR_HPP
#define SPIC_GAME_COOLDOWNBEHAVIOUR_HPP

#include <BehaviourScript.hpp>

namespace game
{
    class CoolDownBehaviour : public spic::BehaviourScript
    {
        private:
            double _coolDown;
            double _minCoolDown;
            bool _cooledDown;

        public:
            explicit CoolDownBehaviour(int coolDown);

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

            [[nodiscard]] bool CooledDown() const;

            void CooledDown(bool cooledDown);

            [[nodiscard]] double CoolDown() const;

            void CoolDown(double coolDown);

            [[nodiscard]] double MinCoolDown() const;

            void MinCoolDown(double minCoolDown);
    };
}


#endif
