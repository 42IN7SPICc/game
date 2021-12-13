#include "LevelManager.hpp"

#include "Managers/FileManager.hpp"
#include "JsonFacade.hpp"

using namespace game;

LevelWithTiles LevelManager::LoadLevelWithTiles(const std::string& file)
{
    try
    {
        auto contents = spic::FileManager::Load(file);
        std::string value{"[" + contents + "]"};
        auto level = spic::JsonFacade::Deserialize<LevelWithTiles>(value);
        level.File = file;

        return level;
    }
    catch (...)
    {
        throw std::runtime_error(std::string{"Failed to load level with tiles `" + file + "`."});
    }
}

Level LevelManager::LoadLevel(const std::string& file)
{
    try
    {
        auto contents = FileManager::Load(file);
        std::string value{"[" + contents + "]"};
        auto level = spic::JsonFacade::Deserialize<Level>(value);
        level.File = file;

        return level;
    }
    catch (...)
    {
        throw std::runtime_error(std::string{"Failed to load level `" + file + "`."});
    }
}

std::map<std::string, Level> LevelManager::GetAll()
{
    std::map<std::string, Level> result{};

    for (const auto& file : FileManager::GetFolderFiles("./resources/levels", ".json"))
    {
        auto level = LoadLevel(file.File);
        level.File = file.File;

        result.insert(std::make_pair(file.Name, level));
    }

    return result;
}
