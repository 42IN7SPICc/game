#include <stdexcept>
#include "WavePrefabFactory.hpp"
#include "EnemyPrefabFactory.hpp"

game::WaveData game::WavePrefabFactory::GenerateWave(size_t waveNumber)
{
    WaveData waveData{};

    switch (waveNumber)
    {
        case 0:
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Erkunder, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Erkunder, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Erkunder, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Erkunder, true));


            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Schutze, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Schutze, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Schutze, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Schutze, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Gruppenfuhrer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Gruppenfuhrer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Gruppenfuhrer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Gruppenfuhrer, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Stabsarzt, true));
            break;

        default:
            throw std::runtime_error("This wave has not been defined.");
    }

    return waveData;
}

std::queue<game::WaveData> game::WavePrefabFactory::GenerateWaves(size_t count)
{
    std::queue<game::WaveData> result;

    for (int i = 0; i < count; ++i)
    {
        result.push(GenerateWave(i));
    }

    return result;
}
