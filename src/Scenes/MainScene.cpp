#include "CreditScene.hpp"
#include "HelpScene.hpp"
#include "MainScene.hpp"
#include "LevelScene.hpp"

#include "Api.hpp"

#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Utils/RandomUtil.hpp"
#include "../Scripts/Common/UserAttackBehaviour.hpp"
#include "../Scripts/Common/UserMovementBehaviour.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene() : MenuScene("Avans Wars: WW2", false)
{
    auto playButton = ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "PLAY");
    playButton->Transform().position = {225, 300};
    playButton->OnClick([]() {
        LevelSelectionController levelController{};
        levelController.InitializeLevels();

        auto level = levelController.GetLevelDto("welcome_to_the_war");

        auto scene = std::make_shared<LevelScene>(level);
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

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "EXIT");
    exitButton->Transform().position = {225, 675};
    exitButton->OnClick([]() {
        Engine::Instance().Shutdown();
    });

    auto hero = HeroPrefabFactory::CreateHero(static_cast<HeroName>(RandomUtil::Next(HeroName::DesmondDoss, HeroName::JosephStalin)));
    hero->Transform().position = {1000, 460};
    hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
    hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());

    Contents().push_back(playButton);
    Contents().push_back(creditsButton);
    Contents().push_back(helpButton);
    Contents().push_back(exitButton);
    Contents().push_back(hero);
}
