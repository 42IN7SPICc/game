#include "SaveSelectionScene.hpp"

#include "MainScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Persistence/SaveGameManager.hpp"

#include "Engine.hpp"
#include "../Constants.hpp"

using namespace game;

SaveSelectionScene::SaveSelectionScene(const std::shared_ptr<spic::GameObject>& audio) : _mainMenuAudio(audio),
                                                                                         MenuScene("Selecteer spelbestand", true, BackgroundName::Menu)
{
    CreateSaveButton("ALPHA", "alpha", 300);
    CreateSaveButton("BRAVO", "bravo", 400);
    CreateSaveButton("CHARLIE", "charlie", 500);

    Contents().push_back(audio);
}

PlayerData SaveSelectionScene::LoadSave(const std::string& saveName)
{
    auto saves = SaveGameManager::GetAll();

    if (!saves.contains(saveName))
    {
        PlayerData playerData{};
        playerData.File = "./resources/saves/" + saveName + ".json";
        SaveGameManager::Save(playerData);

        saves.emplace(saveName, playerData);
    }

    return saves[saveName];
}

bool SaveSelectionScene::SaveExists(const std::string& saveName) const
{
    auto saves = SaveGameManager::GetAll();
    return saves.contains(saveName);
}

void SaveSelectionScene::CreateSaveButton(const std::string& displayName, const std::string& saveName, double buttonY)
{
    double buttonX = spic::Engine::Instance().Config().window.width / 2.0;
    auto saveExists = this->SaveExists(saveName);

    if (saveExists)
    {
        auto save = this->LoadSave(saveName);
        std::string buttonText = displayName + " : " + std::to_string(save.LevelsCompleted) + "/3 levels";

        auto button = ButtonPrefabFactory::CreateWideOutlineButton("Button Save 1", "button_save_1", buttonText);
        button->Transform().position = {buttonX, buttonY};
        button->OnClick([this, save]() {
            PlayerData::Instance(save);
            spic::Engine::Instance().PushScene(std::make_shared<MainScene>(_mainMenuAudio));
        });

        Contents().push_back(button);
    }
    else
    {
        std::string buttonText = "NIEUW BESTAND MAKEN";
        auto button = ButtonPrefabFactory::CreateWideOutlineButton("Button Save 1", "button_save_1", buttonText, true);
        button->Transform().position = {buttonX, buttonY};
        button->OnClick([this, saveName]() {
            auto save = this->LoadSave(saveName);
            PlayerData::Instance(save);
            spic::Engine::Instance().PushScene(std::make_shared<MainScene>(_mainMenuAudio));
        });

        Contents().push_back(button);
    }
}
