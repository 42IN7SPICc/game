#include "MainScene.hpp"

#include "Api.hpp"
#include "../Utils/Layer.hpp"
#include "../Utils/GameObjectUtil.hpp"

using namespace spic;
using namespace game;

MainScene::MainScene()
{
    auto background = std::make_shared<spic::GameObject>("Background", "background", Layer::Background);
    GameObjectUtil::LinkComponent(background, std::make_shared<spic::Sprite>("resources/sprites/menu/backgrounds/mud.png", false, false, 0, 0));

    auto titleText = std::make_shared<spic::Text>("Title Text", "text_title", Layer::HUD, 1720, 100, "Avans Wars: WW2", "resources/fonts/capture_it.otf", 82, Alignment::left, Color::white());
    titleText->Transform().position = {100, 100};

    auto playButton = std::make_shared<spic::Button>("Play Button", "button_play", Layer::HUD, 250, 85);
    playButton->Transform().position = {100, 250};
    playButton->OnClick([]() {
        Debug::Log("Play Button clicked");
    });
    GameObjectUtil::LinkComponent(playButton, std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/play.png", false, false, 0, 0));

    auto exitButton = std::make_shared<spic::Button>("Quit Button", "button_quit", Layer::HUD, 250, 85);
    exitButton->Transform().position = {100, 400};
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
    });
    GameObjectUtil::LinkComponent(exitButton, std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/exit.png", false, false, 0, 0));

    Contents().push_back(background);
    Contents().push_back(titleText);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
}
