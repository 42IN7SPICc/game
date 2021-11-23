#include "BackgroundPrefabFactory.hpp"

#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/Layer.hpp"

#include "Sprite.hpp"

using namespace game;

std::shared_ptr<spic::GameObject> BackgroundPrefabFactory::CreateBackground(BackgroundName backgroundName)
{
    auto background = std::make_shared<spic::GameObject>("Background", "background", Layer::Background);
    background->Transform().position = {683, 384};

    std::string imageSrc{};
    switch (backgroundName)
    {
        case BackgroundName::Menu:
            imageSrc = "mud";
            break;
        case BackgroundName::Pause:
            imageSrc = "mud";
            break;
    }

    auto backgroundSprite = std::make_shared<spic::Sprite>("resources/sprites/menu/backgrounds/" + imageSrc + ".png", false, false, 0, 0);

    GameObjectUtil::LinkComponent(background, backgroundSprite);

    return background;
}