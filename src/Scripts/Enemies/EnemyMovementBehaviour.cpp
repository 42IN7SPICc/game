#include "EnemyMovementBehaviour.hpp"

#include "../../Controllers/LevelController.hpp"
#include "../../Utils/StringUtil.hpp"
#include "../../Utils/PointUtil.hpp"

#include "GameObject.hpp"

#include <stdexcept>

using namespace game;

const double TileSize = 32;
const double TileMapScale = 0.985;
const int MapX = TileSize / 2 + 155;
const int MapY = TileSize / 2;

EnemyMovementBehaviour::EnemyMovementBehaviour(std::shared_ptr<spic::Animator> walkingAnimator) : _walkingAnimator(walkingAnimator)
{
}

bool CanWalk(TileType tileType)
{
    return tileType == TileType::Street || tileType == TileType::Grass || tileType == TileType::Sand || tileType == TileType::Bridge;
}

void EnemyMovementBehaviour::OnStart()
{
    auto parent = GameObject().lock();

    _healthBehaviour = parent->GetComponent<HealthBehaviour>();
    if (!_healthBehaviour)
    {
        throw std::runtime_error("No HealthBehaviour found on the enemy.");
    }
    _rigidBody = parent->GetComponent<spic::RigidBody>();
    if (!_rigidBody)
    {
        throw std::runtime_error("No RigidBody found on the enemy.");
    }
    _sprite = parent->GetComponent<spic::Sprite>();
    if (!_sprite)
    {
        throw std::runtime_error("No Sprite found on the enemy.");
    }

    auto gameObject = spic::GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        _graph = levelController->GetGraph();
        _path = levelController->GetPath();
    }
}

void EnemyMovementBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0)
    {
        _walkingAnimator->Stop();
        return;
    }

    auto parent = GameObject().lock();

    auto enemyPosition = parent->AbsoluteTransform().position;
    double scaledTileSize = TileSize * TileMapScale;
    int tileXLocation = ((enemyPosition.x - MapX) + (scaledTileSize / 2)) / scaledTileSize;
    int tileYLocation = ((enemyPosition.y - MapY) + (scaledTileSize / 2)) / scaledTileSize;

    auto tileLocation = _graph[std::to_string(tileXLocation) + "-" + std::to_string(tileYLocation)];

    if (_path.empty()) return;

    double speedMultiplier = 1.0;
    if (tileLocation.TileType == TileType::Grass)
    {
        speedMultiplier = 0.66;
    }
    else if (tileLocation.TileType == TileType::Sand)
    {
        speedMultiplier = 0.33;
    }

    speedMultiplier *= 5;

    auto toLocation = _graph[_path.front()];

    double distance;
    auto force = PointUtil::CalculateDirectionalPoint(enemyPosition, toLocation.TileObject->AbsoluteTransform().position, speedMultiplier, distance);

    _rigidBody->AddForce(force);

    if (distance <= 2)
    {
        _path.pop();
    }

    _walkingAnimator->Play(true);
    _sprite->FlipX(force.x < 0);
    parent->Transform().rotation = 0;
}

void EnemyMovementBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void EnemyMovementBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void EnemyMovementBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}