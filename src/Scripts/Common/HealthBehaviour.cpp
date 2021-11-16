#include "HealthBehaviour.hpp"

game::HealthBehaviour::HealthBehaviour(int maxHealth)
{

}

void game::HealthBehaviour::OnStart()
{
    BehaviourScript::OnStart();
}

void game::HealthBehaviour::OnUpdate()
{
    BehaviourScript::OnUpdate();
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
