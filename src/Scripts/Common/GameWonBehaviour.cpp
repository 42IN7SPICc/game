#include "GameWonBehaviour.hpp"
#include "../../Scenes/VictoryScene.hpp"
#include "../../Structs/PlayerData.hpp"

#include <Debug.hpp>
#include <Engine.hpp>

using namespace game;

GameWonBehaviour::GameWonBehaviour(game::LevelData& levelData, int balanceAward) : _won(false),
                                                                                   _levelData(levelData),
                                                                                   _balanceAward(balanceAward)
{
}

void GameWonBehaviour::OnStart()
{
    //
}

void GameWonBehaviour::OnUpdate()
{
    if (_won) return;

    if (_levelData.CurrentWave() > _levelData.TotalWaves)
    {
        OnLevelCompleted();
    }
    else if (_levelData.CurrentWave() == _levelData.TotalWaves && !_levelData.Waves.empty() && _levelData.Waves.front().RemainingEnemies() == 0)
    {
        OnLevelCompleted();
    }
}

void GameWonBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void GameWonBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void GameWonBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

void GameWonBehaviour::OnLevelCompleted()
{
    if (_won) return;
    _won = true;

    spic::Debug::Log("Level completed!");
    PlayerData::Instance().Balance += _balanceAward;

    spic::Engine::Instance().PopScene();
    spic::Engine::Instance().PushScene(std::make_shared<game::VictoryScene>());
}
