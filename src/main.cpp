#include "Scripts/Common/CheatManager.hpp"
#include "Api.hpp"

using namespace spic;

int main(int argc, char* args[]) {
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, false}};
    engine.Init(config);

    auto scene = std::make_shared<Scene>();
    engine.PushScene(scene);

    auto cheats = std::make_shared<GameObject>("cheats", "default", 0);
    auto cheatManager = std::make_shared<game::CheatManager>();
    cheatManager->GameObject(cheats);
    cheats->AddComponent(cheatManager);

    auto rigidBody = std::make_shared<RigidBody>(5,5, BodyType::staticBody);
    rigidBody->GameObject(cheats);
    cheats->AddComponent(rigidBody);

    scene->Contents().push_back(cheats);

    engine.Start();
    return 0;
}