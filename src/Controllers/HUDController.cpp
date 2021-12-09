#include "HUDController.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "Text.hpp"
#include "GameObject.hpp"
#include "Color.hpp"
#include "Sprite.hpp"
#include "Debug.hpp"
#include "../Constants.hpp"
#include "../Enums/Layer.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "LevelController.hpp"
#include <numeric>

using namespace spic;
using namespace game;

game::HUDController::HUDController()
{

}

void game::HUDController::CreateTowerHud()
{
    auto bombShooterButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 125, "Bommenwerper", -(TileSize + 2) * (TileButtonScale * 4), BomberTowerColor<Color>());
    auto shotgunButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 100, "Shotgun", -(TileSize + 2) * (TileButtonScale * 3), ShotgunTowerColor<Color>());
    auto flamethrowerButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 150, "Vlammenwerper", -(TileSize + 2) * (TileButtonScale * 2), FlamethrowerTowerColor<Color>());
    auto sniperButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 80, "Scherpschutter", -(TileSize + 2) * (TileButtonScale * 1), SniperTowerColor<Color>());

    auto enemiesLeftTextHeader = std::make_shared<spic::Text>("enemies-text-header", "default", Layer::HUD, HudWidth, 20);
    enemiesLeftTextHeader->Size(18);
    enemiesLeftTextHeader->TextAlignment(Alignment::center);
    enemiesLeftTextHeader->Transform().position.y = 100;
    enemiesLeftTextHeader->Content("Vijanden resterend:");

    auto enemiesText = std::make_shared<spic::Text>("enemies-text", "default", Layer::HUD, HudWidth, 20);
    enemiesText->Size(18);
    enemiesText->TextAlignment(Alignment::center);
    enemiesText->Transform().position.y = 120;
    enemiesText->Content(std::to_string(_levelData->Waves.front().RemainingEnemies()));

    auto waveTextHeader = std::make_shared<spic::Text>("wave-text-header", "default", Layer::HUD, HudWidth, 20);
    waveTextHeader->Size(18);
    waveTextHeader->TextAlignment(Alignment::center);
    waveTextHeader->Transform().position.y = 150;
    waveTextHeader->Content("Ronde:");

    auto waveText = std::make_shared<spic::Text>("wave-text", "default", Layer::HUD, HudWidth, 20);
    waveText->Size(18);
    waveText->TextAlignment(Alignment::center);
    waveText->Transform().position.y = 170;
    waveText->Content(std::to_string(_levelData->CurrentWave()));

    auto moneyText = std::make_shared<spic::Text>("money-text", "default", Layer::HUD, HudWidth, 20);
    moneyText->Size(18);
    moneyText->TextAlignment(Alignment::center);
    moneyText->Transform().position.y = 200;
    moneyText->Content("$ " + std::to_string(_levelData->Balance));

    auto heroHealthTextHeader = std::make_shared<spic::Text>("hero-health-text-header", "default", Layer::HUD, HudWidth, 20);
    heroHealthTextHeader->Size(18);
    heroHealthTextHeader->TextAlignment(Alignment::center);
    heroHealthTextHeader->Transform().position.y = 230;
    heroHealthTextHeader->Content("Hero:");

    auto heroHealthText = std::make_shared<spic::Text>("hero-health-text", "default", Layer::HUD, HudWidth, 20);
    heroHealthText->Size(18);
    heroHealthText->TextAlignment(Alignment::center);
    heroHealthText->Transform().position.y = 250;
    heroHealthText->Content("♥ " + std::to_string(_levelData->HeroHealth->Health()));

    auto militaryBaseHealthTextHeader = std::make_shared<spic::Text>("military-base-health-text-header", "default", Layer::HUD, HudWidth, 20);
    militaryBaseHealthTextHeader->Size(18);
    militaryBaseHealthTextHeader->TextAlignment(Alignment::center);
    militaryBaseHealthTextHeader->Transform().position.y = 280;
    militaryBaseHealthTextHeader->Content("Militaire Basis:");

    auto militaryBaseHealthText = std::make_shared<spic::Text>("military-base-health-text", "default", Layer::HUD, HudWidth, 20);
    militaryBaseHealthText->Size(18);
    militaryBaseHealthText->TextAlignment(Alignment::center);
    militaryBaseHealthText->Transform().position.y = 300;
    militaryBaseHealthText->Content("♥ " + std::to_string(_levelData->MilitaryBaseHealth->Health()));

    auto nextWaveButton = ButtonPrefabFactory::CreateOutlineButton("next-wave-button", "default", "Start gevecht", true);
    auto text = std::dynamic_pointer_cast<spic::Text>(nextWaveButton->Children()[0]);
    text->Size(20);
    nextWaveButton->Transform().scale = 0.8;
    nextWaveButton->OnClick([this, nextWaveButton]() {
        if (_gameLostBehavior->IsLevelFailed())
        {
            return;
        }

        auto& wave = _levelData->Waves.front();
        if (*_levelMode == LevelMode::TowerMode)
        {
            *_levelMode = LevelMode::WaveMode;
            auto text = std::dynamic_pointer_cast<spic::Text>(nextWaveButton->Children()[0]);
            text->Content("Volgende ronde");
        }
        if (wave.RemainingEnemies() == 0 && *_levelMode == LevelMode::WaveMode)
        {
            _levelData->Waves.pop();
            _levelData->HeroHealth->Health(_levelData->HeroHealth->MaxHealth());
        }
    });
    nextWaveButton->Transform().position.y = 350;

    _levelData->HeroHealth->GameObject().lock()->Active(true);

    GameObjectUtil::LinkChild(_rightHud, enemiesLeftTextHeader);
    GameObjectUtil::LinkChild(_rightHud, enemiesText);
    GameObjectUtil::LinkChild(_rightHud, waveTextHeader);
    GameObjectUtil::LinkChild(_rightHud, waveText);
    GameObjectUtil::LinkChild(_rightHud, moneyText);
    GameObjectUtil::LinkChild(_rightHud, heroHealthTextHeader);
    GameObjectUtil::LinkChild(_rightHud, heroHealthText);
    GameObjectUtil::LinkChild(_rightHud, militaryBaseHealthTextHeader);
    GameObjectUtil::LinkChild(_rightHud, militaryBaseHealthText);
    GameObjectUtil::LinkChild(_rightHud, nextWaveButton);
}

