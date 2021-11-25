#include "SaveGameManager.hpp"
#include "FileManager.hpp"

#include <JsonFacade.hpp>

using namespace game;

void SaveGameManager::Save(const PlayerData& playerData)
{
    auto contents = spic::JsonFacade::Serialize(playerData);
    FileManager::Save(playerData.File, contents);
}

PlayerData SaveGameManager::Load(const std::string& file)
{
    try
    {
        auto contents = FileManager::Load(file);
        auto playerData = spic::JsonFacade::Deserialize<PlayerData>(contents);

        return playerData;
    }
    catch (...)
    {
        throw std::runtime_error(std::string{"Failed to load player data `" + file + "`."});
    }
}

std::map<std::string, PlayerData> SaveGameManager::GetAll()
{
    std::map<std::string, PlayerData> result;

    std::string path = "./resources/saves";
    std::string extension = ".json";

    for (const auto& file: FileManager::GetFolderFiles(path, extension))
    {
        auto playerData = Load(file.File);
        playerData.File = file.File;

        result.insert(std::make_pair(file.Name, playerData));

    }

    if (result.empty())
    {
        PlayerData playerData{};
        playerData.File = path + "/save1" + extension;

        result.insert(std::make_pair("save1", playerData));
    }

    return result;
}