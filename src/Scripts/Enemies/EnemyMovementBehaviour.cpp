#include "EnemyMovementBehaviour.hpp"
#include "GameObject.hpp"
#include "Animator.hpp"
#include "../../Controllers/LevelController.hpp"
#include "../../Utils/StringUtil.hpp"

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
    if (parent->GetComponent<HealthBehaviour>()->Health() == 0)
    {
        walkingAnimator->Stop();
        return;
    }

    auto playerPosition = parent->Transform().position;
    double scaledTileSize = TileSize * TileMapScale;
    int playerXLocation = ((playerPosition.x - MapX) + (scaledTileSize / 2)) / scaledTileSize;
    int playerYLocation = ((playerPosition.y - MapY) + (scaledTileSize / 2)) / scaledTileSize;

    auto playerLocation = _graph[std::to_string(playerXLocation) + "-" + std::to_string(playerYLocation)];

    if(_path.empty()) return;

    double speedMultiplier = 1.0;
    if(playerLocation.TileType == TileType::Grass) {
        speedMultiplier = 0.66;
    }
    else if(playerLocation.TileType == TileType::Sand) {
        speedMultiplier = 0.33;
    }

    auto toLocation = _graph[_path.front()];

    if(toLocation.X > playerLocation.X) {
        parent->Transform().position.x += 1.5 * speedMultiplier;
    }
    else if(toLocation.Y > playerLocation.Y) {
        parent->Transform().position.y += 1.5 * speedMultiplier;
    }
    else if(toLocation.Y < playerLocation.Y) {
        parent->Transform().position.y -= 1.5 * speedMultiplier;
    }
    else if(toLocation.X < playerLocation.X) {
        parent->Transform().position.x -= 1.5 * speedMultiplier;
    }

    if(toLocation.X == playerLocation.X && toLocation.Y == playerLocation.Y) {
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