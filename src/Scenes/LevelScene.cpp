#include "LevelScene.hpp"

#include <algorithm>
#include "Api.hpp"
#include "../Utils/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"

using namespace spic;
using namespace game;

LevelScene::LevelScene(const std::string& levelName, LevelController& levelController)
{
    auto level = levelController.GetLevelDto(levelName);

    auto background = BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu);
    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1720, 100, level.Title, "resources/fonts/capture_it.otf", 35, Alignment::left, Color::white());
    titleText->Transform().position = {25, 25};

    auto tilesMapObject = levelController.GetLevelGameObject(level.File);
    //tilesMapObject->Transform().position.x = 75;
    //->Transform().position.y = 75;

    Contents().push_back(background);
    Contents().push_back(titleText);
    //Contents().push_back(tilesMapObject);

    int width = 1366;
    int height = 786;
    int hudWidth = 250;

    auto rightHud = std::make_shared<GameObject>("RightHud", "hud", Layer::HUD);
    auto rightHudSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/white_block.png", false, false, 100, 1);
    GameObjectUtil::LinkComponent(rightHud, rightHudSprite);

    rightHud->Transform().position.x = width - (hudWidth / 2.0);
    rightHud->Transform().position.y = height / 2.0;

    auto streetButton = InitializeTileButton(rightHud, "street.png");
    streetButton->Transform().position.y = -34 * 4;

    auto grassButton = InitializeTileButton(rightHud, "grass.png");
    grassButton->Transform().position.y = 0;

    auto sandButton = InitializeTileButton(rightHud, "sand.png");
    sandButton->Transform().position.y = 34 * 4;

    Contents().push_back(rightHud);
}

std::shared_ptr<spic::Button> LevelScene::InitializeTileButton(const std::shared_ptr<GameObject>& HUD, const std::string& texture)
{
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
