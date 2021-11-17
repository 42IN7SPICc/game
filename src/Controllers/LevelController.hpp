#ifndef SPIC_GAME_LEVELCONTROLLER_HPP
#define SPIC_GAME_LEVELCONTROLLER_HPP

#include <map>
#include <string>

#include "BehaviourScript.hpp"
#include "rapidjson/document.h"
#include "../Structs/Level.hpp"

namespace game {
    class LevelController : spic::BehaviourScript {
    public:
        void InitializeLevels();
        std::shared_ptr<spic::GameObject> GetLevelGameObject(const std::string& fileName);
        Level GetLevelDto(const std::string& levelName);
    private:
        void InitializeLevel(const std::string& file, const std::string& name);
        rapidjson::Document LoadFile(const std::string& fileName);
        std::map<std::string, Level> _levels{};
    };
}


#endif
