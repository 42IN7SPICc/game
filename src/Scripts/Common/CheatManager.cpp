#include "CheatManager.hpp"

#include "Debug.hpp"
#include "GameObject.hpp"
#include "Input.hpp"

#include "GameLostBehaviour.hpp"
#include "GameWonBehaviour.hpp"
#include "../../Controllers/LevelController.hpp"
#include "../../Structs/PlayerData.hpp"
#include "../../Persistence/SaveGameManager.hpp"
#include "Engine.hpp"
#include "../../Scenes/LevelSelectionScene.hpp"

using namespace spic;
using namespace game;

void CheatManager::UnlimitedMoney()
{
    Debug::Log("Fired `Unlimited` Money Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetUnlimitedMoney();
    }
}

void CheatManager::Invincibility()
{
    Debug::Log("Fired Invincibility Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetInvincibility();
    }
}

void CheatManager::Butcher()
{
    Debug::Log("Fired Butcher Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->ButcherEnemies();
    }
}

void CheatManager::Victory()
{
    Debug::Log("Fired Victory Cheat");
    auto levelController = GameObject::Find("LevelController");
    if (levelController)
    {
        auto gameWonBehaviour = levelController->GetComponent<game::GameWonBehaviour>();
        if (gameWonBehaviour)
        {
            gameWonBehaviour->OnLevelCompleted();
        }
    }
}

void CheatManager::GameOver()
{
    Debug::Log("Fired Game Over Cheat");
    auto levelController = GameObject::Find("LevelController");
    if (levelController)
    {
        auto gameLostBehaviour = levelController->GetComponent<game::GameLostBehaviour>();
        if (gameLostBehaviour)
        {
            gameLostBehaviour->OnLevelFailed();
        }
    }
}

void CheatManager::SkipWave()
{
    Debug::Log("Fired Skip Wave Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SkipWave();
    }
}

void CheatManager::NoCoolDown()
{
    Debug::Log("Fired No CoolDown Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->ToggleInfiniteCoolDown();
    }
}

void CheatManager::UnlockLevels()
{
    Debug::Log("Fired Unlock Levels Cheat");
    PlayerData::Instance().LevelsCompleted = 3;
    SaveGameManager::Save();

    auto scene = spic::Engine::Instance().PeekScene();
    auto levelSelectionScene = std::dynamic_pointer_cast<game::LevelSelectionScene>(scene);
    if(levelSelectionScene) {
        levelSelectionScene->LoadLevels(true);
    }
}

void CheatManager::UnlimitedPath()
{
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetUnlimitedPath();
    }
}

void CheatManager::StrongPath()
{
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetStrongPath();
    }
}

void CheatManager::OnStart()
{
    _cheats[Input::KeyCode::U] = []() { return UnlimitedMoney(); };
    _cheats[Input::KeyCode::I] = []() { return Invincibility(); };
    _cheats[Input::KeyCode::B] = []() { return Butcher(); };
    _cheats[Input::KeyCode::V] = []() { return Victory(); };
    _cheats[Input::KeyCode::L] = []() { return GameOver(); };
    _cheats[Input::KeyCode::S] = []() { return SkipWave(); };
    _cheats[Input::KeyCode::N] = []() { return NoCoolDown(); };
    _cheats[Input::KeyCode::A] = []() { return UnlockLevels(); };
    _cheats[Input::KeyCode::P] = []() { return UnlimitedPath(); };
    _cheats[Input::KeyCode::Q] = []() { return StrongPath(); };
}

void CheatManager::OnUpdate()
{
    for (const auto& cheat: _cheats)
    {
        if (Input::GetKey(Input::KeyCode::LEFT_CONTROL) && Input::GetKey(Input::KeyCode::LEFT_SHIFT) && Input::GetKeyDown(cheat.first))
        {
            cheat.second();
            break;
        }
    }
}

void CheatManager::OnTriggerEnter2D(const Collider& collider)
{
    Debug::LogWarning("OnTriggerEnter2D Not implemented");
}

void CheatManager::OnTriggerExit2D(const Collider& collider)
{
    Debug::LogWarning("OnTriggerExit2D Not implemented");
}

void CheatManager::OnTriggerStay2D(const Collider& collider)
{
    Debug::LogWarning("OnTriggerStay2D Not implemented");
}
