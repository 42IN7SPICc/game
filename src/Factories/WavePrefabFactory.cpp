#include <stdexcept>
#include "WavePrefabFactory.hpp"
#include "EnemyPrefabFactory.hpp"

game::WaveData game::WavePrefabFactory::GenerateWave(size_t waveNumber)
{
    WaveData waveData{};

    switch (waveNumber)
    {
        case 0:
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::General, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::General, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            break;

        case 1:
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Scout, true));

            waveData.EnemyQueue.emplace(3, game::EnemyPrefabFactory::CreateEnemy(EnemyName::General, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            break;

        case 2:
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));

            waveData.EnemyQueue.emplace(3, game::EnemyPrefabFactory::CreateEnemy(EnemyName::General, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            break;

        case 3:
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(1, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::General, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));

            waveData.EnemyQueue.emplace(3, game::EnemyPrefabFactory::CreateEnemy(EnemyName::General, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Soldier, true));
            waveData.EnemyQueue.emplace(0.2, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));

            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::InfantryTransport, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Sniper, true));
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Healer, true));
            break;
        case 4:
            waveData.EnemyQueue.emplace(0.5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(15, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(15, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
            waveData.EnemyQueue.emplace(5, game::EnemyPrefabFactory::CreateEnemy(EnemyName::Tank, true));
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
        result.push(GenerateWave(4));
    }

    return result;
}
