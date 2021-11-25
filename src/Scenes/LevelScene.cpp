#include "LevelScene.hpp"

#include "Api.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Utils/TileUtil.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Scripts/Common/CheatManager.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include "../Structs/WaveData.hpp"
#include "../Controllers/LevelController.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;
const double TileMapScale = 0.8;
const int MapX = 75;
const int MapY = 110;

LevelScene::LevelScene(LevelWithTiles& levelWithTiles)
{
    auto levelAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::Game, true, true, 0.2);
    auto mainGameObject = std::make_shared<spic::GameObject>("LevelController", "default", Layer::Background);
    auto background = BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu);

    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1166, 100, levelWithTiles.Title, "resources/fonts/capture_it.otf", 35, Alignment::left, Color::white());
    titleText->Transform().position = {1366 / 2, 50};

    auto hero = game::HeroPrefabFactory::CreateHero(DesmondDoss);
    auto heroHealth = hero->GetComponent<HealthBehaviour>();
    auto endTowerHealth = std::make_shared<game::HealthBehaviour>(std::make_shared<spic::Animator>(0, std::vector<std::shared_ptr<Sprite >>()), 10);

    auto waves = std::queue<WaveData>();

    auto wave1 = WaveData{{}, {}};
    wave1.EnemyQueue.push(std::make_tuple<size_t, std::shared_ptr<spic::GameObject >>(1, std::make_shared<spic::GameObject>("test", "test", 0)));
    waves.push(wave1);

    auto levelController = std::make_shared<game::LevelController>(levelWithTiles, heroHealth, endTowerHealth, waves);
    auto cheatManager = std::make_shared<game::CheatManager>();
    GameObjectUtil::LinkComponent(mainGameObject, levelController);
    GameObjectUtil::LinkComponent(mainGameObject, cheatManager);

    auto tilesMapObject = levelController->BuildLevel();
    tilesMapObject->Transform().position.x = MapX;
    tilesMapObject->Transform().position.y = MapY;
    tilesMapObject->Transform().scale = TileMapScale;

    Contents().push_back(levelAudioSource);
    Contents().push_back(mainGameObject);
    Contents().push_back(background);
    Contents().push_back(titleText);
    Contents().push_back(tilesMapObject);

    Contents().push_back(levelController->CreateHUD());
}