#include "HeroPrefabFactory.hpp"

#include <Animator.hpp>
#include <CircleCollider.hpp>
#include "Sprite.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Heroes/HealAbilityBehaviour.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"
#include "../Scripts/Common/UserMovementBehaviour.hpp"
#include "../Scripts/Common/UserAttackBehaviour.hpp"
#include "../Utils/AnimatorUtil.hpp"
#include "../Utils/GameObjectUtil.hpp"

#include <stdexcept>

const int HeroScale = 1; //default scale on 1
const int HeroWidth = 200; //width of hero image
const int HeroHeight = 320; //height of hero image
const int HeroMass = 50; //random chosen mass
const int HeroVelocity = 50; //random chosen velocity (looks good)
const double HeroBulletSpeed = 17.5; // random chosen bullet speed (looks alright)

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateHero(game::HeroName name)
{
    switch (name)
    {
        case HeroName::DesmondDoss:
            return CreateDesmondDoss();
        case HeroName::BernardIJzerdraat:
            return CreateBernardIJzerdraat();
        case HeroName::FranklinDRoosevelt:
            return CreateFranklinDRoosevelt();
        case HeroName::WinstonChurchill:
            return CreateWinstonChurchill();
        case HeroName::JosephStalin:
            return CreateJosephStalin();
    }

    throw std::runtime_error("Hero not implemented.");
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
    auto baseHero = std::make_shared<spic::GameObject>("Hero", "Player", Layer::Game);
    baseHero->Transform().scale = HeroScale;

    std::vector<std::shared_ptr<spic::Sprite>> idleSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/heroes/Idle/hero_idle_", SortingLayer::Hero);
    std::vector<std::shared_ptr<spic::Sprite>> walkingSprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/heroes/Walking/hero_walking_", SortingLayer::Hero);
    std::vector<std::shared_ptr<spic::Sprite>> celebratingSprites = AnimatorUtil::CreateSpriteVector(11, "resources/sprites/heroes/Celebrating/hero_celebrating_", SortingLayer::Hero);
    std::vector<std::shared_ptr<spic::Sprite>> diedSprites = AnimatorUtil::CreateSpriteVector(9, "resources/sprites/heroes/Died/hero_died_", SortingLayer::Hero);

    auto defaultSprite = std::make_shared<spic::Sprite>(idleSprites[0]->Texture(), false, false, SortingLayer::Hero, 0);
    GameObjectUtil::LinkComponent(baseHero, defaultSprite);

    auto idleAnimator = std::make_shared<spic::Animator>(static_cast<int>(idleSprites.size()), idleSprites);
    GameObjectUtil::LinkComponent(baseHero, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(static_cast<int>(walkingSprites.size()), walkingSprites);
    GameObjectUtil::LinkComponent(baseHero, walkingAnimator);

    auto diedAnimator = std::make_shared<spic::Animator>(static_cast<int>(diedSprites.size()), diedSprites);
    GameObjectUtil::LinkComponent(baseHero, diedAnimator);

    auto CelebratingAnimator = std::make_shared<spic::Animator>(static_cast<int>(celebratingSprites.size()), celebratingSprites);
    GameObjectUtil::LinkComponent(baseHero, CelebratingAnimator);

    auto healthBehaviour = std::make_shared<game::HealthBehaviour>(diedAnimator, defense);
    GameObjectUtil::LinkComponent(baseHero, healthBehaviour);

    auto userMovementBehaviour = std::make_shared<game::UserMovementBehaviour>(static_cast<float>(HeroVelocity), idleAnimator, walkingAnimator, healthBehaviour);
    GameObjectUtil::LinkComponent(baseHero, userMovementBehaviour);

    spic::Point originPoint{(HeroWidth / 2.0) * HeroScale, (HeroHeight / 2.0) * HeroScale};
    auto attackBehaviour = std::make_shared<game::UserAttackBehaviour>(attack, HeroBulletSpeed, originPoint);
    GameObjectUtil::LinkComponent(baseHero, attackBehaviour);

    auto heroCollider = std::make_shared<spic::CircleCollider>((HeroWidth / 2.0) * HeroScale);
    GameObjectUtil::LinkComponent(baseHero, heroCollider);

    auto heroRigidBody = std::make_shared<spic::RigidBody>(HeroMass, 0, spic::BodyType::dynamicBody);
    GameObjectUtil::LinkComponent(baseHero, heroRigidBody);

    return baseHero;
}
