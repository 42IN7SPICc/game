#ifndef SPIC_GAME_PLAYERDATA_HPP
#define SPIC_GAME_PLAYERDATA_HPP

#include <string>
#include "../Enums/HeroName.hpp"

namespace game
{
    /**
     * @brief A model for storing data about the current player.
     */
    class PlayerData
    {
        public:
            template<class Archive>
            void serialize(Archive& ar)
            {
                ar(LevelsCompleted, Balance, KillCount, HeroDeaths, MostHeroDeaths, WavesPlayed, TowersPlaced, MostTowersPlaced);
            }

            int LevelsCompleted; // used for unlock threshold
            int Balance; // amount of reichsmarken the player has
            int KillCount; // amount of enemies killed using hero or towers, for stats
            int HeroDeaths; // amount of times the player let his hero die, for stats
            int MostHeroDeaths; //  the most amount of hero deaths you have had in a level, for high scores
            int WavesPlayed; // amount of waves played, for stats
            int TowersPlaced; // amount of towers placed, for stats
            int MostTowersPlaced; // the most amount of towers you have placed in a level, for high scores
            game::HeroName SelectedHero;

            std::string File;

            /**
             * @brief Access the current instance of the Player Data
             * @return The instance of the player data.
             */
            static PlayerData& Instance();

            /**
             * @brief Set the instance of the Player Data.
             * @param playerData The new instance of the player data.
             */
            static void Instance(const PlayerData& playerData);

        private:
            static PlayerData _instance;
    };
}

#endif
