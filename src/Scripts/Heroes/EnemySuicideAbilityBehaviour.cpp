#include "EnemySuicideAbilityBehaviour.hpp"

void game::EnemySuicideAbilityBehaviour::OnStart()
{
    BehaviourScript::OnStart();
}

void game::EnemySuicideAbilityBehaviour::OnUpdate()
{
    BehaviourScript::OnUpdate();
}

void game::EnemySuicideAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::EnemySuicideAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::EnemySuicideAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
