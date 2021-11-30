#include "LevelData.hpp"

using namespace game;

size_t LevelData::CurrentWave() const
{
    return TotalWaves - Waves.size() + 1;
}

void LevelData::ClearDeadEnemies(WaveData& wave)
{
    std::erase_if(wave.CurrentEnemies, [this](const std::shared_ptr<spic::GameObject>& enemy) {
        if (enemy->GetComponent<HealthBehaviour>()->Health() <= 0)
        {
            Balance += 50; //TODO Different value for different enemies?
            return true;
        }
        return false;
    });
}