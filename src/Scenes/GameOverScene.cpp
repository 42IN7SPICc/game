#include <Text.hpp>
#include <Engine.hpp>
#include "GameOverScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/Font.hpp"

using namespace spic;

game::GameOverScene::GameOverScene() : MenuScene("", false, BackgroundName::GameOver)
{
    auto gameOverAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::GameOver, true, true, 1.0);

    auto titleText = std::make_shared<Text>("Game Over Text", "text_pause", game::Layer::HUD, 1166, 100, "GAME OVER!", game::Font::Title, 64, Alignment::center, Color::white());
    titleText->Transform().position = {683, 132};

    auto exitButton = game::ButtonPrefabFactory::CreateOutlineButton("Return to menu", "button_exit", "EXIT");
    exitButton->Transform().position = {683, 475};
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    Contents().push_back(gameOverAudioSource);
    Contents().push_back(titleText);
    Contents().push_back(exitButton);
}
