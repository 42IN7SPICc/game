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

    auto animator = parent->GetComponents<spic::Animator>()[1]; //walking animator
    animator->Play(true);

    auto gameObject = spic::GameObject::Find("LevelController");
    if (gameObject)
    {


        
    }
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