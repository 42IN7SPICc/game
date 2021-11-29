#include "Api.hpp"
#include "LevelController.hpp"
#include "../Scripts/Common/GameWonBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/TileUtil.hpp"
#include "../Scripts/Common/GameLostBehaviour.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include <numeric>
#include <cmath>
#include <vector>

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;
const double TileMapScale = 0.8;
const int ScreenWidth = 1366;
const int ScreenHeight = 786;
const int HudWidth = 250;
const int MapX = 75;
const int MapY = 110;

void LevelController::OnStart()
{
    auto parent = GameObject().lock();

    auto gameWonBehaviour = std::make_shared<game::GameWonBehaviour>(_levelData);
    GameObjectUtil::LinkComponent(parent, gameWonBehaviour);

    auto gameLostBehaviour = std::make_shared<game::GameLostBehaviour>(_levelData);
    GameObjectUtil::LinkComponent(parent, gameLostBehaviour);
}

void LevelController::OnUpdate()
{
    auto parent = GameObject().lock();
    for (const auto& child: parent->Children())
    {
        if (child->Name() == "hero-health-text")
        {
            child->GetComponent<Text>()->Content("♥ " + std::to_string(_levelData.HeroHealth->Health()));
        }
        else if (child->Name() == "military-base-health-text")
        {
            child->GetComponent<Text>()->Content("♥ " + std::to_string(_levelData.MilitaryBaseHealth->Health()));
        }
        else if (child->Name() == "money-text")
        {
            child->GetComponent<Text>()->Content("$ " + std::to_string(_levelData.Balance));
        }
    }
}

void LevelController::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void LevelController::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void LevelController::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

LevelController::LevelController(game::LevelWithTiles level, std::shared_ptr<game::HealthBehaviour> heroHealth, std::shared_ptr<game::HealthBehaviour> militaryBaseHealth, std::queue<game::WaveData> waves) : _level(std::move(level)),
                                                                                                                                                                                                               _levelData(game::LevelData{
                                                                                                                                                                                                                       std::move(heroHealth),
                                                                                                                                                                                                                       std::move(militaryBaseHealth),
                                                                                                                                                                                                                       waves.size(), // Total waves
                                                                                                                                                                                                                       500,
                                                                                                                                                                                                                       std::move(waves)
                                                                                                                                                                                                               }),
                                                                                                                                                                                                               _levelMode(LevelMode::TileMode),
                                                                                                                                                                                                               _strongPathEnabled(false)
{
}

