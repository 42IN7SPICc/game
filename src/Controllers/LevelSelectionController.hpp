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
    /**
     * @brief A script to handle level loading and selection.
     */
    class LevelSelectionController : spic::BehaviourScript
    {
        public:
            /**
             * @brief Initialize all level to use in the game.
             */
            void InitializeLevels();

            /**
             * @brief Load a level with a given file path.
             * @param file The path to the level file.
             * @return The object containing level data.
             */
            [[nodiscard]] LevelWithTiles LoadLevel(const std::string& file) const;

            /**
             * @brief Get level information by a given level name.
             * @param levelName The name of the level.
             * @return The data of the level.
             */
            [[nodiscard]] Level GetLevelDto(const std::string& levelName) const;

            /**
             * @brief Get all levels with information (without tiles)
             * @param unlockThreshold Weither to use the player's data (false returning all levels, true only the ones he may play)
             * @return Vector of levels.
             */
            [[nodiscard]] std::vector<Level> GetLevels(const bool unlockThreshold = false) const;

        private:
            std::map<std::string, Level> _levels{};
    };
}


#endif
