#include "AttackBehaviour.hpp"

game::AttackBehaviour::AttackBehaviour(int attackPower)
{

}

void game::AttackBehaviour::OnStart()
{
    BehaviourScript::OnStart();
}

void game::AttackBehaviour::OnUpdate()
{
    BehaviourScript::OnUpdate();
}

void game::AttackBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::AttackBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::AttackBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
