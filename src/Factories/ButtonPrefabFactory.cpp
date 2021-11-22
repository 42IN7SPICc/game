#include "ButtonPrefabFactory.hpp"

#include "Sprite.hpp"
#include "Text.hpp"

#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/Layer.hpp"

using namespace game;

std::shared_ptr<spic::Button> ButtonPrefabFactory::CreateButton(const std::string& name, const std::string& tag, const std::string& text, const spic::Point position)
{
    auto button = std::make_shared<spic::Button>(name, tag, Layer::HUD, 250, 85);
    button->Transform().position = position;

    auto buttonSprite = std::make_shared<spic::Sprite>("resources/sprites/hud/buttons/outline.png", false, false, 0, 0);

    auto buttonText = std::make_shared<spic::Text>(name + "_text", tag + "_text", Layer::HUD, 250, 85);
    buttonText->Content(text);
    buttonText->Size(38);
    buttonText->TextColor(spic::Color::white());
    buttonText->TextAlignment(spic::Alignment::center);

    buttonText->Transform().position.y = (button->Height() - buttonText->Size()) / 2;

    GameObjectUtil::LinkComponent(button, buttonSprite);
    GameObjectUtil::LinkChild(button, buttonText);

    return button;
}