#include "HealAbilityBehaviour.hpp"

void game::HealAbilityBehaviour::OnStart()
{

}

void game::HealAbilityBehaviour::OnUpdate()
{

}

void game::HealAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::HealAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::HealAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}

game::HealAbilityBehaviour::HealAbilityBehaviour() : _coolDownBehaviour(nullptr)
{

}
