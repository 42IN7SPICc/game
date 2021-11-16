#include "MainScene.hpp"

#include "Api.hpp"
#include "../Utils/Layer.hpp"
#include "../Factories/HeroPrefabFactory.hpp"
#include "../Scripts/common/HealthBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene()
{
    auto background = std::make_shared<spic::GameObject>("Background", "background", Layer::Background);
    background->AddComponent(std::make_shared<spic::Sprite>("resources/sprites/menu/backgrounds/mud.png", false, false, 0, 0));

    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1720, 100, "Avans Wars: WW2", "resources/fonts/capture_it.otf", 82, Alignment::left, Color::white());
    titleText->Transform().position = {100, 100};

    auto playButton = std::make_shared<spic::Button>("Play Button", "button_play", Layer::HUD, 250, 85);
    playButton->Transform().position = {100, 250};
    playButton->AddComponent(std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/play.png", false, false, 0, 0));
    playButton->OnClick([]() {
        Debug::Log("Play Button clicked");
    });

    auto exitButton = std::make_shared<spic::Button>("Quit Button", "button_quit", Layer::HUD, 250, 85);
    exitButton->Transform().position = {100, 400};
    exitButton->AddComponent(std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/exit.png", false, false, 0, 0));
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto hero = HeroPrefabFactory::CreateHero(HeroName::DesmondDoss);
    auto tempHealthText = std::make_shared<spic::Text>("healthText", "healthText", Layer::HUD, 1720, 100, "0", "resources/fonts/capture_it.otf", 82, Alignment::left, Color::white());
    tempHealthText->Transform().position = {25, 25};
    hero->AddChild(tempHealthText);

    auto healthBehaviour = hero->GetComponent<HealthBehaviour>();

    Contents().push_back(background);
    Contents().push_back(titleText);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
    Contents().push_back(tempHealthText);
    Contents().push_back(hero);
}
