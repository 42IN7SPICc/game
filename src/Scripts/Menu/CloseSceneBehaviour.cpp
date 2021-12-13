#include "CloseSceneBehaviour.hpp"

#include "Engine.hpp"
#include "Input.hpp"

using namespace game;
using namespace spic;

CloseSceneBehaviour::CloseSceneBehaviour(int popAmount) : _popAmount(popAmount)
{
}

void CloseSceneBehaviour::OnStart()
{
}

void CloseSceneBehaviour::OnUpdate()
{
    if (Input::GetKeyUp(spic::Input::KeyCode::ESCAPE))
    {
        Engine::Instance().PopScene();
    }
}

void CloseSceneBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void CloseSceneBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void CloseSceneBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}
