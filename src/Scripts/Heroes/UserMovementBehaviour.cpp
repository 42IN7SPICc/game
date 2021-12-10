#include "UserMovementBehaviour.hpp"

#include <Input.hpp>
#include <GameObject.hpp>
#include <RigidBody.hpp>
#include "Time.hpp"

#include "../../Constants.hpp"
#include "../../Controllers/LevelController.hpp"

#include <stdexcept>
#include <utility>

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

    auto gameObject = spic::GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        _graph = levelController->GetGraph();
    }
}

void game::UserMovementBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0)
    {
        _walkingAnimator->Stop();
        _idleAnimator->Stop();
        return;
    }

    auto parent = GameObject().lock();
    bool moving = false;
    Point movementForce{};
    double movementMultiplier = 1;
    if (_controllable)
    {
        if (Input::GetKey(Input::KeyCode::W))
        {
            movementForce.y -= _velocity;
            moving = true;
        }

        if (Input::GetKey(Input::KeyCode::S))
        {
            movementForce.y += _velocity;
            moving = true;
        }

        if (Input::GetKey(Input::KeyCode::A))
        {
            movementForce.x -= _velocity;
            moving = true;
            auto sprite = parent->GetComponent<spic::Sprite>();
            sprite->FlipX(true);
        }

        if (Input::GetKey(Input::KeyCode::D))
        {
            movementForce.x += _velocity;
            moving = true;
        }

        if (!_graph.empty())
        {
            auto enemyPosition = parent->AbsoluteTransform().position;
            double scaledTileSize = TileSize * TileMapScale;
            int tileXLocation = ((enemyPosition.x - MapX) + (scaledTileSize / 2)) / scaledTileSize;
            int tileYLocation = ((enemyPosition.y - MapY) + (scaledTileSize / 2)) / scaledTileSize;

            auto tileLocation = _graph[std::to_string(tileXLocation) + "-" + std::to_string(tileYLocation)];

            if (tileLocation.TileType == Grass)
            {
                movementMultiplier = 0.66;
            }
            else if (tileLocation.TileType == Sand)
            {
                movementMultiplier = 0.33;
            }
        }
    }

    if (moving)
    {
        movementMultiplier *= spic::Time::DeltaTime() * spic::Time::TimeScale();
        movementForce.x *= movementMultiplier;
        movementForce.y *= movementMultiplier;

        _rigidBody->AddForce(movementForce);
        _idleAnimator->Stop();
        _walkingAnimator->Play(true);
    }
    else
    {
        _walkingAnimator->Stop();
        _idleAnimator->Play(true);
    }

    parent->Transform().rotation = 0;
}

void game::UserMovementBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void game::UserMovementBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void game::UserMovementBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

bool game::UserMovementBehaviour::Controllable() const
{
    return _controllable;
}

void game::UserMovementBehaviour::Controllable(bool controllable)
{
    _controllable = controllable;
}
