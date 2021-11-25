#ifndef SPIC_GAME_LEVELMANAGER_HPP
#define SPIC_GAME_LEVELMANAGER_HPP

#include "../Structs/LevelWithTiles.hpp"
#include "../Structs/Level.hpp"
#include <string>
#include <map>

namespace game
{
    class LevelManager
    {
        public:
            static LevelWithTiles LoadLevelWithTiles(const std::string& file);
            static Level LoadLevel(const std::string& file);

            static std::map<std::string, Level> GetAll();
    };
}

#endif //SPIC_GAME_LEVELMANAGER_HPP
