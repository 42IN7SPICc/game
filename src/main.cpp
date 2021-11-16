#include "Api.hpp"
#include "Factories/HeroPrefabFactory.hpp"

using namespace spic;

int main(int argc, char* args[]) {
    Engine& engine = Engine::Instance();

    EngineConfig config{{"Avans Wars", 1366, 786, true}};
    engine.Init(config);

    auto scene = std::make_shared<Scene>();
    engine.PushScene(scene);

    auto hero = game::HeroPrefabFactory::CreateHero(game::HeroName::DesmondDoss);
    scene->Contents().push_back(hero);

    engine.Start();
}