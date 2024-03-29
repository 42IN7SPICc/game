#include "HealthBarFactory.hpp"

#include "Sprite.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Hud/HealthBarBehaviour.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../Constants.hpp"

#include <stdexcept>

using namespace game;

std::shared_ptr<spic::GameObject> HealthBarFactory::CreateHealthBar(std::shared_ptr<spic::GameObject> target)
{
    auto healthBehaviour = target->GetComponent<HealthBehaviour>();
    if (!healthBehaviour)
    {
        throw std::runtime_error("The target does not have a HealthBehaviour script.");
    }

    auto objectName = "HealthBar " + target->Name();

    auto healthBar = std::make_shared<spic::GameObject>(objectName, "healthbar", Layer::HUD);
    auto healthBarBackground = std::make_shared<spic::Sprite>("resources/sprites/hud/health/background.png", false, false, SortingLayer::HudBackground, 10);

    spic::GameObjectUtil::LinkComponent(healthBar, std::make_shared<HealthBarBehaviour>(healthBehaviour));
    spic::GameObjectUtil::LinkComponent(healthBar, healthBarBackground);

    auto chunkObjectName = objectName + " Chunk";
    for (int i = 0; i < HealthBarChunks; ++i)
    {
        auto healthBarChunk = std::make_shared<spic::GameObject>(chunkObjectName + std::to_string(i), "healthbarchunk", Layer::HUD);
        healthBarChunk->Transform().position = {i * 8 - 36.0, 0};

        spic::GameObjectUtil::LinkComponent(healthBarChunk, std::make_shared<spic::Sprite>("resources/sprites/hud/health/chunk.png", spic::Color::green(), false, false, SortingLayer::HudText, 1));
        spic::GameObjectUtil::LinkChild(healthBar, healthBarChunk);
    }

    return healthBar;
}