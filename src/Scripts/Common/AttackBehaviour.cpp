#include "AttackBehaviour.hpp"
#include "Debug.hpp"

game::AttackBehaviour::AttackBehaviour(int attackPower)
{

}

void game::AttackBehaviour::OnStart()
{
    spic::Debug::Log("AttackBehaviour Started");
}

void game::AttackBehaviour::OnUpdate()
{
    //spic::Debug::Log("AttackBehaviour Updated");
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
