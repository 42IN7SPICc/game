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
    /**
     * @brief A controller to handle changes in the Level.
     */
    class LevelController : public spic::BehaviourScript
    {
        public:
            /**
             * @brief Constructs a new instance of a LevelController with given settings.
             * @param level The data of the current level.
             * @param heroHealth The health of the hero.
             * @param militaryBaseHealth The health of the end point.
             * @param waves The waves of the level.
             */
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

            /**
             * @brief Builds a level with a given health for the end tower.
             * @param endTowerHealthBehaviour The health of the end tower.
             * @return The game object containing the level.
             */
            std::shared_ptr<spic::GameObject> BuildLevel(const std::shared_ptr<game::HealthBehaviour>& endTowerHealthBehaviour);

            /**
             * @brief Creates a HUD for the level.
             * @return The game object containing the hud.
             */
            std::shared_ptr<spic::GameObject> CreateHUD();

            /**
             * @brief Creates a button for the map.
             * @return The game object containing the button.
             */
            std::shared_ptr<spic::GameObject> CreateMapButton();

            /**
             * @brief The cheat for unlimited path tiles.
             */
            void SetUnlimitedPath();

            /**
             * @brief The cheat to allow path tiles everywhere.
             */
            void SetStrongPath();

            /**
             * @brief The cheat for unlimited money.
             */
            void SetUnlimitedMoney();

            /**
             * @brief The cheat for an invincible hero.
             */
            void SetInvincibility() const;

            /**
             * @brief The cheat for skipping a wave.
             */
            void SkipWave();

            /**
             * @brief Get the graph containing all map nodes based on the location.
             * @return The map with nodes and their location.
             */
            std::map<std::string, MapNode>& GetGraph();

            /**
             * @brief Get the path for enemies to walk on.
             * @return The path to walk on.
             */
            [[nodiscard]] std::queue<std::string> GetPath() const;

            /**
             * @brief Remove all the dead enemies from the current wave.
             */
            void ButcherEnemies();

            [[nodiscard]] game::LevelMode GetLevelMode() const;
        private:
            spic::Point _startPosition;
            double _timePassed;
            const game::LevelWithTiles _level;
            game::LevelData _levelData;
            std::shared_ptr<spic::Button> _selectedButton;
            std::shared_ptr<spic::GameObject> _rightHud;
            std::map<std::shared_ptr<spic::Button>, int> _buttonTileAmounts;
            std::map<std::shared_ptr<spic::Button>, int> _buttonTowerCosts;
            game::LevelMode _levelMode;
            bool _strongPathEnabled;


            std::shared_ptr<spic::Button> InitializeTileButton(const std::string& texture, int tileAmount, const std::string& tileTitle, double yLocation);

            std::shared_ptr<spic::Button> InitializeTowerButton(const std::string& texture, int towerCost, const std::string& towerName, double yLocation, spic::Color color);

            void HandleClickTile(const game::MapNode& clickedTile);

            void HandleClickTower(game::MapNode& clickedTile);

            static std::tuple<bool, std::queue<std::string>> CheckIfPathIsComplete(std::map<std::string, MapNode> graphCopy);

            void CreateTowerHud();
    };
}

#endif
