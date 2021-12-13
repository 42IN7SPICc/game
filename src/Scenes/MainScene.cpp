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
#include "../Enums/SortingLayer.hpp"
#include "../Enums/Font.hpp"
#include "../HeroConstants.hpp"
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
        PlayerData::Instance().SelectedHero = currentHero;
    }

    _heroNameText = std::make_shared<spic::Text>("hero-name-text", "hero-name-text", SortingLayer::HudText, HeroWidth + 300, 100);
    _heroNameText->Content(HeroUtil::NameToString(currentHero));
    _heroNameText->TextAlignment(Alignment::center);
    _heroNameText->Font(Font::CaptureIt);
    _heroNameText->TextColor(Color::white());
    _heroNameText->Size(45);
    _heroNameText->Transform().position = {1000.0, 430 - (HeroHeight / 2.0)};

    HeroSwapper(0);

    auto leftArrowButton = ButtonPrefabFactory::CreateSwitchHeroButton({850, 460}, [this]() {
        this->HeroSwapper(-1);
    });

    auto rightArrowButton = ButtonPrefabFactory::CreateSwitchHeroButton({1150, 460}, [this]() {
        this->HeroSwapper(1);
    });
    rightArrowButton->Transform().rotation = 180;

    Contents().push_back(audio);
    Contents().push_back(playButton);
    Contents().push_back(creditsButton);
    Contents().push_back(helpButton);
    Contents().push_back(backButton);
    Contents().push_back(leftArrowButton);
    Contents().push_back(rightArrowButton);
    Contents().push_back(_heroNameText);
}

void MainScene::HeroSwapper(int amount)
{
    auto heroIndex = static_cast<int>(PlayerData::Instance().SelectedHero) + amount;
    if (heroIndex < 0) heroIndex = 4;
    if (heroIndex > 4) heroIndex = 0;
    PlayerData::Instance().SelectedHero = static_cast<HeroName>(heroIndex);

    CreateHero();
}

void MainScene::CreateHero()
{
    auto heroName = PlayerData::Instance().SelectedHero;

    _heroNameText->Content(HeroUtil::NameToString(heroName));

    auto hero = GameObject::Find("Hero");
    if (hero) GameObject::Destroy(hero);

    hero = HeroPrefabFactory::CreateHero(heroName);
    hero->Transform().position = {1000, 460};
    hero->Transform().scale = 1;
    hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
    hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());
    Contents().push_back(hero);
}
