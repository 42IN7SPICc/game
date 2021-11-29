#include "EnemyMovementBehaviour.hpp"
#include "GameObject.hpp"
#include "Animator.hpp"
#include "../../Controllers/LevelController.hpp"
#include "../../Utils/StringUtil.hpp"
#include "Debug.hpp"

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
        for (const auto&[location, node]: _graph)
        {
            if (node.TileType == TileType::Start)
            {
                _currentNode = location;
                _fromNode = location;

                for (const auto& neighbour: node.NeighbourStrings)
                {
                    if (CanWalk(_graph[neighbour].TileType))
                    {
                        _toNode = neighbour;
                        break;
                    }
                }
                break;
            }
        }
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

    auto toLocation = _graph[_path.front()];

    if(toLocation.X > playerLocation.X) {
        parent->Transform().position.x += 1.5;
    }
    else if(toLocation.Y > playerLocation.Y) {
        parent->Transform().position.y += 1.5;
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