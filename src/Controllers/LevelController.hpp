#ifndef SPIC_GAME_LEVELCONTROLLER_HPP
#define SPIC_GAME_LEVELCONTROLLER_HPP

#include <map>
#include <string>
#include "BehaviourScript.hpp"
#include "../Structs/Level.hpp"

namespace game {
    class LevelController : spic::BehaviourScript {
    public:
        void InitializeLevels();
        std::shared_ptr<spic::GameObject> GetLevel(const std::string& fileName);
    private:
        void InitializeLevel(std::string file);
        std::map<std::string, Level> _levels{};
    };
}


#endif
