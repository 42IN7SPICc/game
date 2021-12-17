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
#include "../Structs/HudData.hpp"
#include "../Enums/LevelMode.hpp"
#include "../Scripts/Common/GameLostBehaviour.hpp"
#include "HUDController.hpp"

namespace game
{
    /**
     * @brief A controller to handle changes in the Level.
     */
    class LevelController : public spic::BehaviourScript
    {
        private:
            spic::Point _startPosition;
            std::shared_ptr<game::LevelWithTiles> _level;
            std::shared_ptr<game::LevelData> _levelData;
            std::shared_ptr<game::HudData> _hudData;

            double _timePassed;
            bool _strongPathEnabled;
            bool _noCoolDown;

            void HandleClickTile(const game::MapNode& clickedTile);
            void HandleClickTower(game::MapNode& clickedTile);
        public:
            /**
             * @brief Constructs a new instance of a LevelController with given settings.
             * @param level The data of the current level.
             * @param heroHealth The health of the hero.
             * @param militaryBaseHealth The health of the end point.
             * @param waves The waves of the level.
             * @param levelData The data object of the current level
             * @param hudData The shared data with the HUD controller
             */
            LevelController(std::shared_ptr<game::LevelWithTiles> level, std::shared_ptr<game::HealthBehaviour> heroHealth, std::shared_ptr<game::HealthBehaviour> militaryBaseHealth, std::queue<game::WaveData> waves, std::shared_ptr<game::LevelData> levelData, std::shared_ptr<game::HudData> hudData);

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
             * @param animator The animator for the end tile.
             * @return The game object containing the level.
             */
            std::shared_ptr<spic::GameObject> BuildLevel(const std::shared_ptr<game::HealthBehaviour>& endTowerHealthBehaviour, const std::shared_ptr<spic::Animator>& animator);

            /**
             * @brief Builds the in world colliders to prevent the hero and enemies of walking on non walkable tiles.
             * @param levelData the level data to build the colliders for
             */
            static void InitializeWorldColliders(const game::LevelData& levelData);

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

            /**
             * @brief Add an enemy to the current wave.
             * @param enemy The enemy to add to the wave.
             */
            void AddEnemyToWave(const std::shared_ptr<spic::GameObject>& enemy);

            /**
             * @brief Whether the a given tile is walkable.
             * @param tileType The type of the tile to check.
             * @param isHero If the entity is a hero, false meaning he is an enemy.
             * @return Whether the tile is walkable.
             */
            static bool Walkable(const TileType& tileType, bool isHero = true);

            /**
             * @brief Generate a border for the level with given settings.
             * @param x The X position of the border.
             * @param y The Y position of the border.
             * @param width The width of the border.
             * @param height The height of the border.
             * @return A game object containing a border.
             */
            static std::shared_ptr<spic::GameObject> CreateLevelBorder(double x, double y, double width, double height);

            /**
             * @brief Check if there is a path from the start tile to the end tile
             * @param graphCopy A graph with all the map tiles
             * @return a bool if the path is complete and a queue with the path follow instructions
             */
            static std::tuple<bool, std::queue<std::string>> CheckIfPathIsComplete(std::map<std::string, MapNode> graphCopy);

            /**
             * @brief Toggle the infinite cooldown cheat
             */
            void ToggleInfiniteCoolDown();
    };
}

#endif
