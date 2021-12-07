#include "LevelSelectionScene.hpp"

#include "LevelScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Structs/PlayerData.hpp"

#include "Engine.hpp"

using namespace game;

LevelSelectionScene::LevelSelectionScene() : MenuScene("Level selectie", true)
{
    auto playerData = PlayerData::Instance();
    LevelSelectionController levelSelectionController{};
    levelSelectionController.InitializeLevels();

    auto levels = levelSelectionController.GetLevels(true);

    for (int i = 0; i < levels.size(); ++i)
    {
        auto button = ButtonPrefabFactory::CreateOutlineButton(levels[i].Title, "level_button", "Speel: " + levels[i].Title);
        button->Transform().position = {225.0, static_cast<double>(300 + (100 * i))};
        button->OnClick([levelSelectionController, levels, i]() {
            auto levelWithTiles = levelSelectionController.LoadLevel(levels[i].File);

            auto scene = std::make_shared<LevelScene>(levelWithTiles);
            spic::Engine::Instance().PushScene(scene);
        });
    }
}