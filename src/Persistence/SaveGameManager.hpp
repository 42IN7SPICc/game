#ifndef SPIC_GAME_SAVEGAME_HPP
#define SPIC_GAME_SAVEGAME_HPP

#include "../Structs/PlayerData.hpp"
#include <string>
#include <map>

namespace game
{
    class SaveGameManager
    {
        public:
            static void Save(const PlayerData& playerData);

            static PlayerData Load(const std::string& file);

            static std::map<std::string, PlayerData> GetAll();
    };
}

#endif //SPIC_GAME_SAVEGAME_HPP
