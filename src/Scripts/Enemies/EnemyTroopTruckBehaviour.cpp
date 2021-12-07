#include "EnemyTroopTruckBehaviour.hpp"

#include "../../Factories/EnemyPrefabFactory.hpp"

#include "Engine.hpp"

#include <stdexcept>

game::EnemyTroopTruckBehaviour::EnemyTroopTruckBehaviour(game::EnemyName enemyName, int count) : _enemyName(enemyName),
                                                                                                 _count(count)
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
    if (_healthBehaviour->Health() <= 0)
    {
        auto scene = spic::Engine::Instance().PeekScene();
        for (int i = 0; i < _count; ++i)
        {
            scene->Contents().push_back(EnemyPrefabFactory::CreateEnemy(_enemyName));
        }

        auto parent = GameObject().lock();
        parent->RemoveComponent(parent->GetComponent<EnemyTroopTruckBehaviour>());
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
