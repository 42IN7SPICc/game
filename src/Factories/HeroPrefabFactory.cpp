#include "HeroPrefabFactory.hpp"

#include <Animator.hpp>
#include <CircleCollider.hpp>
#include "Sprite.hpp"

#include "HealthBarFactory.hpp"
#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Heroes/HealAbilityBehaviour.hpp"
#include "../Scripts/Heroes/InvisibilityAbilityBehaviour.hpp"
#include "../Scripts/Heroes/AirstrikeAbilityBehaviour.hpp"
#include "../Scripts/Heroes/IncreaseTowerFireRateAbilityBehaviour.hpp"
#include "../Scripts/Heroes/EnemySuicideAbilityBehaviour.hpp"
#include "../Scripts/Heroes/UserMovementBehaviour.hpp"
#include "../Scripts/Heroes/UserAttackBehaviour.hpp"
#include "Utils/AnimatorUtil.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../HeroConstants.hpp"

#include <stdexcept>

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateHero(game::HeroName name, bool hasHealthBar)
{
    std::shared_ptr<spic::GameObject> hero;

    switch (name)
    {
        case HeroName::DesmondDoss:
            hero = CreateDesmondDoss();
            break;
        case HeroName::BernardIJzerdraat:
            hero = CreateBernardIJzerdraat();
            break;
        case HeroName::FranklinDRoosevelt:
            hero = CreateFranklinDRoosevelt();
            break;
        case HeroName::WinstonChurchill:
            hero = CreateWinstonChurchill();
            break;
        case HeroName::JosephStalin:
            hero = CreateJosephStalin();
            break;
        default:
            throw std::runtime_error("Hero not implemented.");
    }

    if (hasHealthBar)
    {
        auto healthBar = HealthBarFactory::CreateHealthBar(hero);
        healthBar->Transform().position.y = -200;
        healthBar->Transform().scale = 1.5;

        spic::GameObjectUtil::LinkChild(hero, healthBar);
    }

    return hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateDesmondDoss()
{
    auto base_hero = CreateBaseHero(DesmondDossDamage, DesmondDossDefense, DesmondDossColor<spic::Color>());
    auto ability = std::make_shared<game::HealAbilityBehaviour>();
    spic::GameObjectUtil::LinkComponent(base_hero, ability);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateBernardIJzerdraat()
{
    auto base_hero = CreateBaseHero(BernardIJzerdraatDamage, BernardIJzerdraatDefense, BernardIJzerdraatColor<spic::Color>());
    auto ability = std::make_shared<game::InvisibilityAbilityBehaviour>();
    spic::GameObjectUtil::LinkComponent(base_hero, ability);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateFranklinDRoosevelt()
{
    auto base_hero = CreateBaseHero(FranklinDRooseveltDamage, FranklinDRooseveltDefense, FranklinDRooseveltColor<spic::Color>());
    auto ability = std::make_shared<game::AirstrikeAbilityBehaviour>();
    spic::GameObjectUtil::LinkComponent(base_hero, ability);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateWinstonChurchill()
{
    auto base_hero = CreateBaseHero(WinstonChurchillDamage, WinstonChurchillDefense, WinstonChurchillColor<spic::Color>());
    auto ability = std::make_shared<game::IncreaseTowerFireRateAbilityBehaviour>();
    spic::GameObjectUtil::LinkComponent(base_hero, ability);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateJosephStalin()
{
    auto base_hero = CreateBaseHero(JosephStalinDamage, JosephStalinDefense, JosephStalinColor<spic::Color>());
    auto ability = std::make_shared<game::EnemySuicideAbilityBehaviour>();
    spic::GameObjectUtil::LinkComponent(base_hero, ability);

    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateBaseHero(int attack, int defense, spic::Color color)
{
    auto baseHero = std::make_shared<spic::GameObject>("Hero", "hero", Layer::Game);
    baseHero->Transform().scale = HeroScale;

    std::vector<std::shared_ptr<spic::Sprite>> idleSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/heroes/Idle/hero_idle_", color, SortingLayer::Hero);
    std::vector<std::shared_ptr<spic::Sprite>> walkingSprites = spic::AnimatorUtil::CreateSpriteVector(10, "resources/sprites/heroes/Walking/hero_walking_", color, SortingLayer::Hero);
    std::vector<std::shared_ptr<spic::Sprite>> celebratingSprites = spic::AnimatorUtil::CreateSpriteVector(11, "resources/sprites/heroes/Celebrating/hero_celebrating_", color, SortingLayer::Hero);
    std::vector<std::shared_ptr<spic::Sprite>> diedSprites = spic::AnimatorUtil::CreateSpriteVector(9, "resources/sprites/heroes/Died/hero_died_", color, SortingLayer::Hero);

    auto defaultSprite = std::make_shared<spic::Sprite>(idleSprites[0]->Texture(), color, false, false, SortingLayer::Hero, 0);
    spic::GameObjectUtil::LinkComponent(baseHero, defaultSprite);

    auto idleAnimator = std::make_shared<spic::Animator>(static_cast<int>(idleSprites.size()), idleSprites);
    spic::GameObjectUtil::LinkComponent(baseHero, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(static_cast<int>(walkingSprites.size()), walkingSprites);
    spic::GameObjectUtil::LinkComponent(baseHero, walkingAnimator);

    auto diedAnimator = std::make_shared<spic::Animator>(static_cast<int>(diedSprites.size()), diedSprites);
    spic::GameObjectUtil::LinkComponent(baseHero, diedAnimator);

    auto CelebratingAnimator = std::make_shared<spic::Animator>(static_cast<int>(celebratingSprites.size()), celebratingSprites);
    spic::GameObjectUtil::LinkComponent(baseHero, CelebratingAnimator);

    auto healthBehaviour = std::make_shared<game::HealthBehaviour>(diedAnimator, defense * BaseHeroHealth, 0);
    spic::GameObjectUtil::LinkComponent(baseHero, healthBehaviour);

    auto userMovementBehaviour = std::make_shared<game::UserMovementBehaviour>(static_cast<float>(HeroVelocity), idleAnimator, walkingAnimator, healthBehaviour);
    spic::GameObjectUtil::LinkComponent(baseHero, userMovementBehaviour);

    auto attackBehaviour = std::make_shared<game::UserAttackBehaviour>(attack * BaseHeroDamage, HeroBulletSpeed, healthBehaviour);
    spic::GameObjectUtil::LinkComponent(baseHero, attackBehaviour);

    auto heroCollider = std::make_shared<spic::CircleCollider>(HeroWidth * 0.5 * HeroScale);
    spic::GameObjectUtil::LinkComponent(baseHero, heroCollider);

    auto heroRigidBody = std::make_shared<spic::RigidBody>(HeroMass, 0, spic::BodyType::dynamicBody);
    spic::GameObjectUtil::LinkComponent(baseHero, heroRigidBody);

    return baseHero;
}
