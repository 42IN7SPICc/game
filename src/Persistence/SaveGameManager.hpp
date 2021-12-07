#ifndef SPIC_GAME_SAVEGAME_HPP
#define SPIC_GAME_SAVEGAME_HPP

#include "../Structs/PlayerData.hpp"
#include <string>
#include <map>

namespace game
{
    /**
     * @brief A manager to save and load saves.
     */
    class SaveGameManager
    {
        public:
            /**
             * @brief Save the player data to a file.
             */
            static void Save();

            /**
             * @brief Save the player data to a file.
             * @param playerData The player data to be saved.
             */
            static void Save(const PlayerData& playerData);

            /**
             * @brief Load player data from a file.
             * @param file The file to load the data from.
             * @return The player data from the file.
             */
            static PlayerData Load(const std::string& file);

            /**
             * @brief Load all saves with player data.
             * @return A list of filenames and their player data.
             */
            static std::map<std::string, PlayerData> GetAll();
    };
}

#endif //SPIC_GAME_SAVEGAME_HPP
