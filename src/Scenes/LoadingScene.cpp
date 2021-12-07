#include "LoadingScene.hpp"

#include "../Enums/Font.hpp"
#include "../Enums/Layer.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"

#include "Color.hpp"
#include "Engine.hpp"
#include "Text.hpp"

game::LoadingScene::LoadingScene() : MenuScene("", false)
{
    auto titleText = std::make_shared<spic::Text>("Game Title Text", "text_title_game", game::Layer::HUD, 1166, 100, "Avans Wars", game::Font::Title, 92, spic::Alignment::center, spic::Color::white());
    titleText->Transform().position = {683, 196};

    auto subtitleText = std::make_shared<spic::Text>("Game Title Text", "text_title_game", game::Layer::HUD, 1166, 100, "WW2", game::Font::Title, 116, spic::Alignment::center, spic::Color::white());
    subtitleText->Transform().position = {683, 274};

    auto playButton = game::ButtonPrefabFactory::CreateOutlineButton("Play Button", "button_play", "PLAY");
    playButton->Transform().position = {683, 425};
    playButton->OnClick([]() {
    });

    auto exitButton = ButtonPrefabFactory::CreateOutlineButton("Exit Button", "button_exit", "EXIT");
    exitButton->Transform().position = {683, 550};
    exitButton->OnClick([]() {
        spic::Engine::Instance().Shutdown();
    });

    Contents().push_back(titleText);
    Contents().push_back(subtitleText);
    Contents().push_back(playButton);
    Contents().push_back(exitButton);
}
