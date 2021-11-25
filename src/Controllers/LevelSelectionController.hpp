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

            [[nodiscard]] LevelWithTiles LoadLevel(const std::string& file) const;

            [[nodiscard]] Level GetLevelDto(const std::string& levelName) const;

        private:
            std::map<std::string, Level> _levels{};
    };
}


#endif
