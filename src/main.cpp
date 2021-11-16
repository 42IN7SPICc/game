#include "Api.hpp"

#include "Scenes/MainScene.hpp"

using namespace game;
using namespace spic;

int main(int argc, char* args[])
{
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, true}};
#if !NDEBUG
    config.window.fullscreen = false;
#endif
    engine.Init(config);

    auto scene = std::make_shared<MainScene>();
    engine.PushScene(scene);

    engine.Start();
}