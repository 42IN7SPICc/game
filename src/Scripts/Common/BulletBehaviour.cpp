#include "BulletBehaviour.hpp"
#include <stdexcept>

void game::BulletBehaviour::OnStart()
{
    _parent = GameObject().lock();
    if (!_parent) {
        throw std::runtime_error("The parent game object could not be found");
    }
}

void game::BulletBehaviour::OnUpdate()
{

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
