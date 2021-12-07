#include "LevelSelectionScene.hpp"

#include "LevelScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Structs/PlayerData.hpp"
#include "../Enums/Layer.hpp"

#include "Text.hpp"
#include "Engine.hpp"

using namespace game;

LevelSelectionScene::LevelSelectionScene() : MenuScene("Level selectie", true)
{
    auto buttonX = spic::Engine::Instance().Config().window.width / 2;

    auto validationTextForButtonValidation = std::make_shared<spic::Text>("Help Text", "text_help", Layer::HUD, 700, 400);
    auto playerData = PlayerData::Instance();

    auto levelSelectionController = std::make_shared<LevelSelectionController>();
    levelSelectionController->InitializeLevels();

    auto levels = levelSelectionController->GetLevels();

    int i;
    for (i = 0; i < levels.size(); ++i)
    {
        if (playerData.LevelsCompleted >= levels[i].UnlockThreshold)
        {
            // can play
            auto button = ButtonPrefabFactory::CreateWideOutlineButton(levels[i].Title, "level_button", levels[i].Title);
            button->Transform().position = {
                    static_cast<double>(buttonX), static_cast<double>(300 + (100 * i))
            };
            button->OnClick([levelSelectionController, levels, i]() {
                auto levelWithTiles = levelSelectionController->LoadLevel(levels[i].File);

                auto scene = std::make_shared<LevelScene>(levelWithTiles);
                spic::Engine::Instance().PushScene(scene);
            });

            Contents().push_back(button);
        }
        else
        {
            // not play
            auto button = ButtonPrefabFactory::CreateWideOutlineButton(levels[i].Title, "level_button", levels[i].Title, true);
            button->Transform().position = {
                    static_cast<double>(buttonX), static_cast<double>(300 + (100 * i))
            };
            button->OnClick([validationTextForButtonValidation, levels, i]() {
                validationTextForButtonValidation->Active(true);
                validationTextForButtonValidation->Content("Je kunt dit level nog niet spelen! Speel eerst: " + levels[i-1].Title);
            });

            Contents().push_back(button);
        }
    }

    validationTextForButtonValidation->Transform().position = {static_cast<double>(buttonX), static_cast<double>(300 + (100 * (i + 1)))};
    validationTextForButtonValidation->Size(20);
    validationTextForButtonValidation->TextColor(spic::Color::white());
    validationTextForButtonValidation->Active(false);
    Contents().push_back(validationTextForButtonValidation);

}