std::shared_ptr<spic::GameObject> LevelController::CreateHUD()
{
    auto rightHud = std::make_shared<spic::GameObject>("RightHud", "hud", Layer::HUD);
    auto rightHudSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/white_block.png", false, false, 3, 1);
    GameObjectUtil::LinkComponent(rightHud, rightHudSprite);

    rightHud->Transform().position.x = ScreenWidth - (HudWidth / TileButtonScale);
    rightHud->Transform().position.y = ScreenHeight / TileButtonScale;

    auto buttonText = std::make_shared<spic::Text>("tile-title-text", "tile_title_text", Layer::HUD, HudWidth, 100);
    buttonText->Size(24);
    buttonText->TextAlignment(Alignment::center);
    buttonText->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 5);
    GameObjectUtil::LinkChild(rightHud, buttonText);

    auto streetButton = InitializeTileButton(rightHud, "resources/sprites/tiles/street.png", 18, "Straat");
    streetButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 4);

    auto grassButton = InitializeTileButton(rightHud, "resources/sprites/tiles/grass.png", 6, "Gras");
    grassButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 3);

    auto sandButton = InitializeTileButton(rightHud, "resources/sprites/tiles/sand.png", 6, "Zand");
    sandButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 2);

    auto completePathButton = ButtonPrefabFactory::CreateOutlineButton("complete-path-button", "complete_path_button", "Finish Path", true);
    completePathButton->Transform().scale = 0.8;
    completePathButton->OnClick([this, rightHud]() {
        bool pathCompleted = CheckIfPathIsComplete();
        if (pathCompleted || true)
        {
            Debug::Log("Completed Correctly!!");
            _levelMode = LevelMode::TowerMode;
            auto childrenCopy = rightHud->Children();
            for (const auto& child: childrenCopy)
            {
                rightHud->RemoveChild(child);
            }

            auto moneyText = std::make_shared<spic::Text>("money-text", "default", Layer::HUD, HudWidth, 20);
            moneyText->Size(18);
            moneyText->TextAlignment(Alignment::center);
            moneyText->Transform().position.y = 200;
            moneyText->Content("$ " + std::to_string(_levelData.Balance));

            auto heroHealthTextHeader = std::make_shared<spic::Text>("hero-health-text-header", "default", Layer::HUD, HudWidth, 20);
            heroHealthTextHeader->Size(18);
            heroHealthTextHeader->TextAlignment(Alignment::center);
            heroHealthTextHeader->Transform().position.y = 250;
            heroHealthTextHeader->Content("Hero:");

            auto heroHealthText = std::make_shared<spic::Text>("hero-health-text", "default", Layer::HUD, HudWidth, 20);
            heroHealthText->Size(18);
            heroHealthText->TextAlignment(Alignment::center);
            heroHealthText->Transform().position.y = 270;
            heroHealthText->Content("♥ " + std::to_string(_levelData.HeroHealth->Health()));

            auto militaryBaseHealthTextHeader = std::make_shared<spic::Text>("military-base-health-text-header", "default", Layer::HUD, HudWidth, 20);
            militaryBaseHealthTextHeader->Size(18);
            militaryBaseHealthTextHeader->TextAlignment(Alignment::center);
            militaryBaseHealthTextHeader->Transform().position.y = 300;
            militaryBaseHealthTextHeader->Content("Militaire Basis:");

            auto militaryBaseHealthText = std::make_shared<spic::Text>("military-base-health-text", "default", Layer::HUD, HudWidth, 20);
            militaryBaseHealthText->Size(18);
            militaryBaseHealthText->TextAlignment(Alignment::center);
            militaryBaseHealthText->Transform().position.y = 320;
            militaryBaseHealthText->Content("♥ " + std::to_string(_levelData.MilitaryBaseHealth->Health()));

            GameObjectUtil::LinkChild(rightHud, moneyText);
            GameObjectUtil::LinkChild(rightHud, heroHealthTextHeader);
            GameObjectUtil::LinkChild(rightHud, heroHealthText);
            GameObjectUtil::LinkChild(rightHud, militaryBaseHealthTextHeader);
            GameObjectUtil::LinkChild(rightHud, militaryBaseHealthText);
        }
        else
        {
            auto validationText = std::dynamic_pointer_cast<Text>(GameObject::Find("path-validation-text"));
            if (validationText == nullptr)
            { //Check if validation text allready exists
                validationText = std::make_shared<Text>("path-validation-text", "text", Layer::HUD, 200, 100);
                validationText->Transform().position.y = (TileSize + 2) * TileButtonScale;
                validationText->TextAlignment(Alignment::center);
                validationText->TextColor(Color::red());
                GameObjectUtil::LinkChild(rightHud, validationText);
            }
            validationText->Content("Het huidige pad is niet compleet");

        }
    });
    GameObjectUtil::LinkChild(rightHud, completePathButton);

    int result = std::accumulate(_buttonTileAmounts.begin(), _buttonTileAmounts.end(), 0, [](const int previous, const std::pair<std::shared_ptr<spic::Button>, int>& p) { return previous + p.second; });
    buttonText->Content("Tegels (" + std::to_string(result) + ")");

    return rightHud;
}

