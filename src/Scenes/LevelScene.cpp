#include "LevelScene.hpp"

#include "GameObject.hpp"

#include "../Controllers/LevelController.hpp"
#include "../Enums/Layer.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Scripts/Common/CheatManager.hpp"
#include "../Scripts/Menu/PauseSceneBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Factories/WavePrefabFactory.hpp"

using namespace spic;
using namespace game;

const double TileButtonScale = 2.0;
const double TileSize = 32;
const double TileMapScale = 0.985;
const int MapX = TileSize / 2 + 155;
const int MapY = TileSize / 2;

LevelScene::LevelScene(LevelWithTiles& levelWithTiles)
{
    auto background = BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu);

    auto hero = game::HeroPrefabFactory::CreateHero(DesmondDoss);
    hero->Active(false);
    auto heroHealth = hero->GetComponent<HealthBehaviour>();
    auto endTowerHealth = std::make_shared<game::HealthBehaviour>(nullptr, 10);

    auto levelAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::Game, true, true, 0.2);
    auto mainGameObject = std::make_shared<spic::GameObject>("LevelController", "default", Layer::Background);
    auto levelController = std::make_shared<game::LevelController>(levelWithTiles, heroHealth, endTowerHealth, game::WavePrefabFactory::GenerateWaves(5));
    auto cheatManager = std::make_shared<game::CheatManager>();
    GameObjectUtil::LinkComponent(mainGameObject, levelController);
    GameObjectUtil::LinkComponent(mainGameObject, cheatManager);
    GameObjectUtil::LinkComponent(mainGameObject, std::make_shared<PauseSceneBehaviour>());

    auto tilesMapObject = levelController->BuildLevel(endTowerHealth);
    tilesMapObject->Transform().position.x = MapX;
    tilesMapObject->Transform().position.y = MapY;
    tilesMapObject->Transform().scale = TileMapScale;
    GameObjectUtil::LinkChild(tilesMapObject, levelController->CreateMapButton());

    Contents().push_back(hero);
    Contents().push_back(levelAudioSource);
    Contents().push_back(mainGameObject);
    Contents().push_back(background);
    Contents().push_back(tilesMapObject);

    Contents().push_back(levelController->CreateHUD());
}