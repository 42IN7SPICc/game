#include "LevelSelectionScene.hpp"

#include "LevelScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Structs/PlayerData.hpp"
#include "../Enums/Layer.hpp"

#include "Text.hpp"
#include "Engine.hpp"
#include "../Scripts/Common/CheatManager.hpp"
#include "Utils/GameObjectUtil.hpp"

using namespace game;

LevelSelectionScene::LevelSelectionScene(const std::shared_ptr<spic::GameObject>& audio) : MenuScene("Level selectie", 1)
{
    _levelSelectionController = std::make_shared<LevelSelectionController>();
    _levelSelectionController->InitializeLevels();
    _levels = _levelSelectionController->GetLevels();
    LoadLevels(false);

    auto cheatGameObject = std::make_shared<spic::GameObject>("cheats-manager","cheat-manager",0);
    auto cheatManager = std::make_shared<game::CheatManager>();
    spic::GameObjectUtil::LinkComponent(cheatGameObject, cheatManager);

    Contents().push_back(cheatGameObject);

    Contents().push_back(audio);
}

void LevelSelectionScene::LoadLevels(bool reload)
{
    auto levelsObject = spic::GameObject::Find("levels-container");
    if(!levelsObject) {
        levelsObject = std::make_shared<spic::GameObject>("levels-container", "levels-container", 0);
    }
    if(reload) {
        for(auto& child : levelsObject->Children()) {
            levelsObject->RemoveChild(child);
        }
    }

    auto buttonX = spic::Engine::Instance().Config().window.width / 2;
    auto validationTextForButtonValidation = std::make_shared<spic::Text>("Help Text", "text_help", Layer::HUD, 700, 400);

    int i;
    for (i = 0; i < _levels.size(); ++i)
    {
        if (PlayerData::Instance().LevelsCompleted >= _levels[i].UnlockThreshold)
        {
            // can play
            auto button = ButtonPrefabFactory::CreateWideOutlineButton(_levels[i].Title, "level_button", _levels[i].Title);
            button->Transform().position = {
                    static_cast<double>(buttonX), static_cast<double>(300 + (100 * i))
            };
            button->OnClick([this, i]() {
                auto levelWithTiles = _levelSelectionController->LoadLevel(_levels[i].File);

                auto scene = std::make_shared<LevelScene>(levelWithTiles);
                spic::Engine::Instance().PushScene(scene);
            });

            spic::GameObjectUtil::LinkChild(levelsObject, button);
        }
        else
        {
            // not play
            auto button = ButtonPrefabFactory::CreateWideOutlineButton(_levels[i].Title, "level_button", _levels[i].Title, true);
            button->Transform().position = {
                    static_cast<double>(buttonX), static_cast<double>(300 + (100 * i))
            };
            button->OnClick([this, validationTextForButtonValidation, i]() {
                validationTextForButtonValidation->Active(true);
                validationTextForButtonValidation->Content("Je kunt dit level nog niet spelen! Speel eerst: " + _levels[i-1].Title);
            });

            spic::GameObjectUtil::LinkChild(levelsObject, button);
        }
    }

    validationTextForButtonValidation->Transform().position = {static_cast<double>(buttonX), static_cast<double>(300 + (100 * (i + 1)))};
    validationTextForButtonValidation->Size(20);
    validationTextForButtonValidation->TextColor(spic::Color::white());
    validationTextForButtonValidation->Active(false);
    spic::GameObjectUtil::LinkChild(levelsObject, validationTextForButtonValidation);

    Contents().push_back(levelsObject);
    Contents().push_back(validationTextForButtonValidation);
}
