#include "EnemyPrefabFactory.hpp"

#include "../Enums/Layer.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include "../Scripts/Enemies/EnemyMovementBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"

#include "Animator.hpp"
#include "CircleCollider.hpp"
#include "RigidBody.hpp"
#include "Sprite.hpp"

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
    auto enemy = CreateBaseEnemy(15, 200);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGruppenfuhrer()
{
    auto enemy = CreateBaseEnemy(4, 80);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateSchutze()
{
    auto enemy = CreateBaseEnemy(2, 25);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateErkunder()
{
    auto enemy = CreateBaseEnemy(2, 50);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGhillieAnzugSchutze()
{
    auto enemy = CreateBaseEnemy(3, 60);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateStabsarzt()
{
    auto enemy = CreateBaseEnemy(1, 75);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateRaupenschlepper()
{
    auto enemy = CreateBaseEnemy(12, 150);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateBaseEnemy(int attack, int defense)
{
    auto baseEnemy = std::make_shared<spic::GameObject>("Enemy", "enemy", Layer::Game);
    baseEnemy->Transform().scale = EnemyScale;

    auto defaultSprite = std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_1.png", false, false, 1, 0);
    GameObjectUtil::LinkComponent(baseEnemy, defaultSprite);

    std::vector<std::shared_ptr<spic::Sprite>> idleSprites;
    std::vector<std::shared_ptr<spic::Sprite>> walkingSprites;
    std::vector<std::shared_ptr<spic::Sprite>> celebratingSprites;
    std::vector<std::shared_ptr<spic::Sprite>> diedSprites;

    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_1.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_2.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_3.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_4.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_5.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_6.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_7.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_8.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_9.png", false, false, 0, 0));
    idleSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_10.png", false, false, 0, 0));

    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_1.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_2.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_3.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_4.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_5.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_6.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_7.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_8.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_9.png", false, false, 0, 0));
    walkingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Walking/hero_walking_10.png", false, false, 0, 0));

    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_1.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_2.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_3.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_4.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_5.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_6.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_7.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_8.png", false, false, 0, 0));
    diedSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Died/hero_died_9.png", false, false, 0, 0));

    auto idleAnimator = std::make_shared<spic::Animator>(static_cast<int>(idleSprites.size()), idleSprites);
    GameObjectUtil::LinkComponent(baseEnemy, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(static_cast<int>(walkingSprites.size()), walkingSprites);
    GameObjectUtil::LinkComponent(baseEnemy, walkingAnimator);

    auto diedAnimator = std::make_shared<spic::Animator>(static_cast<int>(diedSprites.size()), diedSprites);
    GameObjectUtil::LinkComponent(baseEnemy, diedAnimator);

    auto healthBehaviour = std::make_shared<HealthBehaviour>(diedAnimator, defense);
    GameObjectUtil::LinkComponent(baseEnemy, healthBehaviour);

    auto movementBehaviour = std::make_shared<EnemyMovementBehaviour>();
    GameObjectUtil::LinkComponent(baseEnemy, movementBehaviour);

    auto enemyCollider = std::make_shared<spic::CircleCollider>((EnemyWidth / 2.0) * EnemyScale);
    enemyCollider->IsTrigger(true);
    GameObjectUtil::LinkComponent(baseEnemy, enemyCollider);

    auto enemyRigidBody = std::make_shared<spic::RigidBody>(EnemyMass, 0, spic::BodyType::dynamicBody);
    GameObjectUtil::LinkComponent(baseEnemy, enemyRigidBody);

    return baseEnemy;
}
