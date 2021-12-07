#include <Text.hpp>
#include "MainScene.hpp"

#include "Debug.hpp"
#include "CreditScene.hpp"
#include "HelpScene.hpp"
#include "LevelSelectionScene.hpp"
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

MainScene::MainScene(const std::shared_ptr<spic::GameObject>& audio) : MenuScene("Avans Wars: WW2", true)
{
    auto playButton = ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "SPELEN");
    playButton->Transform().position = {225, 300};
    playButton->OnClick([audio]() {
        auto scene = std::make_shared<LevelSelectionScene>(audio);
        Engine::Instance().PushScene(scene);
    });

    auto helpButton = ButtonPrefabFactory::CreateOutlineButton("Help Button", "button_help", "HELP");
    helpButton->Transform().position = {225, 425};
    helpButton->OnClick([audio]() {
        Engine::Instance().PushScene(std::make_shared<HelpScene>(audio));
    });

    auto creditsButton = ButtonPrefabFactory::CreateOutlineButton("Credits Button", "button_credits", "CREDITS");
    creditsButton->Transform().position = {225, 550};
    creditsButton->OnClick([audio]() {
        Engine::Instance().PushScene(std::make_shared<CreditScene>(audio));
    });

    auto backButton = ButtonPrefabFactory::CreateOutlineButton("Back Button", "button_back", "TERUG");
    backButton->Transform().position = {225, 675};
    backButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto currentHero = PlayerData::Instance().SelectedHero;
    if (currentHero < DesmondDoss || currentHero > JosephStalin) //Check if value of SelectedHero is valid
    {
        currentHero = DesmondDoss;
    }

    auto heroNameText = std::make_shared<spic::Text>("hero-name-text", "hero-name-text", SortingLayer::HudText, HeroWidth + 300, 100);
    heroNameText->Content(HeroUtil::NameToString(currentHero));
    heroNameText->TextAlignment(Alignment::center);
    heroNameText->Font(Font::CaptureIt);
    heroNameText->TextColor(Color::white());
    heroNameText->Size(45);
    heroNameText->Transform().position = {1000.0, 430 - (HeroHeight / 2.0)};

    auto createHero = [this](HeroName currentHero) {
        auto hero = GameObject::Find("Hero");
        if (hero) GameObject::Destroy(hero);

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
        if (heroIndex > 4) heroIndex = 0;
        if (heroIndex < 0) heroIndex = 4;
        currentHero = static_cast<HeroName>(heroIndex);
        PlayerData::Instance().SelectedHero = currentHero;
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

    Contents().push_back(audio);
    Contents().push_back(playButton);
    Contents().push_back(creditsButton);
    Contents().push_back(helpButton);
    Contents().push_back(backButton);
    Contents().push_back(leftArrowButton);
    Contents().push_back(rightArrowButton);
    Contents().push_back(heroNameText);
}
