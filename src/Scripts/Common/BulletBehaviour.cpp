#include "BulletBehaviour.hpp"
#include <Time.hpp>
#include "../../Utils/GameObjectUtil.hpp"
#include <stdexcept>

void game::BulletBehaviour::OnStart()
{
    _parent = GameObject().lock();
    if (!_parent)
    {
        throw std::runtime_error("The parent game object could not be found");
    }

    _rigidBody = _parent->GetComponent<spic::RigidBody>();
    if (!_rigidBody)
    {
        _rigidBody = std::make_shared<spic::RigidBody>(1, 0, spic::BodyType::dynamicBody);
        game::GameObjectUtil::LinkComponent(_parent, _rigidBody);
    }

    auto collider = _parent->GetComponent<spic::Collider>();
    if (!collider)
    {
        throw std::runtime_error("To instantiate a bullet behaviour the game object is required to have a collider");
    }
}

void game::BulletBehaviour::OnUpdate()
{
    auto xWithTimeScale = _direction->x * spic::Time::DeltaTime() * spic::Time::TimeScale();
    auto yWithTimeScale = _direction->y * spic::Time::DeltaTime() * spic::Time::TimeScale();
    _rigidBody->AddForce(spic::Point{xWithTimeScale, yWithTimeScale});
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

game::BulletBehaviour::BulletBehaviour(const spic::Point& direction) : _direction(std::make_unique<spic::Point>(direction))
{
}
