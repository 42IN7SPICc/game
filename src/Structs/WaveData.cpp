#include "WaveData.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"

using namespace game;

size_t WaveData::RemainingEnemies() const
{
    return EnemyQueue.size() + CurrentEnemies.size();
}

void WaveData::ClearDeadEnemies()
{
    std::erase_if(CurrentEnemies, [](std::shared_ptr<spic::GameObject> enemy) {
        if (enemy->GetComponent<HealthBehaviour>()->Health() > 0) return false;
        spic::GameObject::Destroy(enemy);
        return true;
    });
}
