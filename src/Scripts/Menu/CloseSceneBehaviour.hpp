#ifndef SPIC_GAME_CLOSESCENEBEHAVIOUR_HPP
#define SPIC_GAME_CLOSESCENEBEHAVIOUR_HPP

#include "BehaviourScript.hpp"

namespace game
{
    /**
     * @brief A script to close the scene when pressing the ESC ky.
     */
    class CloseSceneBehaviour : public spic::BehaviourScript
    {
        public:
            /**
             * @brief Constructor.
             * @param popAmount Amount of scenes to pop
             */
            explicit CloseSceneBehaviour(int popAmount = 1);

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

        private:
            int _popAmount;
    };
}

#endif //SPIC_GAME_CLOSESCENEBEHAVIOUR_HPP
