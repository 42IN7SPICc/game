#include "LevelController.hpp"
#include "rapidjson/document.h"
#include "../Utils/StringHelper.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <exception>

using namespace game;

std::shared_ptr<spic::GameObject> LevelController::GetLevel(const std::string& fileName) {
    if (!_levels.contains(fileName)) {
        throw std::exception(std::string{"The fileName `" + fileName + "` does not exist."}.c_str());
    }

    auto level = _levels[fileName];

    // load tiles too

    std::ifstream levelFile(level.File.c_str());
    std::string contents((std::istreambuf_iterator<char>(levelFile)),
                         std::istreambuf_iterator<char>());

    levelFile.close();

}

void LevelController::InitializeLevels() {
    std::string path = "./resources/levels";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string file {entry.path().string()};

        if (StringHelper::EndsWith(file, ".json")) {
            InitializeLevel(file);
        }
    }
}


void LevelController::InitializeLevel(std::string file) {
    std::ifstream levelFile(file.c_str());
    std::string contents((std::istreambuf_iterator<char>(levelFile)),
                         std::istreambuf_iterator<char>());

    levelFile.close();

    rapidjson::Document document;
    document.Parse(contents.c_str());

    if (!document.HasMember("title"))
        throw std::exception(std::string {"The title for `" + file + "` could not be parsed"}.c_str());

    if (!document.HasMember("description"))
        throw std::exception(std::string {"The description for `" + file + "` could not be parsed"}.c_str());

    if (!document.HasMember("unlockThreshold"))
        throw std::exception(std::string {"The unlockThreshold for `" + file + "` could not be parsed"}.c_str());

    _levels.insert(std::make_pair(file.substr(0, file.size() - 5), Level {document["title"].GetString(), document["description"].GetString(), file, document["unlockThreshold"].GetInt()}));
}
