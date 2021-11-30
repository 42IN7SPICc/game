#ifndef SPIC_GAME_GAMELOSTBEHAVIOUR_HPP
#define SPIC_GAME_GAMELOSTBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include "../../Structs/LevelData.hpp"

namespace game
{
    class GameLostBehaviour : public spic::BehaviourScript
    {
        private:
            bool _lost;
            game::LevelData& _levelData;
        public:
            explicit GameLostBehaviour(game::LevelData& levelData);

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

            void OnLevelFailed();
    };
}

#endif //SPIC_GAME_GAMELOSTBEHAVIOUR_HPP
