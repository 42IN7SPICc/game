#include "SaveSelectionScene.hpp"

#include "MainScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Persistence/SaveGameManager.hpp"

#include "Engine.hpp"

using namespace game;

SaveSelectionScene::SaveSelectionScene() : MenuScene("Selecteer spelbestand", true, BackgroundName::Menu)
{
    auto buttonSave1 = ButtonPrefabFactory::CreateSquareOutlineButton("Button Save 1", "button_save_1", "ALPHA");
    buttonSave1->Transform().position = {283, 469};
    buttonSave1->OnClick([]() {
        SaveSelectionScene::LoadSave("alpha");
    });

    auto buttonSave2 = ButtonPrefabFactory::CreateSquareOutlineButton("Button Save 2", "button_save_2", "BRAVO");
    buttonSave2->Transform().position = {683, 469};
    buttonSave2->OnClick([]() {
        SaveSelectionScene::LoadSave("beta");
    });

    auto buttonSave3 = ButtonPrefabFactory::CreateSquareOutlineButton("Button Save 3", "button_save_3", "CHARLIE");
    buttonSave3->Transform().position = {1083, 469};
    buttonSave3->OnClick([]() {
        SaveSelectionScene::LoadSave("charlie");
    });

    Contents().push_back(buttonSave1);
    Contents().push_back(buttonSave2);
    Contents().push_back(buttonSave3);
}

void SaveSelectionScene::LoadSave(const std::string& saveName)
{
    auto saves = SaveGameManager::GetAll();

    if (!saves.contains(saveName))
    {
        PlayerData playerData{};
        playerData.File = "./resources/saves/" + saveName + ".json";
        SaveGameManager::Save(playerData);

        saves.emplace(saveName, playerData);
    }

    PlayerData::Instance(saves[saveName]);

    spic::Engine::Instance().PushScene(std::make_shared<MainScene>());
}
