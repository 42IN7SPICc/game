#include "Controllers/LevelController.hpp"
#include "Engine.hpp"
#include "Utils/StringHelper.hpp"
#include "Api.hpp"

#include "Scenes/MainScene.hpp"

using namespace game;
using namespace spic;
using namespace game;

int main(int argc, char* args[])
{
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, true}};
#if !NDEBUG
    config.window.fullscreen = false;
#endif
    engine.Init(config);

    auto levelScene = std::make_shared<Scene>();

    LevelController levelController {};
    levelController.InitializeLevels();

    levelScene->Contents().push_back(levelController.GetLevel("welcome_to_the_war"));

    auto scene = std::make_shared<MainScene>();
    engine.PushScene(scene);

    engine.Start();
}
