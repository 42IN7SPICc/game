#include "WaveData.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"

using namespace game;

size_t WaveData::RemainingEnemies() const
{
    return EnemyQueue.size() + CurrentEnemies.size();
}

void WaveData::ClearDeadEnemies()
{
    std::erase_if(CurrentEnemies, [](const std::shared_ptr<spic::GameObject>& enemy) {
        return enemy->GetComponent<HealthBehaviour>()->Health() <= 0;
    });
}
