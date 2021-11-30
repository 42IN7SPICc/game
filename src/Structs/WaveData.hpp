#ifndef SPIC_GAME_WAVEDATA_HPP
#define SPIC_GAME_WAVEDATA_HPP

#include <map>
#include <memory>
#include <queue>
#include <GameObject.hpp>

namespace game
{
    struct WaveData
    {
        // size_t is in milliseconds between spawning the enemy
        std::queue<std::tuple<double, std::shared_ptr<spic::GameObject>>> EnemyQueue;
        std::vector<std::shared_ptr<spic::GameObject>> CurrentEnemies;

        [[nodiscard]] size_t RemainingEnemies() const;
    };
}

#endif //SPIC_GAME_WAVEDATA_HPP
