#include "LevelData.hpp"

using namespace game;

size_t LevelData::CurrentWave() const
{
    return TotalWaves - Waves.size() + 1;
}