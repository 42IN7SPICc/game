#include "Controllers/LevelController.hpp"
#include "Engine.hpp"
#include "Utils/StringHelper.hpp"
#include "Api.hpp"

#include "Scenes/MainScene.hpp"
#include "Scenes/LevelScene.hpp"

using namespace game;
using namespace spic;
using namespace game;

int main(int argc, char* args[])
{
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, true}};
//#if !NDEBUG
//    config.window.fullscreen = false;
//#endif
    engine.Init(config);

    LevelController levelController{};
    levelController.InitializeLevels();

    auto scene = std::make_shared<LevelScene>("welcome_to_the_war", levelController);
    engine.PushScene(scene);

    engine.Start();
}
