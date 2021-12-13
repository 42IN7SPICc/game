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
            /**
             * @brief empty PlayerData constructor used for JSON parsing etc.
             */
            PlayerData();

            /**
             * @brief PlayerData constructor
             * @param levelsCompleted used for unlock threshold
             * @param balance amount of reichsmarken the player has
             * @param killCount amount of enemies killed using hero or towers, for stats
             * @param heroDeaths amount of times the player let his hero die, for stats
             * @param mostHeroDeaths the most amount of hero deaths you have had in a level, for high scores
             * @param wavesPlayed amount of waves played, for stats
             * @param towersPlaced amount of towers placed, for stats
             * @param mostTowersPlaced the most amount of towers you have placed in a level, for high scores
             */
            PlayerData(int levelsCompleted, int balance, int killCount, int heroDeaths, int mostHeroDeaths, int wavesPlayed, int towersPlaced, int mostTowersPlaced);

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

            /**
             * @warning DO NOT USE! This class should be used as a singleton throughout the codebase
             * @brief Default copy constructor
             * @param data data to copy
             */
            PlayerData(const PlayerData& data) = default;

        private:
            /**
             * @brief Copy assignment operator
             * @param data data to copy
             * @return reference to new data object
             */
            PlayerData& operator=(const PlayerData& data) = default;

            static PlayerData _instance;
    };
}

#endif
