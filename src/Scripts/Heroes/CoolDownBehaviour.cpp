#include "CoolDownBehaviour.hpp"

game::CoolDownBehaviour::CoolDownBehaviour(int coolDown) : _coolDown(coolDown)
{

}

void game::CoolDownBehaviour::OnStart()
{

}

void game::CoolDownBehaviour::OnUpdate()
{

}

void game::CoolDownBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::CoolDownBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::CoolDownBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
