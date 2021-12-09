#include "LoadingScene.hpp"

#include "SaveSelectionScene.hpp"
#include "../Enums/Font.hpp"
#include "../Enums/Layer.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"

#include "Color.hpp"
#include "Engine.hpp"
#include "Text.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Constants.hpp"

game::LoadingScene::LoadingScene() : MenuScene("", false)
{
    auto mainMenuAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::MainMenu, true, true, 1.0);

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

    Contents().push_back(mainMenuAudioSource);
    Contents().push_back(titleText);
    Contents().push_back(subtitleText);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
}
