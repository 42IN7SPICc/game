#include "LevelData.hpp"
#include "../Constants.hpp"
#include "../Scripts/Enemies/EnemyValue.hpp"

using namespace game;

size_t LevelData::CurrentWave() const
{
    return TotalWaves - Waves.size() + 1;
}

void LevelData::ClearDeadEnemies(WaveData& wave)
{
    std::erase_if(wave.CurrentEnemies, [this](const std::shared_ptr<spic::GameObject>& enemy) {
        if (!enemy || enemy.use_count() <= 1)
        {
            // Delete if the enemy is no longer being referenced to from the scene
            return true;
        }
        if (enemy->GetComponent<HealthBehaviour>()->Health() <= 0)
        {
            Balance += enemy->GetComponent<EnemyValue>()->Value();
            return true;
        }
        return false;
    });
}