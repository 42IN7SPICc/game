#include "LevelScene.hpp"

#include "Api.hpp"
#include "../Utils/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"

using namespace spic;
using namespace game;

LevelScene::LevelScene(const std::string& levelName, LevelController& levelController)
{
    auto level = levelController.GetLevelDto(levelName);

    auto background = std::make_shared<spic::GameObject>("Background", "background", Layer::Background);
    GameObjectUtil::LinkComponent(background, std::make_shared<spic::Sprite>("resources/sprites/menu/backgrounds/mud.png", false, false, 0, 0));

    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1720, 100, level.Title, "resources/fonts/capture_it.otf", 35, Alignment::left, Color::white());
    titleText->Transform().position = {25, 25};

    auto tilesMapObject = levelController.GetLevelGameObject(level.File);
    tilesMapObject->Transform().position.x = 75;
    tilesMapObject->Transform().position.y = 75;

    Contents().push_back(background);
    Contents().push_back(titleText);
    Contents().push_back(tilesMapObject);
}{
    auto button = std::make_shared<spic::Button>("button-tile-" + texture, "tile_button", Layer::HUD, 32,32);
    button->Transform().scale = 4.0;
    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/tiles/" + texture, false, false, 100, 1);
    GameObjectUtil::LinkComponent(button, buttonSprite);

    button->OnClick([this, button]() mutable {
        if(_selectedButton != nullptr || _selectedButton == button) {
            auto sprites = _selectedButton->GetComponents<spic::Sprite>();
            _selectedButton->RemoveComponent(sprites[1]);
        }

        if(_selectedButton == button) { // deselect a button
            _selectedButton = nullptr;
            return;
        };

        auto selectionSprite = std::make_shared<spic::Sprite>("resources/sprites/tiles/selected.png", false, false, 100, 1);
        GameObjectUtil::LinkComponent(button, selectionSprite);
        _selectedButton = button;
    });

    GameObjectUtil::LinkChild(HUD, button);
    return button;
}