std::shared_ptr<spic::GameObject> HUDController::CreateHUD()
{
    _rightHud = std::make_shared<spic::GameObject>("RightHud", "hud", Layer::HUD);
    auto rightHudSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/white_block.png", false, false, 3, 1);
    GameObjectUtil::LinkComponent(_rightHud, rightHudSprite);

    _rightHud->Transform().position.x = ScreenWidth - (HudWidth / 2);
    _rightHud->Transform().position.y = ScreenHeight / 2;

    auto buttonText = std::make_shared<spic::Text>("tile-title-text", "tile_title_text", Layer::HUD, HudWidth, 100);
    buttonText->Size(24);
    buttonText->TextAlignment(Alignment::center);
    buttonText->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 5);
    GameObjectUtil::LinkChild(_rightHud, buttonText);

    auto streetButton = InitializeTileButton("resources/sprites/tiles/street.png", _level->AmountsGiven.Street, "Straat", -(TileSize + 2) * (TileButtonScale * 4));
    auto grassButton = InitializeTileButton("resources/sprites/tiles/grass.png", _level->AmountsGiven.Grass, "Gras", -(TileSize + 2) * (TileButtonScale * 3));
    auto sandButton = InitializeTileButton("resources/sprites/tiles/sand.png", _level->AmountsGiven.Sand, "Zand", -(TileSize + 2) * (TileButtonScale * 2));

    auto completePathButton = ButtonPrefabFactory::CreateOutlineButton("complete-path-button", "complete_path_button", "Voltooi pad", true);
    completePathButton->Transform().scale = 0.8;

    completePathButton->OnClick([this]() {
        auto& rightHud = _rightHud;
        auto[pathCompleted, path] = game::LevelController::CheckIfPathIsComplete(_levelData->Graph);
        if (pathCompleted)
        {
            Debug::Log("Completed Correctly!!");
            *_levelMode = LevelMode::TowerMode;
            _levelData->Path = path;
            auto childrenCopy = rightHud->Children();
            for (const auto& child: childrenCopy)
            {
                rightHud->RemoveChild(child);
            }

            CreateTowerHud();
        }
        else
        {
            auto validationText = std::dynamic_pointer_cast<Text>(GameObject::Find("path-validation-text"));
            if (validationText == nullptr)
            { //Check if validation text already exists
                validationText = std::make_shared<Text>("path-validation-text", "text", Layer::HUD, 200, 100);
                validationText->Transform().position.y = (TileSize + 2) * TileButtonScale;
                validationText->TextAlignment(Alignment::center);
                validationText->TextColor(Color::red());
                GameObjectUtil::LinkChild(rightHud, validationText);
            }
            validationText->Content("Het huidige pad is niet compleet.");

        }
    });
    GameObjectUtil::LinkChild(_rightHud, completePathButton);

    int result = std::accumulate(_buttonTileAmounts.begin(), _buttonTileAmounts.end(), 0, [](const int previous, const std::pair<std::shared_ptr<spic::Button>, int>& p) { return previous + p.second; });
    buttonText->Content("Tegels (" + std::to_string(result) + ")");

    return _rightHud;
}

