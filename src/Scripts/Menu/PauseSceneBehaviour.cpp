#include "PauseSceneBehaviour.hpp"

#include "Engine.hpp"
#include "Input.hpp"

#include "../../Scenes/PauseScene.hpp"

#include <memory>

using namespace game;
using namespace spic;

void PauseSceneBehaviour::OnStart()
{
}

void PauseSceneBehaviour::OnUpdate()
{
    if (Input::GetKeyUp(spic::Input::KeyCode::ESCAPE))
    {
        Engine::Instance().PushScene(std::make_shared<PauseScene>());
    }
}

void PauseSceneBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void PauseSceneBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void PauseSceneBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}