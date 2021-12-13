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
    auto buttonSave1 = ButtonPrefabFactory::CreateSquareOutlineButton("Button Save 1", "button_save_1", this->SaveExists("alpha") ? "ALPHA" : "LEEG");
    buttonSave1->Transform().position = {ScreenWidth / 2.0 - 400, 469};
    buttonSave1->OnClick([this]() {
        this->LoadSave("alpha");
    });

    auto buttonSave2 = ButtonPrefabFactory::CreateSquareOutlineButton("Button Save 2", "button_save_2", this->SaveExists("bravo") ? "BRAVO" : "LEEG");
    buttonSave2->Transform().position = {ScreenWidth / 2.0, 469};
    buttonSave2->OnClick([this]() {
        this->LoadSave("bravo");
    });

    auto buttonSave3 = ButtonPrefabFactory::CreateSquareOutlineButton("Button Save 3", "button_save_3", this->SaveExists("charlie") ? "CHARLIE" : "LEEG");
    buttonSave3->Transform().position = {ScreenWidth / 2.0 + 400, 469};
    buttonSave3->OnClick([this]() {
        this->LoadSave("charlie");
    });

    Contents().push_back(audio);
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

    spic::Engine::Instance().PushScene(std::make_shared<MainScene>(_mainMenuAudio));
}

bool SaveSelectionScene::SaveExists(const std::string& saveName) const
{
    auto saves = SaveGameManager::GetAll();
    return saves.contains(saveName);
}
