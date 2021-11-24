#include "EnemyPrefabFactory.hpp"

#include "../Enums/Layer.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include "../Scripts/Enemies/EnemyMovementBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"

#include "Animator.hpp"
#include "CircleCollider.hpp"
#include "RigidBody.hpp"

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
    types::sprite_vector idleSprites = CreateSpriteVector(10, "resources/sprites/heroes/Idle/hero_idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(10, "resources/sprites/heroes/Walking/hero_walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(9, "resources/sprites/heroes/Died/hero_died_");

    auto enemy = CreateBaseEnemy(15, 200, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGruppenfuhrer()
{
    types::sprite_vector idleSprites = CreateSpriteVector(0, "resources/sprites/heroes/Gruppenfuhrer/idle/idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(0, "resources/sprites/heroes/Gruppenfuhrer/walking/walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(0, "resources/sprites/heroes/Gruppenfuhrer/died/died_");

    auto enemy = CreateBaseEnemy(4, 80, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateSchutze()
{
    types::sprite_vector idleSprites = CreateSpriteVector(0, "resources/sprites/heroes/Schutze/idle/idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(0, "resources/sprites/heroes/Schutze/walking/walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(0, "resources/sprites/heroes/Schutze/died/died_");

    auto enemy = CreateBaseEnemy(2, 25, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateErkunder()
{
    types::sprite_vector idleSprites = CreateSpriteVector(0, "resources/sprites/heroes/Erkunder/idle/idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(0, "resources/sprites/heroes/Erkunder/walking/walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(0, "resources/sprites/heroes/Erkunder/died/died_");

    auto enemy = CreateBaseEnemy(2, 50, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateGhillieAnzugSchutze()
{
    types::sprite_vector idleSprites = CreateSpriteVector(0, "resources/sprites/heroes/GhillieAnzugSchutze/idle/idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(0, "resources/sprites/heroes/GhillieAnzugSchutze/walking/walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(0, "resources/sprites/heroes/GhillieAnzugSchutze/died/died_");

    auto enemy = CreateBaseEnemy(3, 60, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateStabsarzt()
{
    types::sprite_vector idleSprites = CreateSpriteVector(0, "resources/sprites/heroes/Stabsarzt/idle/idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(0, "resources/sprites/heroes/Stabsarzt/walking/walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(0, "resources/sprites/heroes/Stabsarzt/died/died_");

    auto enemy = CreateBaseEnemy(1, 75, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateRaupenschlepper()
{
    types::sprite_vector idleSprites = CreateSpriteVector(0, "resources/sprites/heroes/Raupenschlepper/idle/idle_");
    types::sprite_vector walkingSprites = CreateSpriteVector(0, "resources/sprites/heroes/Raupenschlepper/walking/walking_");
    types::sprite_vector diedSprites = CreateSpriteVector(0, "resources/sprites/heroes/Raupenschlepper/died/died_");

    auto enemy = CreateBaseEnemy(12, 150, idleSprites, walkingSprites, diedSprites);

    return enemy;
}

std::shared_ptr<spic::GameObject> EnemyPrefabFactory::CreateBaseEnemy(int attack, int defense, const types::sprite_vector& idleSprites, const types::sprite_vector& walkingSprites, const types::sprite_vector& diedSprites)
{
    auto baseEnemy = std::make_shared<spic::GameObject>("Enemy", "enemy", Layer::Game);
    baseEnemy->Transform().scale = EnemyScale;

    auto defaultSprite = std::make_shared<spic::Sprite>(idleSprites[0]->Texture(), false, false, 1, 0);
    GameObjectUtil::LinkComponent(baseEnemy, defaultSprite);

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

types::sprite_vector EnemyPrefabFactory::CreateSpriteVector(int max, const std::string& prefix, const std::string& extension, bool flipX, bool flipY)
{
    types::sprite_vector sprites{};

    for (int i = 1; i <= max; ++i)
    {
        sprites.push_back(std::make_shared<spic::Sprite>(prefix + std::to_string(i) + extension, flipX, flipY, 0, 0));
    }

    return sprites;
}
