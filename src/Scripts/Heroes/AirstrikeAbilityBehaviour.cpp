#include "AirstrikeAbilityBehaviour.hpp"

void game::AirstrikeAbilityBehaviour::OnStart()
{
    BehaviourScript::OnStart();
}

void game::AirstrikeAbilityBehaviour::OnUpdate()
{
    BehaviourScript::OnUpdate();
}

void game::AirstrikeAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::AirstrikeAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::AirstrikeAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
