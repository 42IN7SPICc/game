#include "Api.hpp"
#include "LevelController.hpp"
#include "../Scripts/Common/GameWonBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/TileUtil.hpp"

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;
const double TileMapScale = 0.8;
const int MapX = 75;
const int MapY = 110;

void LevelController::OnStart()
{
    auto gameWonBehaviour = std::make_shared<game::GameWonBehaviour>(_levelData);
    auto parent = GameObject().lock();
    GameObjectUtil::LinkComponent(parent, gameWonBehaviour);
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
    int totalTileAmount = 22;

    auto rightHud = std::make_shared<spic::GameObject>("RightHud", "hud", Layer::HUD);
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

    auto streetButton = InitializeTileButton(rightHud, "street.png", 18, "Straat");
    streetButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 4);

    auto grassButton = InitializeTileButton(rightHud, "grass.png", 6, "Gras");
    grassButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 3);

    auto sandButton = InitializeTileButton(rightHud, "sand.png", 6, "Zand");
    sandButton->Transform().position.y = -(TileSize + 2) * (TileButtonScale * 2);

    return rightHud;
}

bool TileIsValid(TileType tileType) {
    return
        tileType == TileType::Bushes ||
        tileType == TileType::Street ||
        tileType == TileType::Sand ||
        tileType == TileType::Grass;
}

bool TileWasPlaced(TileType tileType) {
    return
        tileType == TileType::Street ||
        tileType == TileType::Sand ||
        tileType == TileType::Grass;
}

std::shared_ptr<spic::GameObject> LevelController::BuildLevel()
{
    auto tileMap = std::make_shared<spic::GameObject>("TileGrid", "tilemap", Layer::Game);
    for (auto levelTile : _level.Tiles)
    {
        auto name = "Tile_" + std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y);

        auto tile = std::make_shared<spic::GameObject>(name, "tile", Layer::Game);
        auto sprite = std::make_shared<spic::Sprite>(TileUtil::GetSprite((TileType) levelTile.Type), false, false, 1, 1);

        tile->Transform().position.x = levelTile.X * TileSize;
        tile->Transform().position.y = levelTile.Y * TileSize;

        MapNode node;
        node.X = levelTile.X;
        node.Y = levelTile.Y;
        node.TileType = levelTile.TileType();
        node.TileObject = tile;
        _levelData.Graph[std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y)] = node;

        GameObjectUtil::LinkComponent(tile, sprite);
        GameObjectUtil::LinkChild(tileMap, tile);
    }

    double mapSize = sqrt(_level.Tiles.size());
    double buttonSize = mapSize * TileSize;
    auto mapTileButton = std::make_shared<spic::Button>("Map_Button", "map_button", Layer::Game, buttonSize, buttonSize);
    mapTileButton->Transform().position.x += (buttonSize / 2.0) - TileSize / 2.0;
    mapTileButton->Transform().position.y += (buttonSize / 2.0) - TileSize / 2.0;

    mapTileButton->OnClick([this]() {
        if(_buttonTileAmounts[_selectedButton] == 0) return;

        auto mousePositions = Input::MousePosition();
        double scaledTileSize = TileSize * TileMapScale;
        int x = ((mousePositions.x - MapX) + (scaledTileSize / 2)) / scaledTileSize;
        int y = ((mousePositions.y - MapY) + (scaledTileSize / 2)) / scaledTileSize;

        auto clickedTile = _levelData.Graph[std::to_string(x) + "-" + std::to_string(y)];
        if(_selectedButton != nullptr) {
            if(TileIsValid(clickedTile.TileType)) {
                auto selectedSprite = _selectedButton->GetComponent<spic::Sprite>();
                auto sprite = clickedTile.TileObject->GetComponent<spic::Sprite>();
                sprite->Texture(selectedSprite->Texture());

                auto textChange = std::dynamic_pointer_cast<spic::Text>(_selectedButton->Children()[0]);
                _buttonTileAmounts[_selectedButton]--;
                if(textChange) {
                    textChange->Content(std::to_string(_buttonTileAmounts[_selectedButton]));
                }
            }
        }
    });
    GameObjectUtil::LinkChild(tileMap, mapTileButton);

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
        if (_buttonTileAmounts[button] <= 0) return;
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

