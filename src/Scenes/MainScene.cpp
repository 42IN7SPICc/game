#include "MainScene.hpp"

#include "CreditScene.hpp"
#include "HelpScene.hpp"
#include "LevelSelectionScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Utils/RandomUtil.hpp"
#include "../Scripts/Heroes/UserAttackBehaviour.hpp"
#include "../Scripts/Heroes/UserMovementBehaviour.hpp"
#include "../Controllers/SaveGameController.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"

#include "Engine.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene() : MenuScene("Avans Wars: WW2", false)
{
    SaveGameController saveGameController{};
    saveGameController.InitializeSaves();
    saveGameController.Load("save1");

    auto mainMenuAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::MainMenu, true, true, 1.0);

    auto playButton = ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "SPELEN");
    playButton->Transform().position = {225, 300};
    playButton->OnClick([]() {
        auto scene = std::make_shared<LevelSelectionScene>();
        Engine::Instance().PushScene(scene);
    });

    auto helpButton = ButtonPrefabFactory::CreateOutlineButton("Help Button", "button_help", "HELP");
    helpButton->Transform().position = {225, 425};
    helpButton->OnClick([]() {
        Engine::Instance().PushScene(std::make_shared<HelpScene>());
    });

    auto creditsButton = ButtonPrefabFactory::CreateOutlineButton("Credits Button", "button_credits", "CREDITS");
    creditsButton->Transform().position = {225, 550};
    creditsButton->OnClick([]() {
        Engine::Instance().PushScene(std::make_shared<CreditScene>());
    });

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "SLUITEN");
    exitButton->Transform().position = {225, 675};
    exitButton->OnClick([&saveGameController]() {
        saveGameController.Save();
        Engine::Instance().Shutdown();
    });

    auto hero = HeroPrefabFactory::CreateHero(static_cast<HeroName>(RandomUtil::Next(HeroName::DesmondDoss, HeroName::JosephStalin)));
    hero->Transform().position = {1000, 460};
    hero->Transform().scale = 1;
    hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
    hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());

    Contents().push_back(mainMenuAudioSource);
    Contents().push_back(playButton);
    Contents().push_back(creditsButton);
    Contents().push_back(helpButton);
    Contents().push_back(exitButton);
    Contents().push_back(hero);
}
