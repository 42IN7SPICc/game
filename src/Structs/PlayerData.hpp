#ifndef SPIC_GAME_PLAYERDATA_HPP
#define SPIC_GAME_PLAYERDATA_HPP

#include <string>

namespace game
{
    struct PlayerData
    {
        template<class Archive>
        void serialize(Archive& ar)
        {
            ar(LevelsCompleted, Balance, KillCount, HeroDeathCount, WavesPlayed);
        }

        int LevelsCompleted; // used for unlock threshold
        int Balance; // amount of reichsmarken the player has
        int KillCount; // amount of enemies killed using hero or towers, for stats
        int HeroDeathCount; // amount of times the player let his hero die, for stats
        int WavesPlayed; // amount of waves played, for stats

        std::string File;

        static PlayerData& Instance();
        static void Instance(const PlayerData& playerData);

        private:
            static PlayerData _instance;
    };
}

#endif
