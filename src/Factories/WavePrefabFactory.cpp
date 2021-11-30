#include <stdexcept>
#include "WavePrefabFactory.hpp"
#include "EnemyPrefabFactory.hpp"

game::WaveData game::WavePrefabFactory::GenerateWave(size_t waveNumber)
{
    WaveData waveData{};

    switch (waveNumber)
    {
        case 0:
            for (int i = 0; i < 5; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));

            for (int i = 0; i < 4; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }
            break;
        case 1:
            for (int i = 0; i < 10; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));

            for (int i = 0; i < 9; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }
            break;
        case 2:
            for (int i = 0; i < 15; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));

            for (int i = 0; i < 14; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }
            break;
        case 3:
            for (int i = 0; i < 15; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));

            for (int i = 0; i < 14; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }
            break;
        case 4:
            for (int i = 0; i < 15; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));

            for (int i = 0; i < 14; ++i)
            {
                waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Panzer));
            }
            break;
        default:
            throw std::runtime_error("This wave has not been defined");
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
