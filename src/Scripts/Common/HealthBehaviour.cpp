#include "HealthBehaviour.hpp"
#include "Debug.hpp"

game::HealthBehaviour::HealthBehaviour(int maxHealth)
{

}

void game::HealthBehaviour::OnStart()
{
    spic::Debug::Log("HealthBehaviour Started");
}

void game::HealthBehaviour::OnUpdate()
{
    //spic::Debug::Log("HealthBehaviour Updated");
}

void game::HealthBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::HealthBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::HealthBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
