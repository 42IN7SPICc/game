#include "DamageBehaviour.hpp"

#include "GameObject.hpp"

#include "HealthBehaviour.hpp"

using namespace game;

DamageBehaviour::DamageBehaviour(int damage, const std::string& targetTag) : _damage(damage),
                                                                             _targetTag(targetTag),
                                                                             _objectsDamaged(0)
{
}

void DamageBehaviour::OnStart()
{
}

void DamageBehaviour::OnUpdate()
{
}

void DamageBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    if (collider.GameObject().expired()) return;

    auto colliderGameObject = collider.GameObject().lock();

    if (!_targetTag.empty() && colliderGameObject->Tag() != _targetTag) return;

    auto healthBehaviour = colliderGameObject->GetComponent<HealthBehaviour>();
    if (!healthBehaviour) return;

    healthBehaviour->Damage(_damage);
    _objectsDamaged++;
}

void DamageBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void DamageBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

int DamageBehaviour::Damage() const
{
    return _damage;
}

void DamageBehaviour::Damage(int damage)
{
    _damage = damage;
}

const std::string& DamageBehaviour::TargetTag() const
{
    return _targetTag;
}

void DamageBehaviour::TargetTag(const std::string& targetTag)
{
    _targetTag = targetTag;
}

int DamageBehaviour::ObjectsDamaged() const
{
    return _objectsDamaged;
}