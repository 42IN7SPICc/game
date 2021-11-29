#ifndef SPIC_GAME_GAMEWONBEHAVIOUR_HPP
#define SPIC_GAME_GAMEWONBEHAVIOUR_HPP


#include <BehaviourScript.hpp>
#include "../../Structs/LevelData.hpp"

namespace game
{
    class GameWonBehaviour : public spic::BehaviourScript
    {
        private:
            bool _won;
            int _balanceAward;
            LevelData& _levelData;
        public:
            explicit GameWonBehaviour(LevelData& levelData, int balanceAward = 500);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            void OnLevelCompleted();
    };
}

#endif //SPIC_GAME_GAMEWONBEHAVIOUR_HPP
