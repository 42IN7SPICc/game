#include <Animator.hpp>
#include <CircleCollider.hpp>
#include "HeroPrefabFactory.hpp"
#include "Sprite.hpp"
#include "../Scripts/common/HealthBehaviour.hpp"
#include "../Scripts/common/UserMovementBehaviour.hpp"
#include "../Scripts/common/AttackBehaviour.hpp"
#include "../Scripts/heroes/HealAbilityBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"
#include "../Utils/HeroName.hpp"

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateHero(game::HeroName name)
{
    switch (name)
    {
        case DesmondDoss:
            return CreateDesmondDoss();
        case BernardIJzerdraat:
            return CreateBernardIJzerdraat();
        case FranklinDRoosevelt:
            return CreateFranklinDRoosevelt();
        case WinstonChurchill:
            return CreateWinstonChurchill();
        case JosephStalin:
            return CreateJosephStalin();
    }
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateDesmondDoss()
{
    auto base_hero = CreateBaseHero(2, 3);
    auto ability = std::make_shared<game::HealAbilityBehaviour>();
    GameObjectUtil::LinkComponent(base_hero, ability);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateBernardIJzerdraat()
{
    auto base_hero = CreateBaseHero(5, 3);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateFranklinDRoosevelt()
{
    auto base_hero = CreateBaseHero(4, 2);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateWinstonChurchill()
{
    auto base_hero = CreateBaseHero(2, 5);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateJosephStalin()
{
    auto base_hero = CreateBaseHero(5, 5);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateBaseHero(int attack, int defense)
{
    auto baseHero = std::make_shared<spic::GameObject>("Hero", "Player", 1);

    auto defaultSprite = std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_1.png", false, false, 0, 0);
    GameObjectUtil::LinkComponent(baseHero, defaultSprite);

    std::vector<std::shared_ptr<spic::Sprite>> idleSprites;
    std::vector<std::shared_ptr<spic::Sprite>> walkingSprites;

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

    auto idleAnimator = std::make_shared<spic::Animator>(12, idleSprites);
    GameObjectUtil::LinkComponent(baseHero, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(12, walkingSprites);
    GameObjectUtil::LinkComponent(baseHero, walkingAnimator);

    auto healthBehaviour = std::make_shared<game::HealthBehaviour>(defense);
    GameObjectUtil::LinkComponent(baseHero, healthBehaviour);

    auto userMovementBehaviour = std::make_shared<game::UserMovementBehaviour>(50, idleAnimator, walkingAnimator);
    GameObjectUtil::LinkComponent(baseHero, userMovementBehaviour);

    auto attackBehaviour = std::make_shared<game::AttackBehaviour>(attack);
    GameObjectUtil::LinkComponent(baseHero, attackBehaviour);

    auto heroCollider = std::make_shared<spic::CircleCollider>(80);
    GameObjectUtil::LinkComponent(baseHero, heroCollider);

    auto heroRigidBody = std::make_shared<spic::RigidBody>(50, 0, spic::BodyType::dynamicBody);
    GameObjectUtil::LinkComponent(baseHero, heroRigidBody);

    return baseHero;
}
