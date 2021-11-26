#include "Api.hpp"
#include "LevelController.hpp"
#include "../Scripts/Common/GameWonBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/TileUtil.hpp"
#include "../Scripts/Common/GameLostBehaviour.hpp"
#include <numeric>
#include <cmath>

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;
const double TileMapScale = 0.8;
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
    //
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
                                                                                                                                                                                                               })
{
}

std::shared_ptr<spic::GameObject> LevelController::CreateHUD()
{
    int screenWidth = 1366;
    int screenHeight = 786;
    int hudWidth = 250;

    auto rightHud = std::make_shared<spic::GameObject>("RightHud", "hud", Layer::HUD);
    auto rightHudSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/white_block.png", false, false, 100, 1);
    GameObjectUtil::LinkComponent(rightHud, rightHudSprite);

    rightHud->Transform().position.x = screenWidth - (hudWidth / TileButtonScale);
    rightHud->Transform().position.y = screenHeight / TileButtonScale;

    auto buttonText = std::make_shared<spic::Text>("tile-title-text", "tile_title_text", Layer::HUD, hudWidth, 100);
    buttonText->Size(24);
    buttonText->TextAlignment(Alignment::center);
    buttonText->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 5);
    GameObjectUtil::LinkChild(rightHud, buttonText);

    auto streetButton = InitializeTileButton(rightHud, "street.png", 18, "Straat");
    streetButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 4);

    auto grassButton = InitializeTileButton(rightHud, "grass.png", 6, "Gras");
    grassButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 3);

    auto sandButton = InitializeTileButton(rightHud, "sand.png", 6, "Zand");
    sandButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 2);

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

        auto tile = std::make_shared<spic::GameObject>(name, "tile", Layer::Game);
        auto sprite = std::make_shared<spic::Sprite>(TileUtil::GetSprite((TileType) levelTile.Type), false, false, 1, 1);

        if (levelTile.TileType() == TileType::End)
        {
            auto endTileCollider = std::make_shared<spic::BoxCollider>(TileSize * TileMapScale, TileSize * TileMapScale);
            endTileCollider->IsTrigger(true);
            GameObjectUtil::LinkComponent(tile, endTileCollider);
            GameObjectUtil::LinkComponent(tile, endTowerHealthBehaviour);
        }

        tile->Transform().position.x = levelTile.X * TileSize;
        tile->Transform().position.y = levelTile.Y * TileSize;

        MapNode node;
        node.X = levelTile.X;
        node.Y = levelTile.Y;
        node.OriginalTileType = levelTile.TileType();
        node.TileType = levelTile.TileType();
        node.TileObject = tile;
        _levelData.Graph[std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y)] = node;

        GameObjectUtil::LinkComponent(tile, sprite);
        GameObjectUtil::LinkChild(tileMap, tile);
    }

    return tileMap;
}

std::shared_ptr<spic::Button> LevelController::InitializeTileButton(const std::shared_ptr<spic::GameObject>& HUD, const std::string& texture, int tileAmount, const std::string& tileTitle)
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

std::string TileTypeToTexture(TileType tileType)
{
    switch (tileType)
    {
        case game::Street:
            return "street.png";
        case game::Sand:
            return "sand.png";
        case game::Grass:
            return "grass.png";
        case game::Bushes:
        default:
            return "bushes.png";
    }
}

std::string TextureToPrefix(const std::string& texture)
{
    if (texture == "resources/sprites/tiles/street.png")
        return "street.png";
    else if (texture == "resources/sprites/tiles/grass.png")
        return "grass.png";
    else if (texture == "resources/sprites/tiles/sand.png")
        return "sand.png";
}

std::shared_ptr<spic::GameObject> LevelController::CreateMapButton()
{
    double mapSize = sqrt(_level.Tiles.size());
    double buttonSize = mapSize * TileSize;
    auto mapTileButton = std::make_shared<spic::Button>("Map_Button", "map_button", Layer::Game, buttonSize, buttonSize);
    mapTileButton->Transform().position.x += (buttonSize / 2.0) - TileSize / 2.0;
    mapTileButton->Transform().position.y += (buttonSize / 2.0) - TileSize / 2.0;

    mapTileButton->OnClick([this]() {
        //if (_buttonTileAmounts[_selectedButton] == 0) return;

        auto mousePositions = Input::MousePosition();
        double scaledTileSize = TileSize * TileMapScale;
        int x = ((mousePositions.x - MapX) + (scaledTileSize / 2)) / scaledTileSize;
        int y = ((mousePositions.y - MapY) + (scaledTileSize / 2)) / scaledTileSize;

        auto clickedTile = _levelData.Graph[std::to_string(x) + "-" + std::to_string(y)];
        if (_selectedButton != nullptr)
        {
            auto currentTileType = clickedTile.TileType;
            //Check if TileType is safe to put on
            if (currentTileType == TileType::Bushes || currentTileType == TileType::Street || currentTileType == TileType::Sand || currentTileType == TileType::Grass)
            {
                auto selectedButtonSprite = _selectedButton->GetComponent<spic::Sprite>();
                auto overrideSprite = clickedTile.TileObject->GetComponent<spic::Sprite>();

                //The Tile you've placed is the same, some put it back to the original tile
                if (overrideSprite->Texture() == selectedButtonSprite->Texture() && selectedButtonSprite->Texture() != "resources/sprites/tiles/" + TileTypeToTexture(clickedTile.OriginalTileType))
                {
                    overrideSprite->Texture("resources/sprites/tiles/" + TileTypeToTexture(clickedTile.OriginalTileType));
                    _buttonTileAmounts[_selectedButton]++;
                }
                else
                {
                    if (_buttonTileAmounts[_selectedButton] == 0) return;
                    //Check if tile you've clicked isn't a bush, if it is put back the tile in HUD that was already there
                    if (overrideSprite->Texture() != "resources/sprites/tiles/bushes.png")
                    {
                        auto writeBackButton = std::dynamic_pointer_cast<Button>(GameObject::Find("tile-button-" + TextureToPrefix(overrideSprite->Texture())));
                        auto writeBackText = std::dynamic_pointer_cast<Text>(GameObject::Find("tile-button-text-" + TextureToPrefix(overrideSprite->Texture())));

                        _buttonTileAmounts[writeBackButton]++;
                        writeBackText->Content(std::to_string(_buttonTileAmounts[writeBackButton]));
                    }
                    overrideSprite->Texture(selectedButtonSprite->Texture());
                    _buttonTileAmounts[_selectedButton]--;
                }

                //Change text of button in HUD
                auto textChange = std::dynamic_pointer_cast<spic::Text>(_selectedButton->Children()[0]);
                textChange->Content(std::to_string(_buttonTileAmounts[_selectedButton]));

                int result = std::accumulate(_buttonTileAmounts.begin(), _buttonTileAmounts.end(), 0, [](const int previous, const std::pair<std::shared_ptr<spic::Button>, int>& p) { return previous + p.second; });
                auto totalTilesText = std::dynamic_pointer_cast<Text>(GameObject::Find("tile-title-text"));
                totalTilesText->Content("Tegels (" + std::to_string(result) + ")");
            }
        }
    });

    return mapTileButton;
}

