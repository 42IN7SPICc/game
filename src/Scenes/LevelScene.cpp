#include "LevelScene.hpp"

#include <algorithm>
#include "Api.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;

LevelScene::LevelScene(const Level& level)
{
    auto mainGameObject = std::make_shared<spic::GameObject>("LevelController", "default", Layer::Background);
    auto background = BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu);
    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1166, 100, level.Title, "resources/fonts/capture_it.otf", 35, Alignment::left, Color::white());
    titleText->Transform().position = {1366/2, 50};

    //auto tilesMapObject = levelController.GetLevelGameObject(level.File);
    //tilesMapObject->Transform().position.x = 75;
    //->Transform().position.y = 75;

    Contents().push_back(background);
    Contents().push_back(titleText);
    //Contents().push_back(tilesMapObject);

    CreateHUD();
}

std::shared_ptr<spic::Button> LevelScene::InitializeTileButton(const std::shared_ptr<GameObject>& HUD, const std::string& texture, int tileAmount, const std::string& tileTitle)
{
    auto button = std::make_shared<spic::Button>("tile-button-" + texture, "tile_button", Layer::HUD, TileSize, TileSize);
    button->Transform().scale = TileButtonScale;
    button->Transform().position.x = -50;
    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/tiles/" + texture, false, false, 100, 1);
    GameObjectUtil::LinkComponent(button, buttonSprite);

    auto buttonText = std::make_shared<spic::Text>("tile-button-text-" + texture, "tile_button_text", Layer::HUD, TileSize, TileSize);
    buttonText->TextAlignment(Alignment::center);
    buttonText->Content(std::to_string(tileAmount));
    GameObjectUtil::LinkChild(button, buttonText);

    auto labelText = std::make_shared<spic::Text>("button-label-text-" + texture, "tile_label_text", Layer::HUD, 100, TileSize);
    labelText->Transform().position.x = TileSize * TileButtonScale + 5;
    labelText->Size(11);
    labelText->Content(tileTitle);
    GameObjectUtil::LinkChild(button, labelText);

    _buttonTileAmounts[button] = tileAmount;
    button->OnClick([this, button]() mutable {
        if (_buttonTileAmounts[button] == 0) return;
        if (_selectedButton != nullptr || _selectedButton == button)
        {
            auto sprites = _selectedButton->GetComponents<spic::Sprite>();
            _selectedButton->RemoveComponent(sprites[1]);
        }

        if (_selectedButton == button)
        { // deselect a button
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

void LevelScene::CreateHUD()
{
    int screenWidth = 1366;
    int screenHeight = 786;
    int hudWidth = 250;
    int totalTileAmount = 22;

    auto rightHud = std::make_shared<GameObject>("RightHud", "hud", Layer::HUD);
    auto rightHudSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/white_block.png", false, false, 100, 1);
    GameObjectUtil::LinkComponent(rightHud, rightHudSprite);

    rightHud->Transform().position.x = screenWidth - (hudWidth / TileButtonScale);
    rightHud->Transform().position.y = screenHeight / TileButtonScale;

    auto buttonText = std::make_shared<spic::Text>("tile-title-text", "tile_title_text", Layer::HUD, hudWidth, 100);
    buttonText->Content("Tegels (" + std::to_string(totalTileAmount) + ")");
    buttonText->Size(24);
    buttonText->TextAlignment(Alignment::center);
    buttonText->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 5);
    GameObjectUtil::LinkChild(rightHud, buttonText);

    auto streetButton = InitializeTileButton(rightHud, "street.png", 0, "Straat");
    streetButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 4);

    auto grassButton = InitializeTileButton(rightHud, "grass.png", 6, "Gras");
    grassButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 3);

    auto sandButton = InitializeTileButton(rightHud, "sand.png", 6, "Zand");
    sandButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 2);

    Contents().push_back(rightHud);
    Contents().push_back(buttonText);
}