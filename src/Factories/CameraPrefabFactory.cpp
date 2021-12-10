#include "CameraPrefabFactory.hpp"

#include "Engine.hpp"

using namespace game;

std::shared_ptr<spic::Camera> CameraPrefabFactory::CreateCamera(const spic::Color& backgroundColor)
{
    auto config = spic::Engine::Instance().Config();
    auto camera = std::make_shared<spic::Camera>("Camera", 1, spic::Color::black(), 1366, 768);
    camera->Transform().position.x = config.window.width / 2.0;
    camera->Transform().position.y = config.window.height / 2.0;

    return camera;
}
