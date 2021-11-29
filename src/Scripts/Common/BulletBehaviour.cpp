#include "BulletBehaviour.hpp"

#include "../../Utils/GameObjectUtil.hpp"
#include "../../Utils/PointUtil.hpp"

#include <Time.hpp>

#include <stdexcept>

using namespace game;

BulletBehaviour::BulletBehaviour(BulletType bulletType, const spic::Point& direction, double maxDuration, int maxPenetrating) : _bulletType(bulletType),
                                                                                                                                _direction(std::make_unique<spic::Point>(direction)),
                                                                                                                                _duration(0),
                                                                                                                                _maxDuration(maxDuration),
                                                                                                                                _maxPenetrating(maxPenetrating)
{
}

void BulletBehaviour::OnStart()
{
    auto parent = GameObject().lock();

    _rigidBody = parent->GetComponent<spic::RigidBody>();
    if (!_rigidBody)
    {
        _rigidBody = std::make_shared<spic::RigidBody>(1, 0, spic::BodyType::dynamicBody);
        GameObjectUtil::LinkComponent(parent, _rigidBody);
    }

    _damageBehaviour = parent->GetComponent<DamageBehaviour>();
    if (!_damageBehaviour)
    {
        throw std::runtime_error("To instantiate a bullet behaviour the game object is required to have a damage behaviour.");
    }
}

void BulletBehaviour::OnUpdate()
{
    auto parent = GameObject().lock();

    if (_damageBehaviour->ObjectsDamaged() >= (_bulletType == BulletType::Penetrating ? _maxPenetrating : 1))
    {
        spic::GameObject::Destroy(parent);
        return;
    }

    auto deltaTimeScale = spic::Time::DeltaTime() * spic::Time::TimeScale();
    auto xWithTimeScale = _direction->x * deltaTimeScale;
    auto yWithTimeScale = _direction->y * deltaTimeScale;
    _rigidBody->AddForce(spic::Point{xWithTimeScale, yWithTimeScale});

    _duration += deltaTimeScale;
    if (_duration >= _maxDuration)
    {
        spic::GameObject::Destroy(parent);
    }
}

void BulletBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    // Not implemented
}

void BulletBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    // Not implemented
}

void BulletBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    // Not implemented
}
