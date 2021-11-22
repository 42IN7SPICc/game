#include "UserMovementBehaviour.hpp"
#include <Debug.hpp>
#include <RigidBody.hpp>
#include <Input.hpp>
#include <utility>
#include <GameObject.hpp>
#include <stdexcept>

using namespace spic;

game::UserMovementBehaviour::UserMovementBehaviour(float velocity, std::shared_ptr<spic::Animator> idleAnimator, std::shared_ptr<spic::Animator> walkingAnimator, std::shared_ptr<game::HealthBehaviour> healthBehaviour) : _velocity(velocity),
                                                                                                                                                                                                                            _controllable(true),
                                                                                                                                                                                                                            _idleAnimator(std::move(idleAnimator)),
                                                                                                                                                                                                                            _walkingAnimator(std::move(walkingAnimator)),
                                                                                                                                                                                                                            _healthBehaviour(std::move(healthBehaviour))
{
}

void game::UserMovementBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _rigidBody = parent->GetComponent<spic::RigidBody>();

    if (!_walkingAnimator)
    {
        throw std::runtime_error("The user movement behaviour script requires the parent to have a valid walking animator.");
    }

    if (!_idleAnimator)
    {
        throw std::runtime_error("The user movement behaviour script requires the parent to have a valid idle animator.");
    }

    if (!_rigidBody)
    {
        throw std::runtime_error("The user movement behaviour script requires the parent to have a rigidbody.");
    }
}

void game::UserMovementBehaviour::OnUpdate()
{
    auto parent = GameObject().lock();
    if (_healthBehaviour->Health() <= 0)
    {
        _walkingAnimator->Stop();
        _idleAnimator->Stop();
        return;
    }

    bool moving = false;
    if (_controllable)
    {
        if (Input::GetKey(Input::KeyCode::W))
        {
            _rigidBody->AddForce(spic::Point{0, -_velocity});
            moving = true;
        }

        if (Input::GetKey(Input::KeyCode::S))
        {
            _rigidBody->AddForce(spic::Point{0, _velocity});
            moving = true;
        }

        if (Input::GetKey(Input::KeyCode::A))
        {
            _rigidBody->AddForce(spic::Point{-_velocity, 0});
            moving = true;
            auto sprite = parent->GetComponent<spic::Sprite>();
            sprite->FlipX(true);
        }

        if (Input::GetKey(Input::KeyCode::D))
        {
            _rigidBody->AddForce(spic::Point{_velocity, 0});
            moving = true;
        }
    }

    if (moving)
    {
        _idleAnimator->Stop();
        _walkingAnimator->Play(true);
    }
    else
    {
        _walkingAnimator->Stop();
        _idleAnimator->Play(true);
    }
}

void game::UserMovementBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    Debug::LogWarning("Not implemented");
}

void game::UserMovementBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    Debug::LogWarning("Not implemented");
}

void game::UserMovementBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    Debug::LogWarning("Not implemented");
}

bool game::UserMovementBehaviour::Controllable() const
{
    return _controllable;
}

void game::UserMovementBehaviour::Controllable(bool controllable)
{
    _controllable = controllable;
}
