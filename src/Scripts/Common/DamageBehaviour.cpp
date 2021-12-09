#include "DamageBehaviour.hpp"

#include "GameObject.hpp"

#include "HealthBehaviour.hpp"
#include "../../Utils/PointUtil.hpp"

#include <stdexcept>
#include <Debug.hpp>

using namespace game;

DamageBehaviour::DamageBehaviour(int damage, const std::string& targetTag, int radius, int maxPenetrating) : _damage(damage),
                                                                                                             _targetTag(targetTag),
                                                                                                             _radius(radius),
                                                                                                             _objectsDamaged(0),
                                                                                                             _maxPenetrating(maxPenetrating)
{
}

void DamageBehaviour::OnStart()
{
    auto parent = GameObject().lock();

    auto collider = parent->GetComponent<spic::Collider>();
    if (!collider || !collider->IsTrigger())
    {
        throw std::runtime_error("To instantiate a damage behaviour the game object is required to have a trigger collider.");
    }
}

void DamageBehaviour::OnUpdate()
{
}

void DamageBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    if (_objectsDamaged >= _maxPenetrating) return;
    if (collider.GameObject().expired()) return;

    auto colliderGameObject = collider.GameObject().lock();

    if (!_targetTag.empty() && colliderGameObject->Tag() != _targetTag) return;

    if (_radius > 0)
    {
        auto currentPos = GameObject().lock()->AbsoluteTransform().position;
        auto gameObjects = spic::GameObject::FindGameObjectsWithTag(_targetTag);

        for (const auto& gameObject: gameObjects)
        {
            if (PointUtil::Distance(currentPos, gameObject->AbsoluteTransform().position) <= _radius)
            {
                auto healthBehaviour = gameObject->GetComponent<HealthBehaviour>();
                if (!healthBehaviour->Invincibility())
                    Damage(healthBehaviour);
            }
        }
    }
    else
    {
        auto healthBehaviour = colliderGameObject->GetComponent<HealthBehaviour>();
        if (healthBehaviour->Health() > 0 && !healthBehaviour->Invincibility())
            Damage(healthBehaviour);
    }
}

void DamageBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void DamageBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void DamageBehaviour::Damage(const std::shared_ptr<game::HealthBehaviour>& healthBehaviour)
{
    if (!healthBehaviour) return;

    spic::Debug::Log("Damaging!");
    healthBehaviour->Damage(_damage);
    _objectsDamaged++;
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

int DamageBehaviour::Radius() const
{
    return _radius;
}

void DamageBehaviour::Radius(int radius)
{
    _radius = radius;
}
