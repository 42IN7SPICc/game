#include "BulletBehaviour.hpp"

#include "../../Utils/GameObjectUtil.hpp"
#include "../../Utils/PointUtil.hpp"

#include <Time.hpp>

#include <stdexcept>

game::BulletBehaviour::BulletBehaviour(const spic::Point& direction, double maxRange) : _direction(std::make_unique<spic::Point>(direction)),
                                                                                        _maxRange{maxRange}
{
}

void game::BulletBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _rigidBody = parent->GetComponent<spic::RigidBody>();
    if (!_rigidBody)
    {
        _rigidBody = std::make_shared<spic::RigidBody>(1, 0, spic::BodyType::dynamicBody);
        game::GameObjectUtil::LinkComponent(parent, _rigidBody);
    }

    auto collider = parent->GetComponent<spic::Collider>();
    if (!collider || !collider->IsTrigger())
    {
        throw std::runtime_error("To instantiate a bullet behaviour the game object is required to have a trigger collider");
    }

    _startPos = parent->AbsoluteTransform().position;
}

void game::BulletBehaviour::OnUpdate()
{
    auto xWithTimeScale = _direction->x * spic::Time::DeltaTime() * spic::Time::TimeScale();
    auto yWithTimeScale = _direction->y * spic::Time::DeltaTime() * spic::Time::TimeScale();
    _rigidBody->AddForce(spic::Point{xWithTimeScale, yWithTimeScale});

    auto parent = GameObject().lock();
    auto distance = PointUtil::Distance(_startPos, parent->AbsoluteTransform().position);
    if (distance >= _maxRange)
    {
        spic::GameObject::Destroy(parent);
    }
}

void game::BulletBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    // Not implemented
}

void game::BulletBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    // Not implemented
}

void game::BulletBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    // Not implemented
}
