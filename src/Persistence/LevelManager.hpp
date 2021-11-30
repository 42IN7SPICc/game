#ifndef SPIC_GAME_LEVELMANAGER_HPP
#define SPIC_GAME_LEVELMANAGER_HPP

#include "../Structs/LevelWithTiles.hpp"
#include "../Structs/Level.hpp"
#include <string>
#include <map>

namespace game
{
    /**
     * @brief Manager for loading Levels with or without tiles.
     */
    class LevelManager
    {
        public:
            /**
             * @brief Load a level including the tiles.
             * @param file The file to load.
             * @return A level with tiles.
             */
            static LevelWithTiles LoadLevelWithTiles(const std::string& file);

            /**
             * @brief Load a level without tiles.
             * @param file The file to load.
             * @return A level without tiles.
             */
            static Level LoadLevel(const std::string& file);

            /**
             * @brief Load all levels without tiles.
             * @return A list of filenames and the matching level.
             */
            static std::map<std::string, Level> GetAll();
    };
}

#endif //SPIC_GAME_LEVELMANAGER_HPP
