#include "SaveGameController.hpp"
#include "../Persistence/SaveGameManager.hpp"

#include <iostream>
#include <string>

using namespace game;

void SaveGameController::OnStart()
{
    //
}

void SaveGameController::OnUpdate()
{
    //
}

void SaveGameController::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void SaveGameController::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void SaveGameController::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

void SaveGameController::InitializeSaves()
{
    _saves = SaveGameManager::GetAll();
}

void SaveGameController::Load(const std::string& saveGameName)
{
    if (!_saves.contains(saveGameName))
        throw std::runtime_error(std::string{"Save game `" + saveGameName + "` does not exist."});

    PlayerData::Instance(_saves.at(saveGameName));
}

void SaveGameController::Save()
{
    SaveGameManager::Save();
}
