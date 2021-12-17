#include "Api.hpp"
#include "LevelController.hpp"
#include "../Scripts/Common/GameWonBehaviour.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/TileUtil.hpp"
#include "Utils/QueueUtil.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/EnemyPrefabFactory.hpp"
#include "../Factories/TowerPrefabFactory.hpp"
#include <cmath>
#include <map>
#include <vector>
#include <memory>
#include <numeric>
#include "../Constants.hpp"
#include "Utils/RandomUtil.hpp"
#include "../Utils/HeroUtil.hpp"
#include "../Structs/PlayerData.hpp"
#include "../TowerConstants.hpp"
#include "../Scripts/Heroes/AbilityBehaviour.hpp"

using namespace spic;
using namespace game;

LevelController::LevelController(std::shared_ptr<game::LevelWithTiles> level, std::shared_ptr<game::HealthBehaviour> heroHealth, std::shared_ptr<game::HealthBehaviour> militaryBaseHealth, std::queue<game::WaveData> waves, std::shared_ptr<LevelData> levelData, std::shared_ptr<game::HudData> hudData) : _timePassed(0),
                                                                                                                                                                                                                                                                                                              _level(std::move(level)),
                                                                                                                                                                                                                                                                                                              _levelData(levelData),
                                                                                                                                                                                                                                                                                                              _strongPathEnabled(false),
                                                                                                                                                                                                                                                                                                              _hudData(hudData),
                                                                                                                                                                                                                                                                                                              _noCoolDown(false)
{
}

void LevelController::OnStart()
{
    auto parent = GameObject().lock();

    auto gameWonBehaviour = std::make_shared<game::GameWonBehaviour>(*_levelData);
    GameObjectUtil::LinkComponent(parent, gameWonBehaviour);

    _levelData->HeroHealth->GameObject().lock()->Transform().position = GameObject::FindWithTag("end_tile")->AbsoluteTransform().position;

    _startPosition = GameObject::FindWithTag("start_tile")->AbsoluteTransform().position;
}

