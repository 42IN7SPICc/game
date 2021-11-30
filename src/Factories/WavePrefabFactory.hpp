#ifndef SPIC_GAME_WAVEPREFABFACTORY_HPP
#define SPIC_GAME_WAVEPREFABFACTORY_HPP

#include "../Structs/WaveData.hpp"
#include <queue>

namespace game
{
    /**
     * @brief Factory for waves.
     */
    class WavePrefabFactory
    {
        public:
            /**
             * @brief Create a new wave with a given number.
             * @param waveNumber The number of the wave.
             * @return The new wave.
             */
            static WaveData GenerateWave(size_t waveNumber);

            /**
             * @brief Create a queue of waves of a given length.
             * @param count The length of the queue.
             * @return The queue of waves.
             */
            static std::queue<WaveData> GenerateWaves(size_t count);
    };
}

#endif //SPIC_GAME_WAVEPREFABFACTORY_HPP
