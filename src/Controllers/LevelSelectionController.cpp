#include "LevelSelectionController.hpp"
#include "../Persistence/LevelManager.hpp"

#include <iostream>
#include <string>

using namespace game;

LevelWithTiles LevelSelectionController::LoadLevel(const std::string& file) const
{
    return LevelManager::LoadLevelWithTiles(file);
}

void LevelSelectionController::InitializeLevels()
{
    _levels = LevelManager::GetAll();
}

Level LevelSelectionController::GetLevelDto(const std::string& levelName) const
{
    auto tmp = _levels;
    if (_levels.contains(levelName))
        return _levels.at(levelName);

    throw std::runtime_error(std::string{"Level `" + levelName + "` does not exist."});
}

