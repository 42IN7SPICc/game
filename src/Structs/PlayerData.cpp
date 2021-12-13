#include "PlayerData.hpp"

using namespace game;

PlayerData PlayerData::_instance{0, 0, 0, 0, 0, 0, 0, 0};

PlayerData& PlayerData::Instance()
{
    return _instance;
}

void PlayerData::Instance(const PlayerData& playerData)
{
    _instance = playerData;
}

PlayerData::PlayerData() : PlayerData(0, 0, 0, 0, 0, 0, 0, 0)
{

}

PlayerData::PlayerData(int levelsCompleted, int balance, int killCount, int heroDeaths, int mostHeroDeaths, int wavesPlayed, int towersPlaced, int mostTowersPlaced) : LevelsCompleted(levelsCompleted),
                                                                                                                                                                       Balance(balance),
                                                                                                                                                                       KillCount(killCount),
                                                                                                                                                                       HeroDeaths(heroDeaths),
                                                                                                                                                                       MostHeroDeaths(mostHeroDeaths),
                                                                                                                                                                       WavesPlayed(wavesPlayed),
                                                                                                                                                                       TowersPlaced(towersPlaced),
                                                                                                                                                                       MostTowersPlaced(mostTowersPlaced),
                                                                                                                                                                       SelectedHero()
{

}
