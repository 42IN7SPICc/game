#include "ButtonPrefabFactory.hpp"

#include "Engine.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

#include "../Scripts/Menu/CloseSceneBehaviour.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"

using namespace game;

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateOutlineButton(const std::string& name, const std::string& tag, const std::string& text, bool invert_color)
{
    auto button = std::make_shared<spic::Button>(name, tag, Layer::HUD, 250, 85);

    std::string buttonOutline = invert_color ? "outline_black.png" : "outline.png";
    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/" + buttonOutline, false, false, SortingLayer::HudButton, 0);

    auto buttonText = std::make_shared<spic::Text>(name + "_text", tag + "_text", Layer::HUD, 250, 85);
    buttonText->Content(text);
    buttonText->Size(36);
    if (invert_color)
    {
        buttonText->TextColor(spic::Color::black());
    }
    else
    {
        buttonText->TextColor(spic::Color::white());
    }
    buttonText->TextAlignment(spic::Alignment::center);

    spic::GameObjectUtil::LinkComponent(button, buttonSprite);
    spic::GameObjectUtil::LinkChild(button, buttonText);

    return button;
}

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateWideOutlineButton(const std::string& name, const std::string& tag, const std::string& text, bool invert_color)
{
    auto button = std::make_shared<spic::Button>(name, tag, Layer::HUD, 650, 85);

    std::string buttonOutline = invert_color ? "outline_wide_black.png" : "outline_wide.png";
    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/" + buttonOutline, false, false, SortingLayer::HudButton, 0);

    auto buttonText = std::make_shared<spic::Text>(name + "_text", tag + "_text", Layer::HUD, 650, 85);
    buttonText->Content(text);
    buttonText->Size(38);
    if (invert_color)
    {
        buttonText->TextColor(spic::Color::black());
    }
    else
    {
        buttonText->TextColor(spic::Color::white());
    }
    buttonText->TextAlignment(spic::Alignment::center);

    spic::GameObjectUtil::LinkComponent(button, buttonSprite);
    spic::GameObjectUtil::LinkChild(button, buttonText);

    return button;
}


std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateSquareOutlineButton(const std::string& name, const std::string& tag, const std::string& text)
{
    auto button = std::make_shared<spic::Button>(name, tag, Layer::HUD, 350, 350);
    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/outline_square.png", false, false, SortingLayer::HudButton, 0);

    auto buttonText = std::make_shared<spic::Text>(name + "_text", tag + "_text", Layer::HUD, 350, 350);
    buttonText->Content(text);
    buttonText->Size(69);
    buttonText->TextColor(spic::Color::white());
    buttonText->TextAlignment(spic::Alignment::center);

    spic::GameObjectUtil::LinkComponent(button, buttonSprite);
    spic::GameObjectUtil::LinkChild(button, buttonText);

    return button;
}

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateCloseButton(const spic::Point& position, int popAmount)
{
    auto button = std::make_shared<spic::Button>("Close Button", "button_close", Layer::HUD, 48, 48);
    button->Transform().position = position;
    button->OnClick([popAmount]() {
        for (int i = 0; i < popAmount; ++i)
        {
            spic::Engine::Instance().PopScene();
        }
    });

    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/back.png", false, false, SortingLayer::HudButton, 0);
    auto closeSceneBehaviour = std::make_shared<CloseSceneBehaviour>(popAmount);

    spic::GameObjectUtil::LinkComponent(button, buttonSprite);
    spic::GameObjectUtil::LinkComponent(button, closeSceneBehaviour);

    return button;
}

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateSwitchHeroButton(const spic::Point& position, std::function<void()> callback)
{
    auto button = std::make_shared<spic::Button>("Switch Button", "button_switch", Layer::HUD, 48, 48);
    button->Transform().position = position;
    button->OnClick(callback);

    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/back.png", false, false, SortingLayer::HudButton, 0);
    spic::GameObjectUtil::LinkComponent(button, buttonSprite);
    return button;
}
