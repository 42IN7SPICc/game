#include "EnemyPrefabFactory.hpp"

#include "HealthBarFactory.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Common/AttackBehaviour.hpp"
#include "../Scripts/Enemies/EnemyMovementBehaviour.hpp"
#include "../Scripts/Enemies/EnemyTroopTruckBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"

#include "../Constants.hpp"
#include "Animator.hpp"
#include "CircleCollider.hpp"
#include "RigidBody.hpp"

#include <stdexcept>

using namespace game;

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateEnemy(EnemyName name, bool hasHealthBar)
{
    std::shared_ptr<spic::GameObject> enemy;

    switch (name)
    {
        case EnemyName::Panzer:
            enemy = CreatePanzer();
            break;
        case EnemyName::Gruppenfuhrer:
            enemy = CreateGruppenfuhrer();
            break;
        case EnemyName::Schutze:
            enemy = CreateSchutze();
            break;
        case EnemyName::Erkunder:
            enemy = CreateErkunder();
            break;
        case EnemyName::GhillieAnzugSchutze:
            enemy = CreateGhillieAnzugSchutze();
            break;
        case EnemyName::Stabsarzt:
            enemy = CreateStabsarzt();
            break;
        case EnemyName::Raupenschlepper:
            enemy = CreateRaupenschlepper();
            break;
        default:
            throw std::runtime_error("Enemy not implemented.");
    }

    if (hasHealthBar)
    {
        auto healthBar = HealthBarFactory::CreateHealthBar(enemy);
        healthBar->Transform().position.y = -200;
        healthBar->Transform().scale = 1.5;

        GameObjectUtil::LinkChild(enemy, healthBar);
    }

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreatePanzer()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(15, PanzerEnemyHealth, 0.5, idleSprites, walkingSprites, diedSprites);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, PanzerEnemyFireRate, PanzerEnemyRange, PanzerEnemyDamage, PanzerEnemyBulletSpeed);
    GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGruppenfuhrer()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(4, 80, 1, idleSprites, walkingSprites, diedSprites);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, GruppenfuhrerEnemyFireRate, GruppenfuhrerEnemyRange, GruppenfuhrerEnemyDamage, GruppenfuhrerEnemyBulletSpeed);
    GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateSchutze()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(2, 25, 1, idleSprites, walkingSprites, diedSprites);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, SchutzeEnemyFireRate, SchutzeEnemyRange, SchutzeEnemyDamage, SchutzeEnemyBulletSpeed);
    GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateErkunder()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(2, 50, 1.5, idleSprites, walkingSprites, diedSprites);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, ErkunderEnemyFireRate, ErkunderEnemyRange, ErkunderEnemyDamage, ErkunderEnemyBulletSpeed);
    GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGhillieAnzugSchutze()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(3, 60, 1, idleSprites, walkingSprites, diedSprites);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, GhillieAnzugSchutzeEnemyFireRate, GhillieAnzugSchutzeEnemyRange, GhillieAnzugSchutzeEnemyDamage, GhillieAnzugSchutzeEnemyBulletSpeed);
    GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateStabsarzt()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Idle/enemy_idle_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/Walking/enemy_walking_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/Died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(1, 75, 1, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateRaupenschlepper()
{
    types::sprite_vector idleSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/truck/truck_moving_", SortingLayer::Enemy);
    types::sprite_vector walkingSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/truck/truck_moving_", SortingLayer::Enemy);
    types::sprite_vector diedSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/truck/truck_moving_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(12, 150, 0.8, idleSprites, walkingSprites, diedSprites);

    GameObjectUtil::LinkComponent(enemy, std::make_shared<EnemyTroopTruckBehaviour>(EnemyName::Schutze, 6));

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateBaseEnemy(int attack, int health, double speedMultiplier, const types::sprite_vector& idleSprites, const types::sprite_vector& walkingSprites, const types::sprite_vector& diedSprites)
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

    auto healthBehaviour = std::make_shared<HealthBehaviour>(diedAnimator, health, EnemyDeSpawnTime);
    GameObjectUtil::LinkComponent(baseEnemy, healthBehaviour);

    auto movementBehaviour = std::make_shared<EnemyMovementBehaviour>(walkingAnimator, EnemyVelocity * speedMultiplier);
    GameObjectUtil::LinkComponent(baseEnemy, movementBehaviour);

    auto enemyCollider = std::make_shared<spic::CircleCollider>(0.000001);
    GameObjectUtil::LinkComponent(baseEnemy, enemyCollider);

    auto enemyRigidBody = std::make_shared<spic::RigidBody>(EnemyMass, 0, spic::BodyType::dynamicBody);
    GameObjectUtil::LinkComponent(baseEnemy, enemyRigidBody);

    return baseEnemy;
}
