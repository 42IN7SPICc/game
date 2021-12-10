#include "PauseScene.hpp"

#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/Font.hpp"

#include "Engine.hpp"
#include "Text.hpp"
#include "../Constants.hpp"

using namespace game;
using namespace spic;

PauseScene::PauseScene() : MenuScene("", true, BackgroundName::Pause)
{
    auto titleText = std::make_shared<Text>("Pause Text", "text_pause", Layer::HUD, 1166, 100, "PAUSE", Font::Title, 64, Alignment::center, Color::white());
    titleText->Transform().position = {ScreenWidth / 2.0, 132};

    auto resumeButton = ButtonPrefabFactory::CreateOutlineButton("Resume Button", "button_resume", "RESUME");
    resumeButton->Transform().position = {ScreenWidth / 2.0, 350};
    resumeButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "EXIT");
    exitButton->Transform().position = {ScreenWidth / 2.0, 475};
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
        Engine::Instance().PopScene();
    });

    Contents().push_back(titleText);
    Contents().push_back(resumeButton);
    Contents().push_back(exitButton);
}