void LevelController::OnUpdate()
{
    if(_noCoolDown) {
        auto hero = _levelData->HeroHealth->GameObject().lock();
        auto ability = hero->GetComponent<game::AbilityBehaviour>()->GetCoolDownBehaviour();
        ability->CoolDown(0);
        ability->CooledDown(true);
    }
    if (_levelData->LevelMode == LevelMode::TowerMode || _levelData->LevelMode == LevelMode::WaveMode)
    {
        _timePassed += Time::DeltaTime() * Time::TimeScale();

        if (!_levelData->Waves.empty() && _levelData->LevelMode == LevelMode::WaveMode)
        {
            auto& wave = _levelData->Waves.front();
            _levelData->ClearDeadEnemies(wave);
            if (!wave.EnemyQueue.empty())
            {
                auto&[timeTillNextEnemy, nextEnemy] = wave.EnemyQueue.front();
                if (_timePassed >= timeTillNextEnemy)
                {
                    wave.CurrentEnemies.push_back(nextEnemy);
                    nextEnemy->Transform().position = _startPosition;
                    Engine::Instance().PeekScene()->Contents().push_back(nextEnemy);
                    wave.EnemyQueue.pop();
                    _timePassed = 0;
                }
            }

            if (wave.RemainingEnemies() == 0)
            {
                PlayerData::Instance().WavesPlayed += 1;
                _levelData->LevelMode = LevelMode::TowerMode;
            }
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

std::shared_ptr<spic::GameObject> LevelController::BuildLevel(const std::shared_ptr<game::HealthBehaviour>& endTowerHealthBehaviour, const std::shared_ptr<spic::Animator>& animator)
{
    auto tileMap = std::make_shared<spic::GameObject>("TileGrid", "tilemap", Layer::Game);
    for (auto levelTile: _level->Tiles)
    {
        auto name = "Tile_" + std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y);

        auto tile = std::shared_ptr<spic::GameObject>();
        auto sprite = std::make_shared<spic::Sprite>(TileUtil::GetSprite((TileType) levelTile.Type), false, false, 1, 1);

        if (levelTile.TileType() == TileType::End)
        {
            tile = std::make_shared<spic::GameObject>("end-tile", "end_tile", Layer::Game);
            auto endTileCollider = std::make_shared<spic::BoxCollider>(TileSize * TileMapScale, TileSize * TileMapScale);
            endTileCollider->IsTrigger(true);
            auto tileRigidBody = std::make_shared<spic::RigidBody>(10, 0, BodyType::staticBody);

            GameObjectUtil::LinkComponent(tile, endTileCollider);
            GameObjectUtil::LinkComponent(tile, endTowerHealthBehaviour);
            GameObjectUtil::LinkComponent(tile, animator);
            GameObjectUtil::LinkComponent(tile, tileRigidBody);
        }
        else if (levelTile.TileType() == TileType::Start)
        {
            tile = std::make_shared<spic::GameObject>("start-tile", "start_tile", Layer::Game);
        }
        else
        {
            tile = std::make_shared<spic::GameObject>(name, "tile", Layer::Game);
        }

        if (levelTile.TileType() == TileType::Bushes || levelTile.TileType() == TileType::Rocks)
        {
            sprite->FlipX(RandomUtil::NextBool());
            sprite->FlipY(RandomUtil::NextBool());
        }

        tile->Transform().position.x = levelTile.X * TileSize;
        tile->Transform().position.y = levelTile.Y * TileSize;

        MapNode node;
        node.X = levelTile.X;
        node.Y = levelTile.Y;
        node.OriginalTileType = levelTile.TileType();
        node.TileType = levelTile.TileType();
        node.TileObject = tile;
        node.TowerObject = {};
        node.Visited = false;
        _levelData->Graph[std::to_string(levelTile.X) + "-" + std::to_string(levelTile.Y)] = node;

        GameObjectUtil::LinkComponent(tile, sprite);
        GameObjectUtil::LinkChild(tileMap, tile);
    }

    for (auto&[key, node]: _levelData->Graph)
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

    GameObjectUtil::LinkChild(tileMap, CreateLevelBorder(12 * TileSize, -TileSize, TileSize * TileMapScale * 27, TileSize * TileMapScale)); // Top
    GameObjectUtil::LinkChild(tileMap, CreateLevelBorder(25 * TileSize, 12 * TileSize, TileSize * TileMapScale, TileSize * TileMapScale * 27)); // Right
    GameObjectUtil::LinkChild(tileMap, CreateLevelBorder(12 * TileSize, 25 * TileSize, TileSize * TileMapScale * 27, TileSize * TileMapScale)); // Bottom
    GameObjectUtil::LinkChild(tileMap, CreateLevelBorder(-TileSize, 12 * TileSize, TileSize * TileMapScale, TileSize * TileMapScale * 27)); // Left

    return tileMap;
}

void LevelController::InitializeWorldColliders(const game::LevelData& levelData)
{
    for (const auto&[key, node]: levelData.Graph)
    {
        if (!Walkable(node.TileType))
        {
            for (const auto& neighbourString: node.NeighbourStrings)
            {
                if (Walkable(levelData.Graph.at(neighbourString).TileType))
                {
                    if (!node.TileObject->GetComponent<RigidBody>())
                        GameObjectUtil::LinkComponent(node.TileObject, std::make_shared<RigidBody>(10, 0, BodyType::staticBody));
                    if (!node.TileObject->GetComponent<Collider>())
                        GameObjectUtil::LinkComponent(node.TileObject, std::make_shared<BoxCollider>(TileSize * TileMapScale, TileSize * TileMapScale));

                    break;
                }
            }
        }
    }
}

bool LevelController::Walkable(const TileType& tileType, bool isHero)
{
    switch (tileType)
    {
        case Bushes:
            return isHero;

        case Sand:
        case Bridge:
        case Street:
        case Grass:
        case Start:
        case End:
            return true;
    }
    return false;
}

std::shared_ptr<spic::GameObject> LevelController::CreateLevelBorder(double x, double y, double width, double height)
{
    auto border = std::make_shared<spic::GameObject>("Border", "border", Layer::Game);
    border->Transform().position = {x, y};
    GameObjectUtil::LinkComponent(border, std::make_shared<spic::RigidBody>(10, 0, BodyType::staticBody));
    GameObjectUtil::LinkComponent(border, std::make_shared<BoxCollider>(width, height));

    return border;
}

std::shared_ptr<spic::GameObject> LevelController::CreateMapButton()
{
    double mapSize = sqrt(_level->Tiles.size());
    double buttonSize = mapSize * TileSize;
    auto mapTileButton = std::make_shared<spic::Button>("Map_Button", "map_button", Layer::Game, buttonSize, buttonSize);
    mapTileButton->Transform().position.x += (buttonSize / 2.0) - TileSize / 2.0;
    mapTileButton->Transform().position.y += (buttonSize / 2.0) - TileSize / 2.0;

    mapTileButton->OnClick([this]() {
        auto mousePositions = Input::MousePosition();
        double scaledTileSize = TileSize * TileMapScale;
        int x = static_cast<int>(((mousePositions.x - MapX) + (scaledTileSize / 2)) / scaledTileSize);
        int y = static_cast<int>(((mousePositions.y - MapY) + (scaledTileSize / 2)) / scaledTileSize);

        if (_levelData->LevelMode == LevelMode::TileMode)
        {
            HandleClickTile(_levelData->Graph[std::to_string(x) + "-" + std::to_string(y)]);
        }
        else if (_levelData->LevelMode == LevelMode::TowerMode && _levelData->LevelMode != LevelMode::WaveMode)
        {
            HandleClickTower(_levelData->Graph[std::to_string(x) + "-" + std::to_string(y)]);
        }
    });

    return mapTileButton;
}

void LevelController::HandleClickTile(const game::MapNode& clickedTile)
{
    if (_hudData->SelectedButton != nullptr)
    {
        auto currentTileType = clickedTile.TileType;
        if ((_strongPathEnabled && currentTileType != TileType::Start && currentTileType != TileType::End) || currentTileType == TileType::Bushes || currentTileType == TileType::Street || currentTileType == TileType::Sand || currentTileType == TileType::Grass)
        {
            auto selectedButtonSprite = _hudData->SelectedButton->GetComponent<spic::Sprite>();
            auto clickedTileSprite = clickedTile.TileObject->GetComponent<spic::Sprite>();
            TileType clickedTileSpriteTileType = TileUtil::GetTileType(clickedTileSprite->Texture());
            TileType selectedButtonTileType = TileUtil::GetTileType(selectedButtonSprite->Texture());

            if (clickedTileSpriteTileType == selectedButtonTileType && selectedButtonTileType != clickedTile.OriginalTileType)
            {
                clickedTileSprite->Texture(TileUtil::GetSprite(clickedTile.OriginalTileType));
                _levelData->Graph[std::to_string(clickedTile.X) + "-" + std::to_string(clickedTile.Y)].TileType = clickedTile.OriginalTileType;
                _hudData->ButtonTileAmounts[_hudData->SelectedButton]++;
            }
            else
            {
                if (_hudData->ButtonTileAmounts[_hudData->SelectedButton] == 0) return;
                if (clickedTileSpriteTileType != TileType::Bushes && !_strongPathEnabled)
                {
                    auto writeBackButton = std::dynamic_pointer_cast<Button>(GameObject::Find("tile-button-" + clickedTileSprite->Texture()));
                    auto writeBackText = std::dynamic_pointer_cast<Text>(writeBackButton->Children()[0]);

                    auto sprite = writeBackButton->GetComponent<Sprite>();
                    if (TileUtil::GetTileType(sprite->Texture()) != clickedTile.OriginalTileType || selectedButtonTileType == clickedTile.OriginalTileType)
                    {
                        _hudData->ButtonTileAmounts[writeBackButton]++;
                        writeBackText->Content(std::to_string(_hudData->ButtonTileAmounts[writeBackButton]));
                    }
                }
                clickedTileSprite->Texture(selectedButtonSprite->Texture());
                _hudData->ButtonTileAmounts[_hudData->SelectedButton]--;
                _levelData->Graph[std::to_string(clickedTile.X) + "-" + std::to_string(clickedTile.Y)].TileType = selectedButtonTileType;
            }

            //Change text of button in HUD
            auto HUDButtonText = std::dynamic_pointer_cast<spic::Text>(_hudData->SelectedButton->Children()[0]);
            HUDButtonText->Content(std::to_string(_hudData->ButtonTileAmounts[_hudData->SelectedButton]));

            int totalTiles = std::accumulate(_hudData->ButtonTileAmounts.begin(), _hudData->ButtonTileAmounts.end(), 0, [](const int previous, const std::pair<std::shared_ptr<spic::Button>, int>& p) { return previous + p.second; });
            auto totalTilesText = std::dynamic_pointer_cast<Text>(GameObject::Find("tile-title-text"));
            totalTilesText->Content("Tegels (" + std::to_string(totalTiles) + ")");
        }
    }
}

void LevelController::AddEnemyToWave(const std::shared_ptr<spic::GameObject>& enemy)
{
    _levelData->Waves.front().CurrentEnemies.push_back(enemy);
}

void LevelController::HandleClickTower(game::MapNode& clickedTile)
{
    auto currentTileType = clickedTile.TileType;
    if (currentTileType == TileType::Bushes && _hudData->SelectedButton != nullptr && (_levelData->Waves.front().RemainingEnemies() == 0 || _levelData->LevelMode != LevelMode::WaveMode))
    {
        if (!clickedTile.TowerObject && _levelData->Balance >= _hudData->ButtonTowerCosts[_hudData->SelectedButton])
        {
            TowerName towerType;
            switch (_hudData->ButtonTowerCosts[_hudData->SelectedButton]) //current switch on tower cost - maybe change in future of type check
            {
                case SniperTowerCost:
                    towerType = TowerName::Sniper;
                    break;
                case BomberTowerCost:
                    towerType = TowerName::Bomber;
                    break;
                case FlamethrowerTowerCost:
                    towerType = TowerName::Flamethrower;
                    break;
                case ShotgunTowerCost:
                default:
                    towerType = TowerName::Shotgun;
                    break;
            }
            auto tower = TowerPrefabFactory::CreateTower(towerType);
            tower->Transform().position = clickedTile.TileObject->AbsoluteTransform().position;
            tower->Transform().scale = 0.05;

            Engine::Instance().PeekScene()->Contents().push_back(tower);
            clickedTile.TowerObject = tower;
            _levelData->Balance -= _hudData->ButtonTowerCosts[_hudData->SelectedButton];
            auto& playerData = game::PlayerData::Instance();
            playerData.TowersPlaced += 1;
            _levelData->TowersPlaced++;
            if (_levelData->TowersPlaced > playerData.MostTowersPlaced)
                playerData.MostTowersPlaced = _levelData->TowersPlaced;
        }
    }
}

std::tuple<bool, std::queue<std::string>> LevelController::CheckIfPathIsComplete(std::map<std::string, MapNode> graphCopy)
{
    MapNode start;
    MapNode end;
    for (const auto&[key, value]: graphCopy)
    {
        if (value.TileType == TileType::Start)
            start = value;

        else if (value.TileType == TileType::End)
            end = value;
    }

    if (start.NeighbourStrings.empty()) return {false, {}};
    if (end.NeighbourStrings.empty()) return {false, {}};

    std::deque<std::string> unvisitedMapNodes{};
    std::map<std::string, std::string> previous{};

    unvisitedMapNodes.push_back(start.ToString());

    while (!unvisitedMapNodes.empty())
    {
        const auto stringNode = unvisitedMapNodes.front();
        auto& node = graphCopy[stringNode];
        unvisitedMapNodes.pop_front();

        for (const auto& stringNeighbour: node.NeighbourStrings)
        {
            const auto& neighbour = graphCopy[stringNeighbour];

            if (Walkable(neighbour.TileType, false))
            {
                if (previous.contains(stringNeighbour)) continue;

                previous[stringNeighbour] = stringNode;
                unvisitedMapNodes.push_back(stringNeighbour);
            }
        }
    }

    if (!previous.contains(end.ToString())) return {false, {}};

    std::queue<std::string> shortest;
    auto current = end.ToString();

    auto startStr = start.ToString();

    while (current != startStr)
    {
        shortest.push(current);
        current = previous[current];
    }

    shortest.push(start.ToString());
    QueueUtil::Reverse(shortest);

    return {true, shortest};
}

void LevelController::SetUnlimitedPath()
{
    for (auto&[button, tileAmount]: _hudData->ButtonTileAmounts)
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
    _levelData->Balance += 1000000000;
}

void LevelController::SetInvincibility() const
{
    _levelData->HeroHealth->Invincibility(!_levelData->HeroHealth->Invincibility());
}

void LevelController::SkipWave()
{
    if (_levelData->Waves.empty()) return;
    while (!_levelData->Waves.front().EnemyQueue.empty())
    {
        _levelData->Waves.front().EnemyQueue.pop();
    }

    //Don't remove enemies in this loop, it will break the game
    while (!_levelData->Waves.front().CurrentEnemies.empty())
    {
        _levelData->Waves.front().CurrentEnemies.pop_back();
    }

    auto remainingEnemies = GameObject::FindGameObjectsWithTag("enemy");
    for(auto& enemy : remainingEnemies) {
        GameObject::Destroy(enemy);
    }

    _levelData->Waves.pop();
    _levelData->HeroHealth->Health(_levelData->HeroHealth->MaxHealth());
}

std::map<std::string, MapNode>& LevelController::GetGraph()
{
    return _levelData->Graph;
}

std::queue<std::string> LevelController::GetPath() const
{
    return _levelData->Path;
}

void LevelController::ButcherEnemies()
{
    if (!_levelData->Waves.empty())
    {
        for (auto& currentEnemies: _levelData->Waves.front().CurrentEnemies)
        {
            auto healthBehaviour = currentEnemies->GetComponent<HealthBehaviour>();
            healthBehaviour->Damage(healthBehaviour->Health());
        }
    }
}

game::LevelMode LevelController::GetLevelMode() const
{
    return _levelData->LevelMode;
}

void LevelController::ToggleInfiniteCoolDown()
{
    _noCoolDown = !_noCoolDown;
}
