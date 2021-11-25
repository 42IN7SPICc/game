#include "LevelScene.hpp"

#include "BoxCollider.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

#include "../Controllers/LevelController.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Scripts/Common/CheatManager.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include "../Structs/WaveData.hpp"
#include "../Controllers/LevelController.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Scripts/Menu/PauseSceneBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/TileUtil.hpp"

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;
const double TileMapScale = 0.8;
const int MapX = 75;
const int MapY = 110;

LevelScene::LevelScene(LevelWithTiles& levelWithTiles)
{
    auto background = BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu);

    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1166, 100, levelWithTiles.Title, "resources/fonts/capture_it.otf", 35, Alignment::left, Color::white());
    titleText->Transform().position = {1366 / 2, 50};

    auto hero = game::HeroPrefabFactory::CreateHero(DesmondDoss);
    auto heroHealth = hero->GetComponent<HealthBehaviour>();
    auto endTowerHealth = std::make_shared<game::HealthBehaviour>(nullptr, 10);

    auto waves = std::queue<WaveData>();
    auto wave1 = WaveData{{}, {}};
    wave1.EnemyQueue.push(std::make_tuple<size_t, std::shared_ptr<spic::GameObject >>(1, std::make_shared<spic::GameObject>("test", "test", 0)));
    waves.push(wave1);

    auto levelAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::Game, true, true, 0.2);
    auto mainGameObject = std::make_shared<spic::GameObject>("LevelController", "default", Layer::Background);
    auto levelController = std::make_shared<game::LevelController>(levelWithTiles, heroHealth, endTowerHealth, waves);
    auto cheatManager = std::make_shared<game::CheatManager>();
    GameObjectUtil::LinkComponent(mainGameObject, levelController);
    GameObjectUtil::LinkComponent(mainGameObject, cheatManager);
    GameObjectUtil::LinkComponent(mainGameObject, std::make_shared<PauseSceneBehaviour>());

    auto tilesMapObject = BuildLevel(level, endTowerHealth);
    tilesMapObject->Transform().position.x = 75;
    tilesMapObject->Transform().position.y = 110;
    tilesMapObject->Transform().scale = TileMapScale;

    auto tilesMapObject = levelController->BuildLevel();
    tilesMapObject->Transform().position.x = MapX;
    tilesMapObject->Transform().position.y = MapY;
    tilesMapObject->Transform().scale = TileMapScale;

    Contents().push_back(hero);
    Contents().push_back(levelAudioSource);
    Contents().push_back(mainGameObject);
    Contents().push_back(background);
    Contents().push_back(titleText);
    Contents().push_back(tilesMapObject);

    Contents().push_back(levelController->CreateHUD());
}