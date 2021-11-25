#include "PlayerData.hpp"

using namespace game;

PlayerData PlayerData::_instance{0, 0, 0, 0, 0};

PlayerData& PlayerData::Instance()
{
    return _instance;
}

void PlayerData::Instance(const PlayerData& playerData)
{
    _instance = playerData;
}