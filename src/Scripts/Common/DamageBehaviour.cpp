#include <Debug.hpp>
#include "DamageBehaviour.hpp"

using namespace game;

void DamageBehaviour::OnStart()
{
//    spic::Debug::Log("On start");
}

void DamageBehaviour::OnUpdate()
{
    // Not implemented
}

void DamageBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
//    spic::Debug::Log("Not implemented");
}

void DamageBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
//    spic::Debug::Log("Not implemented");
}

void DamageBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
//    spic::Debug::Log("Not implemented");
}

DamageBehaviour::DamageBehaviour(int damage) : _damage(damage)
{
}
