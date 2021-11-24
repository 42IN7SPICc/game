#include "LevelSelectionController.hpp"
#include "../Utils/StringUtil.hpp"

#include <JsonFacade.hpp>

#include <iostream>
#include <GameObject.hpp>
#include <filesystem>
#include <fstream>
#include <exception>

using namespace game;

const int TileSize = 32;

LevelWithTiles LevelSelectionController::LoadLevel(const std::string& file)
{
    try
    {
        auto contents = LoadFile(file);
        auto level = spic::JsonFacade::Deserialize<LevelWithTiles>("[" + contents + "]");
        level.File = file;

        return level;
    }
    catch (...)
    {
        throw std::runtime_error(std::string{"Failed to load level `" + file + "`."});
    }
}

void LevelSelectionController::InitializeLevels()
{
    std::string path = "./resources/levels";
    std::string ext = ".json";

    for (const auto& entry: std::filesystem::directory_iterator(path))
    {
        std::string file{entry.path().string()};

        if (StringUtil::EndsWith(file, ext))
        {
            auto name = file.substr(path.size() + 1, file.size() - 1);
            for (int i = 0; i < ext.size(); ++i) name.pop_back();

            InitializeLevel(file, name);
        }
    }
}

void LevelSelectionController::InitializeLevel(const std::string& file, const std::string& name)
{
    try
    {
        auto contents = LoadFile(file);
        auto level = spic::JsonFacade::Deserialize<Level>("[" + contents + "]");
        level.File = file;

        _levels.insert(std::make_pair(name, level));
    }
    catch (...)
    {
        throw std::runtime_error(std::string{"Failed to initialize level `" + file + "`."});
    }
}

Level LevelSelectionController::GetLevelDto(const std::string& levelName)
{
    if (_levels.contains(levelName))
        return _levels.at(levelName);

    throw std::runtime_error(std::string{"Level `" + levelName + "` does not exist."});
}

std::string LevelSelectionController::LoadFile(const std::string& fileName)
{
    try
    {
        std::ifstream levelFile(fileName);
        std::string contents((std::istreambuf_iterator<char>(levelFile)), std::istreambuf_iterator<char>());
        levelFile.close();

        return contents;
    }
    catch (std::exception&)
    {
        throw std::runtime_error(std::string{"Something went wrong handling `" + fileName + "`."});
    }

}

