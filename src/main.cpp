#include "Engine.hpp"
#include "GameObject.hpp"
#include "scripts/common/UserMovementBehaviour.hpp"
#include <memory>
#include <Sprite.hpp>

using namespace spic;

int main(int argc, char* args[]) {
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, false}};
    engine.Init(config);

    auto scene = std::make_shared<Scene>();
    engine.PushScene(scene);

    auto player = std::make_shared<GameObject>("character", "player", 0);
    scene->Contents().push_back(player);

    auto sprite = std::make_shared<spic::Sprite>("", false, false, 0, 0);
    sprite->GameObject(player);
    player->AddComponent(sprite);

    auto movementBehaviour = std::make_shared<game::UserMovementBehaviour>(1.5);
    movementBehaviour->GameObject(player);
    player->AddComponent(movementBehaviour);

    engine.Start();
}