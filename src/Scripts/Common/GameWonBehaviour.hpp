#ifndef SPIC_GAME_GAMEWONBEHAVIOUR_HPP
#define SPIC_GAME_GAMEWONBEHAVIOUR_HPP


#include <BehaviourScript.hpp>
#include "../../Structs/LevelData.hpp"

namespace game
{
    /**
     * @brief A script that handles the game won screen.
     */
    class GameWonBehaviour : public spic::BehaviourScript
    {
        private:
            bool _won;
            int _balanceAward;
            game::LevelData& _levelData;
        public:
            /**
             * @brief Constructs a new instance of a GameWonBehaviour with a given level and balance.
             * @param levelData The data of the level.
             * @param balanceAward The award that the user has received.
             */
            explicit GameWonBehaviour(game::LevelData& levelData, int balanceAward = 500);

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
             * @brief Triggers when the level has been completed.
             */
            void OnLevelCompleted();
    };
}

#endif //SPIC_GAME_GAMEWONBEHAVIOUR_HPP
