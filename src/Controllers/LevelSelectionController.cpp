#include "LevelSelectionController.hpp"
#include "../Persistence/LevelManager.hpp"
#include "../Structs/PlayerData.hpp"

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
    if (_levels.contains(levelName))
        return _levels.at(levelName);

    throw std::runtime_error(std::string{"Level `" + levelName + "` does not exist."});
}

std::vector<Level> LevelSelectionController::GetLevels() const
{
    std::vector<Level> levels;

    for (const auto&[key, value]: _levels)
    {
        levels.push_back(value);
    }

    return levels;
}

