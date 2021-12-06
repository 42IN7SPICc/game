#include "CheatManager.hpp"

#include "Debug.hpp"
#include "GameObject.hpp"
#include "Input.hpp"

#include "GameLostBehaviour.hpp"
#include "GameWonBehaviour.hpp"
#include "../../Controllers/LevelController.hpp"
#include "../../Structs/PlayerData.hpp"
#include "../../Persistence/SaveGameManager.hpp"

using namespace spic;
using namespace game;

void UnlimitedMoney()
{
    Debug::Log("Fired `Unlimited` Money Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetUnlimitedMoney();
    }
}

void Invincibility()
{
    Debug::Log("Fired Invincibility Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetInvincibility();
    }
}

void Butcher()
{
    Debug::Log("Fired Butcher Cheat");
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->ButcherEnemies();
    }
}

void Victory()
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

void GameOver()
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

void SkipWave()
{
    Debug::Log("Fired Skip Wave Cheat");
}

void NoCoolDown()
{
    Debug::Log("Fired No CoolDown Cheat");
}

void UnlockLevels()
{
    Debug::Log("Fired Unlock Levels Cheat");
    PlayerData::Instance().LevelsCompleted = 1000;
    SaveGameManager::Save(PlayerData::Instance());
}

void UnlimitedPath()
{
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetUnlimitedPath();
    }
}

void StrongPath()
{
    auto gameObject = GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        levelController->SetStrongPath();
    }
}

void ExpBoost()
{
    Debug::Log("Fired Exp Boost Cheat");
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
    _cheats[Input::KeyCode::E] = []() { return ExpBoost(); };
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
