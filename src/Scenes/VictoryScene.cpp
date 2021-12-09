#include <Engine.hpp>
#include <Color.hpp>
#include <Text.hpp>
#include <RigidBody.hpp>
#include <CircleCollider.hpp>
#include <Sprite.hpp>
#include <BehaviourScript.hpp>
#include <BoxCollider.hpp>
#include "VictoryScene.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Enums/Font.hpp"
#include "../Enums/Layer.hpp"
#include "../Utils/RandomUtil.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Factories/AudioSourcePrefabFactory.hpp"
#include "../Constants.hpp"

using namespace spic;

namespace game
{
    class ConfettiBehaviour : public spic::BehaviourScript
    {
        public:
            void OnStart() override
            {
                //
            }

            void OnUpdate() override
            {
                //
            }

            void OnTriggerEnter2D(const Collider& collider) override
            {
                if (!collider.GameObject().expired() && collider.GameObject().lock()->Tag() == "confetti_bound")
                {
                    GameObject().lock()->Transform().position.y = -25;
                    GameObject().lock()->Transform().position.x = game::RandomUtil::Next(ConfettiXRangeMin, ConfettiXRangeMax);
                }
            }

            void OnTriggerExit2D(const Collider& collider) override
            {
                //
            }

            void OnTriggerStay2D(const Collider& collider) override
            {
                //
            }
    };
}

game::VictoryScene::VictoryScene() : MenuScene("", false, BackgroundName::Victory)
{
    auto victoryAudioSource = game::AudioSourcePrefabFactory::CreateAudioObject(AudioClipName::Victory, true, true, 1.0);

    auto titleText = std::make_shared<Text>("Pause Text", "text_pause", game::Layer::HUD, 1166, 100, "VICTORY!", game::Font::Title, 64, Alignment::center, Color::white());
    titleText->Transform().position = {ScreenWidth / 2.0, 132};

    auto exitButton = game::ButtonPrefabFactory::CreateOutlineButton("Return to menu", "button_exit", "EXIT");
    exitButton->Transform().position = {ScreenWidth / 2.0, 475};
    exitButton->OnClick([]() {
        Engine::Instance().PopScene();
    });

    for (int i = 0; i < AmountOfConfetti; ++i)
    {
        Contents().push_back(GenerateConfetti());
    }

    auto bottomBound = std::make_shared<GameObject>("bottom_confetti_bound", "confetti_bound", Layer::Game);
    bottomBound->Transform().position.x = ScreenWidth / 2;
    bottomBound->Transform().position.y = -ConfettiYRangeMin;
    auto bottomBoundCollider = std::make_shared<BoxCollider>(3000, 50);
    GameObjectUtil::LinkComponent(bottomBound, bottomBoundCollider);
    GameObjectUtil::LinkComponent(bottomBound, std::make_shared<RigidBody>(1, 0, BodyType::staticBody));

    Contents().push_back(victoryAudioSource);
    Contents().push_back(titleText);
    Contents().push_back(exitButton);
    Contents().push_back(bottomBound);
}

std::shared_ptr<spic::GameObject> game::VictoryScene::GenerateConfetti()
{
    auto confettiObject = std::make_shared<GameObject>("confetti", "confetti_bound", Layer::Game);
    confettiObject->Transform().position.x = game::RandomUtil::Next(ConfettiXRangeMin, ConfettiXRangeMax);
    confettiObject->Transform().position.y = game::RandomUtil::Next(ConfettiYRangeMin, ConfettiYRangeMax);
    confettiObject->Transform().scale = game::RandomUtil::NextDouble(ConfettiMinSize, ConfettiMaxSize);

    int randomConfettiId = game::RandomUtil::Next(1, 4);
    game::GameObjectUtil::LinkComponent(confettiObject, std::make_shared<Sprite>("resources/sprites/hud/effects/confetti_" + std::to_string(randomConfettiId) + ".png", false, false, 0, 0));

    auto circleCollider = std::make_shared<CircleCollider>(1);
    circleCollider->IsTrigger(true);
    game::GameObjectUtil::LinkComponent(confettiObject, circleCollider);
    game::GameObjectUtil::LinkComponent(confettiObject, std::make_shared<RigidBody>(10, game::RandomUtil::NextDouble(ConfettiMinGravity, ConfettiMaxGravity), BodyType::dynamicBody));
    game::GameObjectUtil::LinkComponent(confettiObject, std::make_shared<game::ConfettiBehaviour>());
    return confettiObject;
}
