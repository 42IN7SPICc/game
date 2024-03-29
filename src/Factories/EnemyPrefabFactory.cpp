#include "EnemyPrefabFactory.hpp"

#include "HealthBarFactory.hpp"
#include "../EnemyConstants.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Common/AttackBehaviour.hpp"
#include "../Scripts/Enemies/EnemyInvisibleBehaviour.hpp"
#include "../Scripts/Enemies/EnemyMedicBehaviour.hpp"
#include "../Scripts/Enemies/EnemyMovementBehaviour.hpp"
#include "../Scripts/Enemies/EnemySpeedBoostBehaviour.hpp"
#include "../Scripts/Enemies/EnemyTroopTruckBehaviour.hpp"
#include "Utils/GameObjectUtil.hpp"

#include "Animator.hpp"
#include "CircleCollider.hpp"
#include "RigidBody.hpp"
#include "../Scripts/Enemies/EnemyValue.hpp"

#include <stdexcept>

using namespace game;

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateEnemy(EnemyName name, bool hasHealthBar)
{
    std::shared_ptr<spic::GameObject> enemy;

    switch (name)
    {
        case EnemyName::Tank:
            enemy = CreatePanzer();
            break;
        case EnemyName::General:
            enemy = CreateGruppenfuhrer();
            break;
        case EnemyName::Soldier:
            enemy = CreateSchutze();
            break;
        case EnemyName::Scout:
            enemy = CreateErkunder();
            break;
        case EnemyName::Sniper:
            enemy = CreateGhillieAnzugSchutze();
            break;
        case EnemyName::Healer:
            enemy = CreateStabsarzt();
            break;
        case EnemyName::InfantryTransport:
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

        spic::GameObjectUtil::LinkChild(enemy, healthBar);
    }

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreatePanzer()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(1, "resources/sprites/enemies/tank/idle/tank_idle_", SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(8, "resources/sprites/enemies/tank/moving/tank_moving_", SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(17, "resources/sprites/enemies/tank/died/tank_exploding_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(15, PanzerEnemyHealth, PanzerEnemyVelocity, idleSprites, walkingSprites, diedSprites, PanzerEnemyValue);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, PanzerEnemyFireRate, PanzerEnemyRange, PanzerEnemyDamage, PanzerEnemyBulletSpeed);
    spic::GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGruppenfuhrer()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/idle/enemy_idle_", GruppenfuhrerColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/walking/enemy_walking_", GruppenfuhrerColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/soldier/died/enemy_died_", GruppenfuhrerColor<spic::Color>(), SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(4, GruppenfuhrerEnemyHealth, GruppenfuhrerEnemyVelocity, idleSprites, walkingSprites, diedSprites, GruppenfuhrerEnemyValue);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, GruppenfuhrerEnemyFireRate, GruppenfuhrerEnemyRange, GruppenfuhrerEnemyDamage, GruppenfuhrerEnemyBulletSpeed);
    spic::GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    spic::GameObjectUtil::LinkComponent(enemy, std::make_shared<EnemySpeedBoostBehaviour>(GruppenfuhrerEnemyBoostCoolDown, GruppenfuhrerEnemySpeedBoost, GruppenfuhrerEnemyBoostTime, GruppenfuhrerEnemyBoostRange));

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateSchutze()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/idle/enemy_idle_", SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/walking/enemy_walking_", SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/soldier/died/enemy_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(2, SchutzeEnemyHealth, SchutzeEnemyVelocity, idleSprites, walkingSprites, diedSprites, SchutzeEnemyValue);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, SchutzeEnemyFireRate, SchutzeEnemyRange, SchutzeEnemyDamage, SchutzeEnemyBulletSpeed);
    spic::GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateErkunder()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/idle/enemy_idle_", ErkunderColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/walking/enemy_walking_", ErkunderColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/soldier/died/enemy_died_", ErkunderColor<spic::Color>(), SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(2, ErkunderEnemyHealth, ErkunderEnemyVelocity, idleSprites, walkingSprites, diedSprites, ErkunderEnemyValue);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, ErkunderEnemyFireRate, ErkunderEnemyRange, ErkunderEnemyDamage, ErkunderEnemyBulletSpeed);
    spic::GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGhillieAnzugSchutze()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/idle/enemy_idle_", GhillieAnzugSchutzeColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/walking/enemy_walking_", GhillieAnzugSchutzeColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/soldier/died/enemy_died_", GhillieAnzugSchutzeColor<spic::Color>(), SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(3, GhillieAnzugSchutzeEnemyHealth, GhillieAnzugEnemyVelocity, idleSprites, walkingSprites, diedSprites, GhillieAnzugSchutzeEnemyValue);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, GhillieAnzugSchutzeEnemyFireRate, GhillieAnzugSchutzeEnemyRange, GhillieAnzugSchutzeEnemyDamage, GhillieAnzugSchutzeEnemyBulletSpeed);
    spic::GameObjectUtil::LinkComponent(enemy, attackBehaviour);

    spic::GameObjectUtil::LinkComponent(enemy, std::make_shared<EnemyInvisibleBehaviour>(GhillieAnzugSchutzeEnemyInvisibleEffectTime, GhillieAnzugSchutzeEnemyInvisibleCoolDownTime));

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateStabsarzt()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/idle/enemy_idle_", StabsarztColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/enemies/soldier/walking/enemy_walking_", StabsarztColor<spic::Color>(), SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(9, "resources/sprites/enemies/soldier/died/enemy_died_", StabsarztColor<spic::Color>(), SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(1, StabsarztEnemyHealth, StabsarztEnemyVelocity, idleSprites, walkingSprites, diedSprites, StabsarztEnemyValue);

    spic::GameObjectUtil::LinkComponent(enemy, std::make_shared<EnemyMedicBehaviour>(StabsarztHealPercentage, StabsarztHealRange, StabsarztHealCooldown));

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateRaupenschlepper()
{
    spic::types::sprite_vector idleSprites = spic::AnimatorUtil::CreateSpriteVector(1, "resources/sprites/enemies/truck/idle/truck_idle_", SortingLayer::Enemy);
    spic::types::sprite_vector walkingSprites = spic::AnimatorUtil::CreateSpriteVector(4, "resources/sprites/enemies/truck/moving/truck_moving_", SortingLayer::Enemy);
    spic::types::sprite_vector diedSprites = spic::AnimatorUtil::CreateSpriteVector(1, "resources/sprites/enemies/truck/died/truck_died_", SortingLayer::Enemy);

    auto enemy = CreateBaseEnemy(12, RaupenschlepperEnemyHealth, RaupenschlepperEnemyVelocity, idleSprites, walkingSprites, diedSprites, RaupenschlepperEnemyValue);

    spic::GameObjectUtil::LinkComponent(enemy, std::make_shared<EnemyTroopTruckBehaviour>(EnemyName::Soldier, 6));

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateBaseEnemy(int attack, int health, double speedMultiplier, const spic::types::sprite_vector& idleSprites, const spic::types::sprite_vector& walkingSprites, const spic::types::sprite_vector& diedSprites, int value)
{
    auto baseEnemy = std::make_shared<spic::GameObject>("Enemy", "enemy", Layer::Game);
    baseEnemy->Transform().scale = EnemyScale;

    auto defaultSprite = std::make_shared<spic::Sprite>(idleSprites[0]->Texture(), idleSprites[0]->Color(), false, false, SortingLayer::Enemy, 0);
    spic::GameObjectUtil::LinkComponent(baseEnemy, defaultSprite);

    auto idleAnimator = std::make_shared<spic::Animator>(static_cast<int>(idleSprites.size()), idleSprites);
    spic::GameObjectUtil::LinkComponent(baseEnemy, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(static_cast<int>(walkingSprites.size()), walkingSprites);
    spic::GameObjectUtil::LinkComponent(baseEnemy, walkingAnimator);

    auto diedAnimator = std::make_shared<spic::Animator>(static_cast<int>(diedSprites.size()), diedSprites);
    spic::GameObjectUtil::LinkComponent(baseEnemy, diedAnimator);

    auto healthBehaviour = std::make_shared<HealthBehaviour>(diedAnimator, health, EnemyDeSpawnTime);
    spic::GameObjectUtil::LinkComponent(baseEnemy, healthBehaviour);

    auto movementBehaviour = std::make_shared<EnemyMovementBehaviour>(walkingAnimator, EnemyVelocity * speedMultiplier);
    spic::GameObjectUtil::LinkComponent(baseEnemy, movementBehaviour);

    auto enemyCollider = std::make_shared<spic::CircleCollider>(0.000001);
    spic::GameObjectUtil::LinkComponent(baseEnemy, enemyCollider);

    auto enemyRigidBody = std::make_shared<spic::RigidBody>(EnemyMass, 0, spic::BodyType::dynamicBody);
    spic::GameObjectUtil::LinkComponent(baseEnemy, enemyRigidBody);

    auto enemyValue = std::make_shared<game::EnemyValue>(value);
    spic::GameObjectUtil::LinkComponent(baseEnemy, enemyValue);

    return baseEnemy;
}
