#include "CheatManager.hpp"
#include "Input.hpp"
#include "Debug.hpp"
#include "GameObject.hpp"
#include "GameWonBehaviour.hpp"

using namespace spic;
using namespace game;

void UnlimitedMoney()
{
    Debug::Log("Fired Unlimited Money Cheat");
}

void Invincibility()
{
    Debug::Log("Fired Invincibility Cheat");
}

void Butcher()
{
    Debug::Log("Fired Butcher Cheat");
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
}

void UnlimitedPath()
{
    Debug::Log("Fired Unlimited Path Cheat");
}

void StrongPath()
{
    Debug::Log("Fired Strong Path Cheat");
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
