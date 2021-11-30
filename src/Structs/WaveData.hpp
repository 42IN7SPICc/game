#ifndef SPIC_GAME_WAVEDATA_HPP
#define SPIC_GAME_WAVEDATA_HPP

#include <map>
#include <memory>
#include <queue>
#include <GameObject.hpp>

namespace game
{
    /**
     * @brief A model for storing about the wave.
     */
    struct WaveData
    {
        // size_t is in milliseconds between spawning the enemy
        std::queue<std::tuple<double, std::shared_ptr<spic::GameObject>>> EnemyQueue;
        std::vector<std::shared_ptr<spic::GameObject>> CurrentEnemies;

        /**
         * @brief Fetch all the remaining enemies in the wave.
         * @return The amount of enemies remaining.
         */
        [[nodiscard]] size_t RemainingEnemies() const;
    };
}

#endif //SPIC_GAME_WAVEDATA_HPP
