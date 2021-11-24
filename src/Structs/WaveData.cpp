#include "WaveData.hpp"
using namespace game;

size_t WaveData::RemainingEnemies() const
{
    return EnemyQueue.size() + CurrentEnemies.size();
}