std::shared_ptr<spic::GameObject> LevelController::BuildLevel(const std::shared_ptr<game::HealthBehaviour>& endTowerHealthBehaviour)
{
    auto tileMap = std::make_shared<spic::GameObject>("TileGrid", "tilemap", Layer::Game);
    for (auto levelTile: _level.Tiles)
    {
        auto name = "Tile_" + std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y);

        auto tile = std::shared_ptr<spic::GameObject>();
        auto sprite = std::make_shared<spic::Sprite>(TileUtil::GetSprite((TileType) levelTile.Type), false, false, 1, 1);

        if (levelTile.TileType() == TileType::End)
        {
            tile = std::make_shared<spic::GameObject>("end-tile", "end_tile", Layer::Game);
            auto endTileCollider = std::make_shared<spic::BoxCollider>(TileSize * TileMapScale, TileSize * TileMapScale);
            endTileCollider->IsTrigger(true);
            GameObjectUtil::LinkComponent(tile, endTileCollider);
            GameObjectUtil::LinkComponent(tile, endTowerHealthBehaviour);
        }
        else if (levelTile.TileType() == TileType::Start)
        {
            tile = std::make_shared<spic::GameObject>("start-tile", "start_tile", Layer::Game);
        }
        else
        {
            tile = std::make_shared<spic::GameObject>(name, "tile", Layer::Game);
        }

        tile->Transform().position.x = levelTile.X * TileSize;
        tile->Transform().position.y = levelTile.Y * TileSize;

        MapNode node;
        node.X = levelTile.X;
        node.Y = levelTile.Y;
        node.OriginalTileType = levelTile.TileType();
        node.TileType = levelTile.TileType();
        node.TileObject = tile;
        node.Visited = false;
        _levelData.Graph[std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y)] = node;

        GameObjectUtil::LinkComponent(tile, sprite);
        GameObjectUtil::LinkChild(tileMap, tile);
    }

    for (auto&[key, node]: _levelData.Graph)
    {
        if (node.X > 0)
            node.NeighbourStrings.push_back(std::to_string(node.X - 1) + "-" + std::to_string(node.Y));
        if (node.X < 24)
            node.NeighbourStrings.push_back(std::to_string(node.X + 1) + "-" + std::to_string(node.Y));
        if (node.Y > 0)
            node.NeighbourStrings.push_back(std::to_string(node.X) + "-" + std::to_string(node.Y - 1));
        if (node.Y < 24)
            node.NeighbourStrings.push_back(std::to_string(node.X) + "-" + std::to_string(node.Y + 1));
    }

    return tileMap;
}

std::shared_ptr<spic::Button> LevelController::InitializeTileButton(const std::shared_ptr<spic::GameObject>& HUD, const std::string& texture, int tileAmount, const std::string& tileTitle)
{
    auto button = std::make_shared<spic::Button>("tile-button-" + texture, "tile_button", Layer::HUD, TileSize, TileSize);
    button->Transform().scale = TileButtonScale;
    button->Transform().position.x = -50;
    auto buttonSprite = std::make_shared<spic::Sprite>(texture, false, false, 100, 1);
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
        };

        auto selectionSprite = std::make_shared<spic::Sprite>("resources/sprites/tiles/selected.png", false, false, 100, 1);
        GameObjectUtil::LinkComponent(button, selectionSprite);
        _selectedButton = button;
    });

    GameObjectUtil::LinkChild(HUD, button);
    return button;
}

std::shared_ptr<spic::GameObject> LevelController::CreateMapButton()
{
    double mapSize = sqrt(_level.Tiles.size());
    double buttonSize = mapSize * TileSize;
    auto mapTileButton = std::make_shared<spic::Button>("Map_Button", "map_button", Layer::Game, buttonSize, buttonSize);
    mapTileButton->Transform().position.x += (buttonSize / 2.0) - TileSize / 2.0;
    mapTileButton->Transform().position.y += (buttonSize / 2.0) - TileSize / 2.0;

    mapTileButton->OnClick([this]() {
        auto mousePositions = Input::MousePosition();
        double scaledTileSize = TileSize * TileMapScale;
        int x = ((mousePositions.x - MapX) + (scaledTileSize / 2)) / scaledTileSize;
        int y = ((mousePositions.y - MapY) + (scaledTileSize / 2)) / scaledTileSize;

        if (_levelMode == LevelMode::TileMode)
        {
            HandleTileClick(_levelData.Graph[std::to_string(x) + "-" + std::to_string(y)]);
        }
        else if (_levelMode == LevelMode::TowerMode)
        {
            //TODO HandleTowerClick
        }
    });

    return mapTileButton;
}

