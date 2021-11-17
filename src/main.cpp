#include "Controllers/LevelController.hpp"
#include "Engine.hpp"
#include "Utils/StringHelper.hpp"

using namespace spic;
using namespace game;

int main(int argc, char* args[]) {
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, true}};
    engine.Init(config);

    auto scene = std::make_shared<Scene>();

    LevelController levelController {};
    levelController.InitializeLevels();

    scene->Contents().push_back(levelController.GetLevel("welcome_to_the_war"));

    engine.PushScene(scene);

    engine.Start();
}