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

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            void OnLevelFailed();
    };
}

#endif //SPIC_GAME_GAMELOSTBEHAVIOUR_HPP
