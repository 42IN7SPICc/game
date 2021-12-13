#ifndef SPIC_GAME_HUDCONROLLER_HPP
#define SPIC_GAME_HUDCONROLLER_HPP

#include <Text.hpp>
#include "Button.hpp"
#include "Color.hpp"
#include "../Structs/LevelData.hpp"
#include "../Structs/HudData.hpp"
#include "../Enums/LevelMode.hpp"
#include "../Scripts/Common/GameLostBehaviour.hpp"
#include "../Structs/LevelWithTiles.hpp"
#include "../Scripts/Common/CoolDownBehaviour.hpp"

namespace game
{
    /**
     * @brief A script that polls updates from other components to display them in the HUD
     */
    class HUDController : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::LevelWithTiles> _level;
            std::shared_ptr<game::LevelData> _levelData;
            std::shared_ptr<game::HudData> _hudData;

            std::shared_ptr<spic::GameObject> _rightHud;
            std::shared_ptr<game::GameLostBehaviour> _gameLostBehavior;
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;

            std::shared_ptr<spic::Button> InitializeTileButton(const std::string& texture, int tileAmount, const std::string& tileTitle, double yLocation);
            std::shared_ptr<spic::Button> InitializeTowerButton(const std::string& texture, int towerCost, const std::string& towerName, double yLocation, spic::Color color);
            void CreateHudInfo (const std::string& name, const double& height, const double& yPosition, const std::string& content);
            void CreateTowerHud();
        public:
            /**
             * @brief A constructor for the HUD controller
             * @param level The level current level data
             * @param levelData The level current level
             * @param hudData The Data the HUD shares with the LevelController
             */
            HUDController(std::shared_ptr<game::LevelWithTiles> level, std::shared_ptr<LevelData> levelData, std::shared_ptr<game::HudData> hudData);

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
             * @brief Creates a HUD game object
             * @return A HUD game object
             */
            std::shared_ptr<spic::GameObject> CreateHUD();
    };
}


#endif //SPIC_GAME_HUDCONROLLER_HPP
