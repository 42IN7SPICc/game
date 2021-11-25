#ifndef SPIC_GAME_LEVELSCENE_HPP
#define SPIC_GAME_LEVELSCENE_HPP

#include <map>
#include "Scene.hpp"
#include "Button.hpp"
#include "../Structs/LevelWithTiles.hpp"
#include "../Controllers/LevelSelectionController.hpp"
#include "../Controllers/SaveGameController.hpp"

namespace game
{
    class LevelScene : public spic::Scene
    {
        private:
            std::shared_ptr<spic::GameObject> BuildLevel(const LevelWithTiles &level);
            std::shared_ptr<spic::Button> _selectedButton;
            std::map<std::shared_ptr<spic::Button>, int> _buttonTileAmounts;

            std::shared_ptr<spic::Button> InitializeTileButton(const std::shared_ptr<spic::GameObject>& HUD, const std::string& texture, int tileAmount, const std::string& tileTitle);

            void CreateHUD();

        public:
            explicit LevelScene(const LevelWithTiles& level);
    };
}


#endif