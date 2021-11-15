#include "Engine.hpp"
#include "GameObject.hpp"
#include "scripts/common/CheatManager.hpp"

using namespace spic;

int main(int argc, char* args[]) {
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, true}};
    engine.Init(config);

    auto scene = std::make_shared<Scene>();
    engine.PushScene(scene);

    auto cheats = std::make_shared<GameObject>("cheats", "default", 0);
    auto cheatManager = std::make_shared<CheatManager>();
    cheatManager->GameObject(cheats);
    cheats->AddComponent(cheatManager);

    scene->Contents().push_back(cheats);

    engine.Start();
    return 0;
}