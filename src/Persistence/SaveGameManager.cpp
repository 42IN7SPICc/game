#include "SaveGameManager.hpp"

#include "Managers/FileManager.hpp"
#include "JsonFacade.hpp"

#include "Debug.hpp"

using namespace game;

void SaveGameManager::Save()
{
    Save(PlayerData::Instance());
}

void SaveGameManager::Save(const PlayerData& playerData)
{
    auto contents = spic::JsonFacade::Serialize(playerData);
    spic::FileManager::Save(playerData.File, contents);
}

PlayerData SaveGameManager::Load(const std::string& file)
{
    try
    {
        auto contents = spic::FileManager::Load(file);
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

    for (const auto& file: spic::FileManager::GetFolderFiles(path, extension))
    {
        try
        {
            auto playerData = Load(file.File);
            playerData.File = file.File;

            result.insert(std::make_pair(file.Name, playerData));
        }
        catch (...)
        {
            spic::Debug::LogWarning("Error loading save game `" + file.File + "`");
        }
    }

    return result;
}