#include <Text.hpp>
#include "MainScene.hpp"

#include "Debug.hpp"
#include "CreditScene.hpp"
#include "HelpScene.hpp"
#include "LevelScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Utils/RandomUtil.hpp"
#include "../Utils/HeroUtil.hpp"
#include "../Scripts/Heroes/UserAttackBehaviour.hpp"
#include "../Scripts/Heroes/UserMovementBehaviour.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Enums/Font.hpp"
#include "../Constants.hpp"

#include "Engine.hpp"
#include "../Structs/PlayerData.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene() : MenuScene("Avans Wars: WW2", true)
{
    LevelSelectionController levelSelectionController{};
    levelSelectionController.InitializeLevels();

    auto mainMenuAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::MainMenu, true, true, 1.0);

    auto playButton = ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "PLAY");
    playButton->Transform().position = {225, 300};
    playButton->OnClick([levelSelectionController]() {
        auto level = levelSelectionController.GetLevelDto("welcome_to_the_war");
        auto levelWithTiles = levelSelectionController.LoadLevel(level.File);

        auto scene = std::make_shared<LevelScene>(levelWithTiles);
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

    auto backButton = ButtonPrefabFactory::CreateOutlineButton("Back Button", "button_back", "BACK");
    backButton->Transform().position = {225, 675};
    backButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto currentHero = PlayerData::Instance().SelectedHero;
    if(currentHero < DesmondDoss || currentHero > JosephStalin) { //Check if value of SelectedHero is valid
        currentHero = DesmondDoss;
    }

    auto heroNameText = std::make_shared<spic::Text>("hero-name-text","hero-name-text",SortingLayer::HudText, HeroWidth + 300, 100);
    heroNameText->Content(HeroUtil::NameToString(currentHero));
    heroNameText->TextAlignment(Alignment::center);
    heroNameText->Font(Font::CaptureIt);
    heroNameText->TextColor(Color::white());
    heroNameText->Size(45);
    heroNameText->Transform().position = { 1000.0, 430 - (HeroHeight / 2.0) };

    auto createHero = [this](HeroName currentHero) {
        auto hero = GameObject::Find("Hero");
        if(hero) GameObject::Destroy(hero);

        hero = HeroPrefabFactory::CreateHero(currentHero);
        hero->Transform().position = {1000, 460};
        hero->Transform().scale = 1;
        hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
        hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());
        Contents().push_back(hero);
    };

    createHero(currentHero);
    auto heroSwitcher = [currentHero, heroNameText, createHero](int amount) mutable {
        int heroIndex = static_cast<int>(currentHero) + amount;
        if(heroIndex > 4) heroIndex = 0;
        if(heroIndex < 0) heroIndex = 4;
        currentHero = static_cast<HeroName>(heroIndex);
        heroNameText->Content(HeroUtil::NameToString(currentHero));
        createHero(currentHero);
    };
    auto leftArrowButton = ButtonPrefabFactory::CreateSwitchHeroButton({850, 460}, [heroSwitcher]() mutable {
        heroSwitcher(-1);
    });

    auto rightArrowButton = ButtonPrefabFactory::CreateSwitchHeroButton({1150, 460}, [heroSwitcher]() mutable {
        heroSwitcher(1);
    });
    rightArrowButton->Transform().rotation = 180;

    Contents().push_back(mainMenuAudioSource);
    Contents().push_back(playButton);
    Contents().push_back(creditsButton);
    Contents().push_back(helpButton);
    Contents().push_back(backButton);
    Contents().push_back(leftArrowButton);
    Contents().push_back(rightArrowButton);
    Contents().push_back(heroNameText);
}
