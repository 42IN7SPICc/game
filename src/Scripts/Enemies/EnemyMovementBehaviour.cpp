#include <RigidBody.hpp>
#include "EnemyMovementBehaviour.hpp"
#include "GameObject.hpp"
#include "Animator.hpp"
#include "../../Controllers/LevelController.hpp"
#include "../../Utils/StringUtil.hpp"
#include "../../Utils/PointUtil.hpp"

using namespace game;

const double TileSize = 32;
const double TileMapScale = 0.985;
const int MapX = TileSize / 2 + 155;
const int MapY = TileSize / 2;

bool CanWalk(TileType tileType)
{
    return tileType == TileType::Street || tileType == TileType::Grass || tileType == TileType::Sand || tileType == TileType::Bridge;
}

void EnemyMovementBehaviour::OnStart()
{
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
    auto parent = GameObject().lock();
    auto walkingAnimator = parent->GetComponents<spic::Animator>()[1];
    if (parent->GetComponent<HealthBehaviour>()->Health() <= 0)
    {
        walkingAnimator->Stop();
        return;
    }

    auto enemyPosition = parent->Transform().position;
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

    GameObject().lock()->GetComponent<spic::RigidBody>()->AddForce(force);

    if (distance <= 2)
    {
        _path.pop();
    }

    walkingAnimator->Play(true);
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