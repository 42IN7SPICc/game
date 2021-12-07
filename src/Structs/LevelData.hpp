#ifndef SPIC_GAME_LEVELDATA_HPP
#define SPIC_GAME_LEVELDATA_HPP

#include "WaveData.hpp"
#include "MapNode.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include <queue>

namespace game
{
    /**
     * @brief A model for storing level data.
     */
    struct LevelData
    {
        const int LevelThreshold;
        std::shared_ptr<game::HealthBehaviour> HeroHealth;
        std::shared_ptr<game::HealthBehaviour> MilitaryBaseHealth;
        const size_t TotalWaves;
        size_t Balance;
        std::queue<WaveData> Waves;
        std::map<std::string, game::MapNode> Graph;
        std::queue<std::string> Path;

        /**
         * @brief The current wave.
         * @return The current value.
         */
        [[nodiscard]] size_t CurrentWave() const;

        /**
         * @brief Remove dead enemies from the wave.
         * @param wave The wave to remove enemies from.
         */
        void ClearDeadEnemies(WaveData& wave);
    };
}

#endif //SPIC_GAME_LEVELDATA_HPP
