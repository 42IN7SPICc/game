#include "EnemyTroopTruckBehaviour.hpp"

#include "EnemyMovementBehaviour.hpp"
#include "../../Constants.hpp"
#include "../../Controllers/LevelController.hpp"
#include "../../Factories/EnemyPrefabFactory.hpp"
#include "../../Utils/RandomUtil.hpp"

#include "Engine.hpp"

#include <stdexcept>

const double MaxDistance = TileSize * TileMapScale * 1.5;
const double DistanceOffset = TileSize / 2;

game::EnemyTroopTruckBehaviour::EnemyTroopTruckBehaviour(game::EnemyName enemyName, int count) : _enemyName(enemyName),
                                                                                                 _count(count),
                                                                                                 _spawned(false)
{
}

void game::EnemyTroopTruckBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _healthBehaviour = parent->GetComponent<HealthBehaviour>();
    if (!_healthBehaviour)
    {
        throw std::runtime_error("The EnemyTroopTruckBehaviour requires a HealthBehaviour on the same game object.");
    }
}

void game::EnemyTroopTruckBehaviour::OnUpdate()
{
    if (!_spawned && _healthBehaviour->Health() <= 0)
    {
        auto parent = GameObject().lock();
        auto parentTransform = parent->AbsoluteTransform();

        auto scene = spic::Engine::Instance().PeekScene();
        auto levelController = spic::GameObject::Find("LevelController")->GetComponent<LevelController>();
        auto parentPath = parent->GetComponent<EnemyMovementBehaviour>()->Path();
        for (int i = 0; i < _count; ++i)
        {
            auto enemy = EnemyPrefabFactory::CreateEnemy(_enemyName, true);
            enemy->Transform() = parentTransform;
            enemy->Transform().position.x += (RandomUtil::NextDouble(0, MaxDistance) - DistanceOffset);
            enemy->Transform().position.y += (RandomUtil::NextDouble(0, MaxDistance) - DistanceOffset);
            enemy->GetComponent<EnemyMovementBehaviour>()->Path(parentPath);
            scene->Contents().push_back(enemy);
            levelController->AddEnemyToWave(enemy);
        }

        _spawned = true;
    }
}

void game::EnemyTroopTruckBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void game::EnemyTroopTruckBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void game::EnemyTroopTruckBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

bool game::EnemyTroopTruckBehaviour::Spawned() const
{
    return _spawned;
}