std::shared_ptr<spic::Button> game::HUDController::InitializeTowerButton(const std::string& texture, int towerCost, const std::string& towerName, double yLocation, spic::Color color)
{
    auto button = std::make_shared<spic::Button>("tower-button-" + texture, "tower_button", Layer::HUD, TowerSpriteSize, TowerSpriteSize);
    button->Transform().scale = TowerButtonScale;
    button->Transform().position.x = -75;
    button->Transform().position.y = yLocation;

    _buttonTowerCosts[button] = towerCost;
    button->OnClick([this, button]() {
        if (_selectedButton == nullptr) _selectedButton = button;
        else if (_selectedButton == button)
        {
            _selectedButton->Transform().rotation = 0;
            _selectedButton = nullptr;
            return;
        }

        _selectedButton->Transform().rotation = 0;
        button->Transform().rotation = -45;
        _selectedButton = button;
    });

    auto buttonSprite = std::make_shared<spic::Sprite>(texture, color, false, false, 100, 1);
    GameObjectUtil::LinkComponent(button, buttonSprite);

    auto towerNameText = std::make_shared<spic::Text>("button-name-text-" + texture, "tower_name_text", Layer::HUD, 125, TileSize);
    towerNameText->Transform().position.x = 24;
    towerNameText->Transform().position.y = yLocation - 10;
    towerNameText->Size(16);
    towerNameText->Content(towerName);
    GameObjectUtil::LinkChild(_rightHud, towerNameText);

    auto towerCostText = std::make_shared<spic::Text>("button-cost-text-" + texture, "tower_cost_text", Layer::HUD, 125, TileSize);
    towerCostText->Transform().position.x = 24;
    towerCostText->Transform().position.y = yLocation + 10;
    towerCostText->Size(16);
    towerCostText->Content("$" + std::to_string(towerCost));
    GameObjectUtil::LinkChild(_rightHud, towerCostText);

    GameObjectUtil::LinkChild(_rightHud, button);
    return button;
}

std::shared_ptr<spic::Button> game::HUDController::InitializeTileButton(const std::string& texture, int tileAmount, const std::string& tileTitle, double yLocation)
{
    auto button = std::make_shared<spic::Button>("tile-button-" + texture, "tile_button", Layer::HUD, TileSize, TileSize);
    button->Transform().position.y = yLocation;
    button->Transform().scale = TileButtonScale;
    button->Transform().position.x = -50;
    auto buttonSprite = std::make_shared<spic::Sprite>(texture, false, false, 100, 1);
    GameObjectUtil::LinkComponent(button, buttonSprite);

    auto buttonText = std::make_shared<spic::Text>("tile-button-text-" + texture, "tile_button_text", Layer::HUD, TileSize, TileSize);
    buttonText->TextAlignment(Alignment::center);
    buttonText->Content(std::to_string(tileAmount));
    buttonText->Size(18 * 4);
    GameObjectUtil::LinkChild(button, buttonText);

    auto labelText = std::make_shared<spic::Text>("button-label-text-" + texture, "tile_label_text", Layer::HUD, 100, TileSize);

    labelText->Transform().position.y = yLocation;
    labelText->Transform().position.x = TileSize * TileButtonScale + 5;
    labelText->Size(11);

    labelText->Content(tileTitle);
    GameObjectUtil::LinkChild(_rightHud, labelText);

    _buttonTileAmounts[button] = tileAmount;
    button->OnClick([this, button]() {
        if (_selectedButton != nullptr || _selectedButton == button)
        {
            auto sprites = _selectedButton->GetComponents<spic::Sprite>();
            _selectedButton->RemoveComponent(sprites[1]);
        }

        if (_selectedButton == button)
        { // deselect a button
            _selectedButton = nullptr;
            return;
        }

        auto selectionSprite = std::make_shared<spic::Sprite>("resources/sprites/tiles/selected.png", false, false, 100, 1);
        GameObjectUtil::LinkComponent(button, selectionSprite);
        _selectedButton = button;
    });

    GameObjectUtil::LinkChild(_rightHud, button);
    return button;
}

void HUDController::OnStart()
{
    //
}

void HUDController::OnUpdate()
{
    for (const auto& child: _rightHud->Children())
    {
        if (child->Name() == "hero-health-text")
        {
            auto text = std::dynamic_pointer_cast<spic::Text>(child);
            text->Content("♥ " + std::to_string(_levelData->HeroHealth->Health()));
        }
        else if (child->Name() == "military-base-health-text")
        {
            auto text = std::dynamic_pointer_cast<spic::Text>(child);
            text->Content("♥ " + std::to_string(_levelData->MilitaryBaseHealth->Health()));
        }
        else if (child->Name() == "money-text")
        {
            auto text = std::dynamic_pointer_cast<spic::Text>(child);
            text->Content("$ " + std::to_string(_levelData->Balance));
        }
        else if (child->Name() == "wave-text")
        {
            auto text = std::dynamic_pointer_cast<spic::Text>(child);
            text->Content(std::to_string(_levelData->CurrentWave()));
        }
        else if (child->Name() == "enemies-text")
        {
            auto text = std::dynamic_pointer_cast<spic::Text>(child);
            text->Content(_levelData->Waves.empty() ? "0" : std::to_string(_levelData->Waves.front().RemainingEnemies()));
        }
    }
}

void HUDController::OnTriggerEnter2D(const Collider& collider)
{
    //
}

void HUDController::OnTriggerExit2D(const Collider& collider)
{
    //
}

void HUDController::OnTriggerStay2D(const Collider& collider)
{
    //
}
