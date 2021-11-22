#include "MainScene.hpp"
#include "LevelScene.hpp"
#include "CreditScene.hpp"

#include "Api.hpp"

#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Utils/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/RandomUtil.hpp"
#include "../Scripts/Common/UserAttackBehaviour.hpp"
#include "../Scripts/Common/UserMovementBehaviour.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene()
{
    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1720, 100, "Avans Wars: WW2", "resources/fonts/capture_it.otf", 82, Alignment::left, Color::white());
    titleText->Transform().position = {100, 100};

    auto playButton = ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "PLAY", {100, 250});
    playButton->OnClick([]() {
        LevelController levelController{};
        levelController.InitializeLevels();

        auto scene = std::make_shared<LevelScene>("welcome_to_the_war", levelController);
        Engine::Instance().PushScene(scene);
    });

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "EXIT", {100, 375});
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto creditsButton = ButtonPrefabFactory::CreateOutlineButton("Credits Button", "button_credits", "CREDITS", {
            100,
            500
    });
    creditsButton->OnClick([]() {
        Engine::Instance().PushScene(std::make_shared<CreditScene>());
    });

    auto hero = HeroPrefabFactory::CreateHero(static_cast<HeroName>(RandomUtil::Next(HeroName::DesmondDoss, HeroName::JosephStalin)));
    hero->Transform().position = {900, 300};
    hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
    hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());

    Contents().push_back(BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu));

    Contents().push_back(hero);
    Contents().push_back(titleText);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
    Contents().push_back(creditsButton);
}
