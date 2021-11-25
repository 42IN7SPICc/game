#include <Debug.hpp>
#include <Engine.hpp>
#include "GameLostBehaviour.hpp"
#include "../../Scenes/GameOverScene.hpp"

void game::GameLostBehaviour::OnStart()
{
    spic::Debug::Log("Started");
}

void game::GameLostBehaviour::OnUpdate()
{
    if (_lost) return;

    if (_levelData.MilitaryBaseHealth->Health() <= 0)
    {
        OnLevelFailed();
    }
}

void game::GameLostBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::GameLostBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::GameLostBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

game::GameLostBehaviour::GameLostBehaviour(game::LevelData& levelData) : _levelData(levelData), _lost(false)
{

}

void game::GameLostBehaviour::OnLevelFailed()
{
    if (_lost) return;
    _lost = true;
    spic::Debug::Log("Level completed!");

    spic::Engine::Instance().PopScene();
    spic::Engine::Instance().PushScene(std::make_shared<game::GameOverScene>());
}
