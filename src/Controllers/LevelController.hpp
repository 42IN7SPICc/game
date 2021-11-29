#ifndef SPIC_GAME_LEVELCONTROLLER_HPP
#define SPIC_GAME_LEVELCONTROLLER_HPP

#include <map>
#include <vector>
#include <memory>
#include <string>

#include "BehaviourScript.hpp"
#include "Button.hpp"
#include "GameObject.hpp"
#include "../Structs/LevelWithTiles.hpp"
#include "../Structs/LevelData.hpp"
#include "../Enums/LevelMode.hpp"

namespace game
{
    class LevelController : public spic::BehaviourScript
    {
        public:
            LevelController(game::LevelWithTiles level, std::shared_ptr<game::HealthBehaviour> heroHealth, std::shared_ptr<game::HealthBehaviour> militaryBaseHealth, std::queue<game::WaveData> waves);

            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            std::shared_ptr<spic::GameObject> BuildLevel(const std::shared_ptr<game::HealthBehaviour>& endTowerHealthBehaviour);

            std::shared_ptr<spic::GameObject> CreateHUD();

            std::shared_ptr<spic::GameObject> CreateMapButton();

            void SetUnlimitedPath();

            void SetStrongPath();

            void SetUnlimitedMoney();

            std::map<std::string, MapNode>& GetGraph();
        private:
            const game::LevelWithTiles _level;
            game::LevelData _levelData;
            std::shared_ptr<spic::Button> _selectedButton;
            std::shared_ptr<spic::GameObject> _rightHud;
            std::map<std::shared_ptr<spic::Button>, int> _buttonTileAmounts;
            game::LevelMode _levelMode;
            bool _strongPathEnabled;

            std::shared_ptr<spic::Button> InitializeTileButton(const std::shared_ptr<spic::GameObject>& HUD, const std::string& texture, int tileAmount, const std::string& tileTitle);

            void HandleClickTile(const game::MapNode& clickedTile);

            void HandleClickTower(game::MapNode& clickedTile);

            static bool CheckIfPathIsComplete(std::map<std::string, MapNode> graphCopy);
    };
}

#endif
