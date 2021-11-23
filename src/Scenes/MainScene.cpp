#include "MainScene.hpp"
#include "LevelScene.hpp"
#include "CreditScene.hpp"

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
    playButton->Transform().position = {100, 250};
    playButton->OnClick([]() {
        LevelController levelController{};
        levelController.InitializeLevels();

        auto scene = std::make_shared<LevelScene>("welcome_to_the_war", levelController);
        Engine::Instance().PushScene(scene);
    });

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "EXIT");
    exitButton->Transform().position = {100, 375};
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto creditsButton = ButtonPrefabFactory::CreateOutlineButton("Credits Button", "button_credits", "CREDITS");
    creditsButton->Transform().position = {100, 500};
    creditsButton->OnClick([]() {
        Engine::Instance().PushScene(std::make_shared<CreditScene>());
    });

    auto hero = HeroPrefabFactory::CreateHero(static_cast<HeroName>(RandomUtil::Next(HeroName::DesmondDoss, HeroName::JosephStalin)));
    hero->Transform().position = {900, 300};
    hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
    hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());

    Contents().push_back(hero);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
    Contents().push_back(creditsButton);
}
