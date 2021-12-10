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
#include "../Factories/HealthBarFactory.hpp"
#include "LevelController.hpp"
#include <numeric>
#include "../Utils/HeroUtil.hpp"

using namespace spic;
using namespace game;

game::HUDController::HUDController(std::shared_ptr<game::LevelWithTiles> level, std::shared_ptr<LevelData> levelData, std::shared_ptr<game::HudData> hudData) : _level(std::move(level)),
                                                                                                                                                                _levelData(levelData),
                                                                                                                                                                _hudData(hudData)
{

}

void game::HUDController::CreateHudInfo (std::string name, double height, double yPosition, std::string content) {
    auto text = std::make_shared<spic::Text>(name, "default", Layer::HUD, HudWidth, height);
    text->Size(18);
    text->TextAlignment(Alignment::center);
    text->Transform().position.y = yPosition;
    text->Content(content);
    GameObjectUtil::LinkChild(_rightHud, text);
}

void game::HUDController::CreateTowerHud()
{
    auto bombShooterButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 125, "Bommenwerper", -(TileSize + 2) * (TileButtonScale * 4), BomberTowerColor<Color>());
    auto shotgunButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 100, "Shotgun", -(TileSize + 2) * (TileButtonScale * 3), ShotgunTowerColor<Color>());
    auto flamethrowerButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 150, "Vlammenwerper", -(TileSize + 2) * (TileButtonScale * 2), FlamethrowerTowerColor<Color>());
    auto sniperButton = InitializeTowerButton("resources/sprites/towers/shooting/tower_shooting_1.png", 80, "Scherpschutter", -(TileSize + 2) * (TileButtonScale * 1), SniperTowerColor<Color>());
    auto hero = _levelData->HeroHealth->GameObject().lock();
    _coolDownBehaviour = HeroUtil::GetAbilityCoolDownBehaviour(hero);

    CreateHudInfo("ability-cooldown-timer", 20, 80, "Ability Cooldown");
    CreateHudInfo("ability-cooldown-timer-text", 20, 100, std::to_string(_coolDownBehaviour->CoolDown()) + " seconden");

    CreateHudInfo("enemies-text-header", 20, 130, "Vijanden resterend:");
    CreateHudInfo("enemies-text", 20, 150, std::to_string(_levelData->Waves.front().RemainingEnemies()));

    CreateHudInfo("wave-text-header", 20, 180, "Ronde:");
    CreateHudInfo("wave-text", 20, 200, std::to_string(_levelData->CurrentWave()));

    CreateHudInfo("money-text", 20, 230, "$ " + std::to_string(_levelData->Balance));

    CreateHudInfo("military-base-health-text-header", 20, 260, "Militaire Basis:");
    auto healthBar = HealthBarFactory::CreateHealthBar(_levelData->MilitaryBaseHealth->GameObject().lock());
    healthBar->Transform().position.y = 290;
    GameObjectUtil::LinkChild(_rightHud, healthBar);

    auto nextWaveButton = ButtonPrefabFactory::CreateOutlineButton("next-wave-button", "default", "Start gevecht", true);
    auto text = std::dynamic_pointer_cast<spic::Text>(nextWaveButton->Children()[0]);
    text->Size(20);
    nextWaveButton->Transform().scale = 0.8;
    nextWaveButton->OnClick([this, nextWaveButton]() {
        if (_gameLostBehavior->IsLevelFailed()) return;

        auto& wave = _levelData->Waves.front();
        if (_levelData->LevelMode == LevelMode::TowerMode)
        {
            _levelData->LevelMode = LevelMode::WaveMode;
            auto text = std::dynamic_pointer_cast<spic::Text>(nextWaveButton->Children()[0]);
            text->Content("Volgende ronde");
            _levelData->HeroHealth->GameObject().lock()->Active(true);
        }
        if (wave.RemainingEnemies() == 0 && _levelData->LevelMode == LevelMode::WaveMode)
        {
            _levelData->Waves.pop();
            _levelData->HeroHealth->Health(_levelData->HeroHealth->MaxHealth());
        }
    });
    nextWaveButton->Transform().position.y = 350;

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
            _levelData->LevelMode = LevelMode::TowerMode;
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

    int result = std::accumulate(_hudData->ButtonTileAmounts.begin(), _hudData->ButtonTileAmounts.end(), 0, [](const int previous, const std::pair<std::shared_ptr<spic::Button>, int>& p) { return previous + p.second; });
    buttonText->Content("Tegels (" + std::to_string(result) + ")");

    return _rightHud;
}

std::shared_ptr<spic::Button> game::HUDController::InitializeTowerButton(const std::string& texture, int towerCost, const std::string& towerName, double yLocation, spic::Color color)
{
    auto button = std::make_shared<spic::Button>("tower-button-" + texture, "tower_button", Layer::HUD, TowerSpriteSize, TowerSpriteSize);
    button->Transform().scale = TowerButtonScale;
    button->Transform().position.x = -75;
    button->Transform().position.y = yLocation;

    _hudData->ButtonTowerCosts[button] = towerCost;
    button->OnClick([this, button]() {
        if (_hudData->SelectedButton == nullptr) _hudData->SelectedButton = button;
        else if (_hudData->SelectedButton == button)
        {
            _hudData->SelectedButton->Transform().rotation = 0;
            _hudData->SelectedButton = nullptr;
            return;
        }

        _hudData->SelectedButton->Transform().rotation = 0;
        button->Transform().rotation = -45;
        _hudData->SelectedButton = button;
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

    _hudData->ButtonTileAmounts[button] = tileAmount;
    button->OnClick([this, button]() {
        if (_hudData->SelectedButton != nullptr || _hudData->SelectedButton == button)
        {
            auto sprites = _hudData->SelectedButton->GetComponents<spic::Sprite>();
            _hudData->SelectedButton->RemoveComponent(sprites[1]);
        }

        if (_hudData->SelectedButton == button)
        { // deselect a button
            _hudData->SelectedButton = nullptr;
            return;
        }

        auto selectionSprite = std::make_shared<spic::Sprite>("resources/sprites/tiles/selected.png", false, false, 100, 1);
        GameObjectUtil::LinkComponent(button, selectionSprite);
        _hudData->SelectedButton = button;
    });

    GameObjectUtil::LinkChild(_rightHud, button);
    return button;
}

void HUDController::OnStart()
{
    auto parent = GameObject().lock();

    _gameLostBehavior = std::make_shared<game::GameLostBehaviour>(*_levelData);
    GameObjectUtil::LinkComponent(parent, _gameLostBehavior);
}

void HUDController::OnUpdate()
{
    for (const auto& child: _rightHud->Children())
    {
        if (child->Name() == "money-text")
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
        else if (child->Name() == "ability-cooldown-timer-text")
        {
            auto text = std::dynamic_pointer_cast<spic::Text>(child);
            if(_coolDownBehaviour->CooledDown()) {
                text->Content("ready!");
            } else {
                text->Content(std::to_string((int) _coolDownBehaviour->CoolDown() + 1) + " sec");
            }
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
