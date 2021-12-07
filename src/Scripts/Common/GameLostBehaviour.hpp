#ifndef SPIC_GAME_GAMELOSTBEHAVIOUR_HPP
#define SPIC_GAME_GAMELOSTBEHAVIOUR_HPP

#include <BehaviourScript.hpp>
#include "../../Structs/LevelData.hpp"

namespace game
{
    /**
     * @brief The script the handle the game lost screen.
     */
    class GameLostBehaviour : public spic::BehaviourScript
    {
        private:
            bool _lost;
            bool _dying;
            double _lostForTime;
            game::LevelData& _levelData;
        public:
            /**
             * @brief Constructs a new instance of a GameLostBehaviour with a given level.
             * @param levelData The data of the level.
             */
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

            /**
             * @brief Triggers when the user has failed to win the level.
             */
            void OnLevelFailed();

            /**
             * @brief Get weither the level is failed or not
             * @returns Weither the level is failed or not
             */
            bool IsLevelFailed() const;
    };
}

#endif //SPIC_GAME_GAMELOSTBEHAVIOUR_HPP
