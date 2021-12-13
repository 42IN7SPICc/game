#include "VictoryScene.hpp"

#include <BoxCollider.hpp>
#include <CircleCollider.hpp>
#include <Color.hpp>
#include <Engine.hpp>
#include <RigidBody.hpp>
#include <Sprite.hpp>
#include <Text.hpp>

#include "../Enums/Font.hpp"
#include "../Enums/Layer.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Scripts/Menu/ConfettiBehaviour.hpp"
#include "Utils/RandomUtil.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../Constants.hpp"
#include "../Scripts/Common/MouseColliderScript.hpp"

game::VictoryScene::VictoryScene() : MenuScene("", 0, BackgroundName::Victory)
{
    auto victoryAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::Victory, true, true, 1.0);

    auto titleText = std::make_shared<spic::Text>("Pause Text", "text_pause", game::Layer::HUD, 1166, 100, "VICTORY!", game::Font::Title, 64, spic::Alignment::center, spic::Color::white());
    titleText->Transform().position = {ScreenWidth / 2.0, 132};

    auto exitButton = game::ButtonPrefabFactory::CreateOutlineButton("Return to menu", "button_exit", "EXIT");
    exitButton->Transform().position = {ScreenWidth / 2.0, 475};
    exitButton->OnClick([]() {
        spic::Engine::Instance().PopScene();
    });
    spic::GameObjectUtil::LinkComponent(exitButton, std::make_shared<spic::BoxCollider>(exitButton->Width(), exitButton->Height()));
    spic::GameObjectUtil::LinkComponent(exitButton, std::make_shared<spic::RigidBody>(1, 0, spic::BodyType::staticBody));

    for (int i = 0; i < AmountOfConfetti; ++i)
    {
        Contents().push_back(GenerateConfetti());
    }

    auto bottomBound = std::make_shared<spic::GameObject>("bottom_confetti_bound", "confetti_bound", Layer::Game);
    bottomBound->Transform().position.x = ScreenWidth / 2;
    bottomBound->Transform().position.y = -ConfettiYRangeMin;
    auto bottomBoundCollider = std::make_shared<spic::BoxCollider>(ScreenWidth + 1000, 50);
    bottomBoundCollider->IsTrigger(true);
    spic::GameObjectUtil::LinkComponent(bottomBound, bottomBoundCollider);
    spic::GameObjectUtil::LinkComponent(bottomBound, std::make_shared<spic::RigidBody>(1, 0, spic::BodyType::staticBody));
    spic::GameObjectUtil::LinkComponent(bottomBound, std::make_shared<game::ConfettiBehaviour>());

    auto mouseCollider = std::make_shared<spic::GameObject>("mouse_collider", "mouse_collider", Layer::Game);
    auto mouseColliderScript = std::make_shared<game::MouseColliderScript>();
    spic::GameObjectUtil::LinkComponent(mouseCollider, mouseColliderScript);

    Contents().push_back(mouseCollider);
    Contents().push_back(victoryAudioSource);
    Contents().push_back(titleText);
    Contents().push_back(exitButton);
    Contents().push_back(bottomBound);
}

std::shared_ptr<spic::GameObject> game::VictoryScene::GenerateConfetti()
{
    auto confettiObject = std::make_shared<spic::GameObject>("confetti", "confetti", Layer::Game);
    confettiObject->Transform().position.x = spic::RandomUtil::Next(ConfettiXRangeMin, ConfettiXRangeMax);
    confettiObject->Transform().position.y = spic::RandomUtil::Next(ConfettiYRangeMin, ConfettiYRangeMax);
    confettiObject->Transform().scale = spic::RandomUtil::NextDouble(ConfettiMinSize, ConfettiMaxSize);

    int randomConfettiId = spic::RandomUtil::Next(1, 4);
    spic::GameObjectUtil::LinkComponent(confettiObject, std::make_shared<spic::Sprite>("resources/sprites/hud/effects/confetti_" + std::to_string(randomConfettiId) + ".png", false, false, 0, 0));

    spic::GameObjectUtil::LinkComponent(confettiObject, std::make_shared<spic::CircleCollider>(confettiObject->Transform().scale * 256));
    spic::GameObjectUtil::LinkComponent(confettiObject, std::make_shared<spic::RigidBody>(spic::RandomUtil::NextDouble(ConfettiMinGravity, ConfettiMaxGravity), 1.5, spic::BodyType::dynamicBody));
    return confettiObject;
}
