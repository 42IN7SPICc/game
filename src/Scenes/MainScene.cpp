#include "MainScene.hpp"

#include "CreditScene.hpp"
#include "HelpScene.hpp"
#include "LevelScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Utils/RandomUtil.hpp"
#include "../Scripts/Heroes/UserAttackBehaviour.hpp"
#include "../Scripts/Heroes/UserMovementBehaviour.hpp"

#include "Engine.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene(const std::shared_ptr<spic::GameObject>& audio) : MenuScene("Avans Wars: WW2", true)
{
    LevelSelectionController levelSelectionController{};
    levelSelectionController.InitializeLevels();

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
    helpButton->OnClick([audio]() {
        Engine::Instance().PushScene(std::make_shared<HelpScene>(audio));
    });

    auto creditsButton = ButtonPrefabFactory::CreateOutlineButton("Credits Button", "button_credits", "CREDITS");
    creditsButton->Transform().position = {225, 550};
    creditsButton->OnClick([audio]() {
        Engine::Instance().PushScene(std::make_shared<CreditScene>(audio));
    });

    auto backButton = ButtonPrefabFactory::CreateOutlineButton("Back Button", "button_back", "BACK");
    backButton->Transform().position = {225, 675};
    backButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto hero = HeroPrefabFactory::CreateHero(static_cast<HeroName>(RandomUtil::Next(HeroName::DesmondDoss, HeroName::JosephStalin)));
    hero->Transform().position = {1000, 460};
    hero->Transform().scale = 1;
    hero->GetComponent<UserMovementBehaviour>()->Controllable(false);
    hero->RemoveComponent(hero->GetComponent<UserAttackBehaviour>());

    Contents().push_back(audio);
    Contents().push_back(playButton);
    Contents().push_back(creditsButton);
    Contents().push_back(helpButton);
    Contents().push_back(backButton);
    Contents().push_back(hero);
}
