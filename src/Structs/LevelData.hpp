#ifndef SPIC_GAME_LEVELDATA_HPP
#define SPIC_GAME_LEVELDATA_HPP

#include "WaveData.hpp"
#include "MapNode.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include <queue>

namespace game
{
    struct LevelData
    {
        std::shared_ptr<HealthBehaviour> HeroHealth;
        std::shared_ptr<HealthBehaviour> MilitaryBaseHealth;
        const size_t TotalWaves;
        size_t Balance;
        std::queue<WaveData> Waves;
        std::map<std::string, MapNode> Graph {};

        [[nodiscard]] size_t CurrentWave() const;
    };
}

#endif //SPIC_GAME_LEVELDATA_HPP
