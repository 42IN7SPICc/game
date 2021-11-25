#ifndef SPIC_GAME_LEVELSELECTIONCONTROLLER_HPP
#define SPIC_GAME_LEVELSELECTIONCONTROLLER_HPP

#include <map>
#include <string>

#include "BehaviourScript.hpp"
#include "../Structs/Level.hpp"
#include "../Structs/LevelWithTiles.hpp"
#include "../Structs/Tile.hpp"

namespace game
{
    class LevelSelectionController : spic::BehaviourScript
    {
        public:
            void InitializeLevels();

            LevelWithTiles LoadLevel(const std::string& file);

            Level GetLevelDto(const std::string& levelName);

        private:
            void InitializeLevel(const std::string& file, const std::string& name);

            static std::string LoadFile(const std::string& fileName);

            std::map<std::string, Level> _levels{};
    };
}


#endif
