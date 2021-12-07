#include "InvisibilityAbilityBehaviour.hpp"

void game::InvisibilityAbilityBehaviour::OnStart()
{
    BehaviourScript::OnStart();
}

void game::InvisibilityAbilityBehaviour::OnUpdate()
{
    BehaviourScript::OnUpdate();
}

void game::InvisibilityAbilityBehaviour::OnTriggerEnter2D(const Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::InvisibilityAbilityBehaviour::OnTriggerExit2D(const Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::InvisibilityAbilityBehaviour::OnTriggerStay2D(const Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