void LevelController::HandleTileClick(const game::MapNode& clickedTile)
{
    if (_selectedButton != nullptr)
    {
        auto currentTileType = clickedTile.TileType;
        if ((_strongPathEnabled && currentTileType != TileType::Start && currentTileType != TileType::End) || currentTileType == TileType::Bushes || currentTileType == TileType::Street || currentTileType == TileType::Sand || currentTileType == TileType::Grass)
        {
            auto selectedButtonSprite = _selectedButton->GetComponent<spic::Sprite>();
            auto clickedTileSprite = clickedTile.TileObject->GetComponent<spic::Sprite>();
            TileType clickedTileSpriteTileType = TileUtil::GetTileType(clickedTileSprite->Texture());
            TileType selectedButtonTileType = TileUtil::GetTileType(selectedButtonSprite->Texture());

            if (clickedTileSpriteTileType == selectedButtonTileType && selectedButtonTileType != clickedTile.OriginalTileType)
            {
                clickedTileSprite->Texture(TileUtil::GetSprite(clickedTile.OriginalTileType));
                _levelData.Graph[std::to_string(clickedTile.X) + "-" + std::to_string(clickedTile.Y)].TileType = clickedTile.OriginalTileType;
                _buttonTileAmounts[_selectedButton]++;
            }
            else
            {
                if (_buttonTileAmounts[_selectedButton] == 0) return;
                if (clickedTileSpriteTileType != TileType::Bushes && !_strongPathEnabled)
                {
                    auto writeBackButton = std::dynamic_pointer_cast<Button>(GameObject::Find("tile-button-" + clickedTileSprite->Texture()));
                    auto writeBackText = std::dynamic_pointer_cast<Text>(writeBackButton->Children()[0]);

                    auto sprite = writeBackButton->GetComponent<Sprite>();
                    if (TileUtil::GetTileType(sprite->Texture()) != clickedTile.OriginalTileType || selectedButtonTileType == clickedTile.OriginalTileType)
                    {
                        _buttonTileAmounts[writeBackButton]++;
                        writeBackText->Content(std::to_string(_buttonTileAmounts[writeBackButton]));
                    }
                }
                clickedTileSprite->Texture(selectedButtonSprite->Texture());
                _buttonTileAmounts[_selectedButton]--;
                _levelData.Graph[std::to_string(clickedTile.X) + "-" + std::to_string(clickedTile.Y)].TileType = selectedButtonTileType;
            }

            //Change text of button in HUD
            auto HUDButtonText = std::dynamic_pointer_cast<spic::Text>(_selectedButton->Children()[0]);
            HUDButtonText->Content(std::to_string(_buttonTileAmounts[_selectedButton]));

            int totalTiles = std::accumulate(_buttonTileAmounts.begin(), _buttonTileAmounts.end(), 0, [](const int previous, const std::pair<std::shared_ptr<spic::Button>, int>& p) { return previous + p.second; });
            auto totalTilesText = std::dynamic_pointer_cast<Text>(GameObject::Find("tile-title-text"));
            totalTilesText->Content("Tegels (" + std::to_string(totalTiles) + ")");
        }
    }
}

bool LevelController::CheckIfPathIsComplete() const
{
    auto graphCopy = _levelData.Graph;
    MapNode start;
    for (const auto&[key, value]: graphCopy)
    {
        if (value.TileType == TileType::Start)
            start = value;
    }

    if (start.NeighbourStrings.empty()) return false;

    std::vector<std::string> pathTiles;
    pathTiles.push_back(std::to_string(start.X) + "-" + std::to_string(start.Y));
    while (!pathTiles.empty())
    {
        auto& tile = graphCopy[pathTiles[0]];
        tile.Visited = true;
        for (auto& stringNeighbour: tile.NeighbourStrings)
        {
            const auto& neighbour = graphCopy[stringNeighbour];
            if (neighbour.TileType == TileType::End) return true;
            if ((neighbour.TileType == TileType::Street || neighbour.TileType == TileType::Sand || neighbour.TileType == TileType::Grass || neighbour.TileType == TileType::Bridge) && !neighbour.Visited)
                pathTiles.push_back(std::to_string(neighbour.X) + "-" + std::to_string(neighbour.Y));
        }
        pathTiles.erase(std::find(pathTiles.begin(), pathTiles.end(), pathTiles[0]));
    }

    return false;
}

void LevelController::SetUnlimitedPath()
{
    for (auto&[button, tileAmount]: _buttonTileAmounts)
    {
        tileAmount = 625;
        auto HUDButtonText = std::dynamic_pointer_cast<spic::Text>(button->Children()[0]);
        HUDButtonText->Content(std::to_string(tileAmount));
    }
}

void LevelController::SetStrongPath()
{
    _strongPathEnabled = true;
}

void LevelController::SetUnlimitedMoney()
{
    _levelData.Balance += 1000000000;
}
