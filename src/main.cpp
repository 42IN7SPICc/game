#include "Scripts/Common/CheatManager.hpp"
#include "Api.hpp"

using namespace spic;

int main(int argc, char* args[]) {
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, false}};
    engine.Init(config);

    auto scene = std::make_shared<Scene>();
    engine.PushScene(scene);

    scene->Contents().push_back(cheats);

    engine.Start();
    return 0;
}