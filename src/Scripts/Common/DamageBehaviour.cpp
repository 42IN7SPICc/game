#include "DamageBehaviour.hpp"

#include "GameObject.hpp"

#include "HealthBehaviour.hpp"

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
    if (collider.GameObject().expired()) return;

    auto colliderGameObject = collider.GameObject().lock();

    auto healthBehaviour = colliderGameObject->GetComponent<HealthBehaviour>();
    if (!healthBehaviour) return;

    healthBehaviour->Damage(_damage);

    spic::GameObject::Destroy(GameObject().lock());
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
