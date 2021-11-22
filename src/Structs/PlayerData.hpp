#ifndef SPIC_GAME_PLAYERDATA_HPP
#define SPIC_GAME_PLAYERDATA_HPP

namespace game
{
    struct PlayerData
    {
        int LevelsCompleted; // used for unlock threshold
        int Balance; // amount of reichsmarken the player has
        int KillCount; // amount of enemies killed using hero or towers, for stats
        int HeroDeathCount; // amount of times the player let his hero die, for stats
        int WavesPlayed; // amount of waves played, for stats
    };
}

#endif
