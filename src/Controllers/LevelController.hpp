#ifndef SPIC_GAME_LEVELCONTROLLER_HPP
#define SPIC_GAME_LEVELCONTROLLER_HPP

#include <map>
#include <vector>
#include <memory>
#include <string>

#include "BehaviourScript.hpp"
#include "../Structs/Level.hpp"
#include "../Structs/LevelData.hpp"

namespace game
{
    class LevelController : public spic::BehaviourScript
    {
        public:
            LevelController(game::Level level, std::shared_ptr<game::HealthBehaviour> heroHealth, std::shared_ptr<game::HealthBehaviour> militaryBaseHealth, std::queue<game::WaveData> waves);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

        private:
            const game::Level _level;
            game::LevelData _levelData;
    };
}

#endif
