#include "UserMovementBehaviour.hpp"
#include <Debug.hpp>
#include <RigidBody.hpp>
#include <Input.hpp>
#include <utility>
#include <GameObject.hpp>
#include <stdexcept>

using namespace spic;

void game::UserMovementBehaviour::OnStart()
{
    _parent = GameObject().lock();
    _rigidBody = _parent->GetComponent<spic::RigidBody>();

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
    bool moving = false;
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

    }

    if (Input::GetKey(Input::KeyCode::D))
    {
        _rigidBody->AddForce(spic::Point{_velocity, 0});
        moving = true;
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

game::UserMovementBehaviour::UserMovementBehaviour(float velocity, std::shared_ptr<spic::Animator> idleAnimator, std::shared_ptr<spic::Animator> walkingAnimator) : _velocity(velocity),
                                                                                                                                                                    _idleAnimator(std::move(idleAnimator)),
                                                                                                                                                                    _walkingAnimator(std::move(walkingAnimator))
{
}