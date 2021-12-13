#include "LevelData.hpp"
#include "../Scripts/Enemies/EnemyValue.hpp"
#include "../Scripts/Enemies/EnemyTroopTruckBehaviour.hpp"
#include "PlayerData.hpp"

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

        auto troopTruck = enemy->GetComponent<EnemyTroopTruckBehaviour>();
        if (enemy->GetComponent<HealthBehaviour>()->Health() <= 0 && (!troopTruck || troopTruck->Spawned()))
        {
            Balance += enemy->GetComponent<EnemyValue>()->Value();
            PlayerData::Instance().KillCount += 1;
            return true;
        }
        return false;
    });
}