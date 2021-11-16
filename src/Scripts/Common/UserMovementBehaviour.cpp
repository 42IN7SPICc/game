#include <Debug.hpp>
#include <RigidBody.hpp>
#include <Input.hpp>
#include <utility>
#include "UserMovementBehaviour.hpp"
#include "GameObject.hpp"

using namespace spic;

void game::UserMovementBehaviour::OnStart()
{
    _parent = GameObject().lock();

    _rigidBody = _parent->GetComponent<spic::RigidBody>();
    if (!_rigidBody)
    {
        _rigidBody = std::make_shared<spic::RigidBody>(1, 0, BodyType::dynamicBody);
        _parent->AddComponent(_rigidBody);
        _rigidBody->GameObject(_parent);
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