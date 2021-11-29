#include "EnemyMovementBehaviour.hpp"
#include "GameObject.hpp"
#include "Animator.hpp"

using namespace game;

void EnemyMovementBehaviour::OnStart()
{
}

void EnemyMovementBehaviour::OnUpdate()
{
    auto parent = GameObject().lock();
    parent->Transform().position.x += 0.5;

    auto animator = parent->GetComponents<spic::Animator>()[1]; //walking animator
    animator->Play(true);
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