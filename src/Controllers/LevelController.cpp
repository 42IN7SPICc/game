#include "LevelController.hpp"
#include "../Utils/StringUtil.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/TileUtil.hpp"
#include "../Utils/Layer.hpp"

#include <iostream>
#include <GameObject.hpp>
#include <Sprite.hpp>
#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <exception>

using namespace game;

std::shared_ptr<spic::GameObject> LevelController::GetLevelGameObject(const std::string& fileName)
{
    auto document = LoadFile(fileName);

    auto tileMap = std::make_shared<spic::GameObject>("TileGrid", "tilemap", Layer::Game);

    if (!document.HasMember("tiles"))
        throw std::runtime_error(std::string{"The tiles for `" + _levels[fileName].File + "` could not be parsed"});

    const rapidjson::Value& tiles = document["tiles"];

    for (int i = 0; i < tiles.Size(); ++i)
    {
        auto name = "Tile_" + std::to_string(i) + "_Type_" + std::to_string(tiles[i]["type"].GetInt());

        auto tile = std::make_shared<spic::GameObject>(name, "tile", Layer::Game);
        auto sprite = std::make_shared<spic::Sprite>(TileUtil::GetSprite((TileType) tiles[i]["type"].GetInt()), false, false, 1, 1);

        tile->Transform().position.x = tiles[i]["x"].GetInt() * 32;
        tile->Transform().position.y = tiles[i]["y"].GetInt() * 32;

        GameObjectUtil::LinkComponent(tile, sprite);
        GameObjectUtil::LinkChild(tileMap, tile);
    }

    return tileMap;
}

void LevelController::InitializeLevels()
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

void LevelController::InitializeLevel(const std::string& file, const std::string& name)
{
    try
    {
        auto document = LoadFile(file);

        if (!document.HasMember("title"))
            throw std::runtime_error(std::string{"The title for `" + file + "` could not be parsed"});

        if (!document.HasMember("description"))
            throw std::runtime_error(std::string{"The description for `" + file + "` could not be parsed"});

        if (!document.HasMember("unlockThreshold"))
            throw std::runtime_error(std::string{"The unlockThreshold for `" + file + "` could not be parsed"});

        _levels.insert(std::make_pair(name, Level{
                document["title"].GetString(),
                document["description"].GetString(),
                file,
                document["unlockThreshold"].GetInt()
        }));
    }
    catch (...)
    {
        throw std::runtime_error(std::string{"Failed to initialize level `" + file + "`."});
    }
}

rapidjson::Document LevelController::LoadFile(const std::string& fileName)
{
    try
    {
        std::ifstream levelFile(fileName.c_str());
        std::string contents((std::istreambuf_iterator<char>(levelFile)), std::istreambuf_iterator<char>());

        levelFile.close();
        rapidjson::Document document;

        if (document.Parse(contents.c_str()).GetParseError() != rapidjson::kParseErrorNone)
        {
            throw std::runtime_error(std::string{"Failed to parse `" + fileName + "`."});
        }

        return document;
    }
    catch (std::exception&)
    {
        throw std::runtime_error(std::string{"Something went wrong handling `" + fileName + "`."});
    }
}

Level LevelController::GetLevelDto(const std::string& levelName)
{
    if (_levels.contains(levelName))
        return _levels.at(levelName);

    throw std::runtime_error(std::string{"Level `" + levelName + "` does not exist."});
}

