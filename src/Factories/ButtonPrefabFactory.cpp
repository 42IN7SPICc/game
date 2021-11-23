#include "ButtonPrefabFactory.hpp"

#include "Engine.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

#include "../Scripts/Menu/CloseSceneBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/Layer.hpp"

using namespace game;

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateOutlineButton(const std::string& name, const std::string& tag, const std::string& text)
{
    auto button = std::make_shared<spic::Button>(name, tag, Layer::HUD, 250, 85);

    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/outline.png", false, false, 0, 0);

    auto buttonText = std::make_shared<spic::Text>(name + "_text", tag + "_text", Layer::HUD, 250, 85);
    buttonText->Content(text);
    buttonText->Size(38);
    buttonText->TextColor(spic::Color::white());
    buttonText->TextAlignment(spic::Alignment::center);

    GameObjectUtil::LinkComponent(button, buttonSprite);
    GameObjectUtil::LinkChild(button, buttonText);

    return button;
}

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateCloseButton(const spic::Point& position)
{
    auto button = std::make_shared<spic::Button>("Close Button", "button_close", Layer::HUD, 48, 48);
    button->Transform().position = position;
    button->OnClick([]() {
        spic::Engine::Instance().PopScene();
    });

    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/back.png", false, false, 0, 0);
    auto closeSceneBehaviour = std::make_shared<CloseSceneBehaviour>();

    GameObjectUtil::LinkComponent(button, buttonSprite);
    GameObjectUtil::LinkComponent(button, closeSceneBehaviour);

    return button;
}
