#ifndef SPIC_GAME_LEVELCONTROLLER_HPP
#define SPIC_GAME_LEVELCONTROLLER_HPP

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <tuple>
#include <stack>

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

            /**
             * @brief Triggers when the scripts starts for the first time.
             */
            void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;

            /**
             * @brief Triggers when the script collides with a collider.
             * @param collider The collider that collided.
             */
            void OnTriggerEnter2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers when the script stopped colliding with a collider.
             * @param collider The collider that stop colliding.
             */
            void OnTriggerExit2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers while an collider is colliding with a collider.
             * @param collider The collider is colliding.
             */
            void OnTriggerStay2D(const spic::Collider& collider) override;

            std::shared_ptr<spic::GameObject> BuildLevel(const std::shared_ptr<game::HealthBehaviour>& endTowerHealthBehaviour);

            std::shared_ptr<spic::GameObject> CreateHUD();

            std::shared_ptr<spic::GameObject> CreateMapButton();

            void SetUnlimitedPath();

            void SetStrongPath();

            void SetUnlimitedMoney();

            void SetInvincibility() const;

            std::map<std::string, MapNode>& GetGraph();

            std::queue<std::string> GetPath() const;
            
            void ButcherEnemies();

        private:
            spic::Point _startPosition;
            double _timePassed;
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

            static std::tuple<bool, std::queue<std::string>> CheckIfPathIsComplete(std::map<std::string, MapNode> graphCopy);
    };
}

#endif
