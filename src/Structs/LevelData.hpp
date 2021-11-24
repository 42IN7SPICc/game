#ifndef SPIC_GAME_LEVELDATA_HPP
#define SPIC_GAME_LEVELDATA_HPP

#include "WaveData.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include <queue>

namespace game
{
    struct LevelData
    {
        std::shared_ptr<game::HealthBehaviour> HeroHealth;
        std::shared_ptr<game::HealthBehaviour> MilitaryBaseHealth;
        const size_t TotalWaves;
        size_t Balance;
        std::queue<WaveData> Waves;

        [[nodiscard]] size_t CurrentWave() const;
    };
}

#endif //SPIC_GAME_LEVELDATA_HPP
