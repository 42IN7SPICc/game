#include "EnemyPrefabFactory.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Common/AttackBehaviour.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include "../Scripts/Enemies/EnemyMovementBehaviour.hpp"
#include "../Utils/AnimatorUtil.hpp"
#include "../Utils/GameObjectUtil.hpp"

#include "Animator.hpp"
#include "CircleCollider.hpp"
#include "RigidBody.hpp"
#include "../Scripts/Common/DamageBehaviour.hpp"

#include <stdexcept>

const int EnemyScale = 1; //default scale on 1
const int EnemyWidth = 200; //width of enemy image
const int EnemyHeight = 320; //height of enemy image
const int EnemyMass = 50; //random chosen mass
const int EnemyVelocity = 50; //random chosen velocity

using namespace game;

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateEnemy(EnemyName name)
{
    switch (name)
    {
        case EnemyName::Panzer:
            return CreatePanzer();
        case EnemyName::Gruppenfuhrer:
            return CreateGruppenfuhrer();
        case EnemyName::Schutze:
            return CreateSchutze();
        case EnemyName::Erkunder:
            return CreateErkunder();
        case EnemyName::GhillieAnzugSchutze:
            return CreateGhillieAnzugSchutze();
        case EnemyName::Stabsarzt:
            return CreateStabsarzt();
        case EnemyName::Raupenschlepper:
            return CreateRaupenschlepper();
    }

    throw std::runtime_error("Enemy not implemented.");
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreatePanzer()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(15, 200, idleSprites, walkingSprites, diedSprites);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", 3, 500, 15, false, 25);
    GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGruppenfuhrer()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(4, 80, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateSchutze()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(2, 25, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateErkunder()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(2, 50, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGhillieAnzugSchutze()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(3, 60, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateStabsarzt()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(1, 75, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateRaupenschlepper()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/truck/truck_moving_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/truck/truck_moving_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/truck/truck_moving_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(12, 150, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateBaseEnemy(int attack, int health, const types::sprite_vector& idleSprites, const types::sprite_vector& walkingSprites, const types::sprite_vector& diedSprites)
{
    auto baseEnemy = std::make_shared<spic::GameObject>("Enemy", "enemy", Layer::Game);
    baseEnemy->Transform().scale = EnemyScale;

    auto defaultSprite = std::make_shared<spic::Sprite>(idleSprites[0]->Texture(), false, false, SortingLayer::Hero, 0);
    GameObjectUtil::LinkComponent(baseEnemy, defaultSprite);

    auto idleAnimator = std::make_shared<spic::Animator>(static_cast<int>(idleSprites.size()), idleSprites);
    GameObjectUtil::LinkComponent(baseEnemy, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(static_cast<int>(walkingSprites.size()), walkingSprites);
    GameObjectUtil::LinkComponent(baseEnemy, walkingAnimator);

    auto diedAnimator = std::make_shared<spic::Animator>(static_cast<int>(diedSprites.size()), diedSprites);
    GameObjectUtil::LinkComponent(baseEnemy, diedAnimator);

    auto healthBehaviour = std::make_shared<HealthBehaviour>(diedAnimator, health);
    GameObjectUtil::LinkComponent(baseEnemy, healthBehaviour);

    auto damageBehaviour = std::make_shared<DamageBehaviour>(attack, "end_tile");
    GameObjectUtil::LinkComponent(baseEnemy, damageBehaviour);

    auto movementBehaviour = std::make_shared<EnemyMovementBehaviour>();
    GameObjectUtil::LinkComponent(baseEnemy, movementBehaviour);

    auto colliderRadius = EnemyWidth * 0.5 * EnemyScale;
    auto enemyTriggerCollider = std::make_shared<spic::CircleCollider>(colliderRadius);
    enemyTriggerCollider->IsTrigger(true);
    GameObjectUtil::LinkComponent(baseEnemy, enemyTriggerCollider);

//    auto enemyCollider = std::make_shared<spic::CircleCollider>(colliderRadius);
//    GameObjectUtil::LinkComponent(baseEnemy, enemyCollider);

    auto enemyRigidBody = std::make_shared<spic::RigidBody>(EnemyMass, 0, spic::BodyType::dynamicBody);
    GameObjectUtil::LinkComponent(baseEnemy, enemyRigidBody);

    return baseEnemy;
}
