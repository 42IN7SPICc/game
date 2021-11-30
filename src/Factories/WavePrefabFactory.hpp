#ifndef SPIC_GAME_WAVEPREFABFACTORY_HPP
#define SPIC_GAME_WAVEPREFABFACTORY_HPP

#include "../Structs/WaveData.hpp"
#include <queue>

namespace game
{
    class WavePrefabFactory
    {
        public:
            static WaveData GenerateWave(size_t waveNumber);

            static std::queue<WaveData> GenerateWaves(size_t count);
    };
}

#endif //SPIC_GAME_WAVEPREFABFACTORY_HPP
