#ifndef SPIC_GAME_HUDCONROLLER_HPP
#define SPIC_GAME_HUDCONROLLER_HPP

#include "Button.hpp"
#include "Color.hpp"
#include "../Structs/LevelData.hpp"
#include "../Structs/HudData.hpp"
#include "../Enums/LevelMode.hpp"
#include "../Scripts/Common/GameLostBehaviour.hpp"
#include "../Structs/LevelWithTiles.hpp"

namespace game
{
    class HUDController : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::LevelWithTiles> _level;
            std::shared_ptr<game::LevelData> _levelData;
            std::shared_ptr<game::HudData> _hudData;

            std::shared_ptr<spic::GameObject> _rightHud;
            std::shared_ptr<game::GameLostBehaviour> _gameLostBehavior;

            std::shared_ptr<spic::Button> InitializeTileButton(const std::string& texture, int tileAmount, const std::string& tileTitle, double yLocation);
            std::shared_ptr<spic::Button> InitializeTowerButton(const std::string& texture, int towerCost, const std::string& towerName, double yLocation, spic::Color color);
        public:
            HUDController(std::shared_ptr<game::LevelWithTiles> level, std::shared_ptr<LevelData> levelData, std::shared_ptr<game::HudData> hudData);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            std::shared_ptr<spic::GameObject> CreateHUD();

            void CreateTowerHud();
    };
}


#endif //SPIC_GAME_HUDCONROLLER_HPP
