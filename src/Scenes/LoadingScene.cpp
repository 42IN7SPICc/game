#include "LoadingScene.hpp"

#include "CreditScene.hpp"
#include "SaveSelectionScene.hpp"
#include "../Constants.hpp"
#include "../Enums/Font.hpp"
#include "../Enums/Layer.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"

#include "Color.hpp"
#include "Engine.hpp"
#include "Text.hpp"

game::LoadingScene::LoadingScene() : MenuScene("", 0)
{
    auto mainMenuAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::MainMenu, true, true, 0.2);

    auto titleText = std::make_shared<spic::Text>("Game Title Text", "text_title_game", game::Layer::HUD, 1166, 100, "Avans Wars", game::Font::Title, 92, spic::Alignment::center, spic::Color::white());
    titleText->Transform().position = {ScreenWidth / 2.0, 196};

    auto subtitleText = std::make_shared<spic::Text>("Game Title Text", "text_title_game", game::Layer::HUD, 1166, 100, "WW2", game::Font::Title, 116, spic::Alignment::center, spic::Color::white());
    subtitleText->Transform().position = {ScreenWidth / 2.0, 274};

    auto playButton = game::ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "SPELEN");
    playButton->Transform().position = {ScreenWidth / 2.0, 425};
    playButton->OnClick([mainMenuAudioSource]() {
        spic::Engine::Instance().PushScene(std::make_shared<SaveSelectionScene>(mainMenuAudioSource));
    });

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "SLUITEN");
    exitButton->Transform().position = {ScreenWidth / 2.0, 550};
    exitButton->OnClick([]() {
        spic::Engine::Instance().Shutdown();
    });

    auto creditsButton = ButtonPrefabFactory::CreateOutlineButton("Credits Button", "button_credits", "CREDITS");
    creditsButton->Transform().position = {
            (creditsButton->Width() / 2) + 25, ScreenHeight - (creditsButton->Height() / 2) - 25
    };
    creditsButton->OnClick([mainMenuAudioSource]() {
        spic::Engine::Instance().PushScene(std::make_shared<CreditScene>(mainMenuAudioSource));
    });

    Contents().push_back(mainMenuAudioSource);
    Contents().push_back(titleText);
    Contents().push_back(subtitleText);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
    Contents().push_back(creditsButton);
}
