#include <Animator.hpp>
#include <CircleCollider.hpp>
#include "HeroPrefabFactory.hpp"
#include "Sprite.hpp"
#include "../Scripts/common/HealthBehaviour.hpp"
#include "../Scripts/common/UserMovementBehaviour.hpp"
#include "../Scripts/common/AttackBehaviour.hpp"
#include "../Scripts/heroes/HealAbilityBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"

const int hero_scale = 1; //default scale on 1
const int hero_width = 200; //width of hero image
const int hero_mass = 50; //random chosen mass
const int hero_velocity = 50; //random chosen velocity (looks good)

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
    baseHero->Transform().scale = hero_scale;

    auto defaultSprite = std::make_shared<spic::Sprite>("resources/sprites/heroes/Idle/hero_idle_1.png", false, false, 0, 0);
    GameObjectUtil::LinkComponent(baseHero, defaultSprite);

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

    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_1.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_2.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_3.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_4.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_5.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_6.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_7.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_8.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_9.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_10.png", false, false, 0, 0));
    celebratingSprites.push_back(std::make_shared<spic::Sprite>("resources/sprites/heroes/Celebrating/hero_celebrating_11.png", false, false, 0, 0));

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
    GameObjectUtil::LinkComponent(baseHero, idleAnimator);

    auto walkingAnimator = std::make_shared<spic::Animator>(static_cast<int>(walkingSprites.size()), walkingSprites);
    GameObjectUtil::LinkComponent(baseHero, walkingAnimator);

    auto diedAnimator = std::make_shared<spic::Animator>(static_cast<int>(diedSprites.size()), diedSprites);
    GameObjectUtil::LinkComponent(baseHero, diedAnimator);

    auto CelebratingAnimator = std::make_shared<spic::Animator>(static_cast<int>(celebratingSprites.size()), celebratingSprites);
    GameObjectUtil::LinkComponent(baseHero, CelebratingAnimator);

    auto healthBehaviour = std::make_shared<game::HealthBehaviour>(diedAnimator, defense);
    GameObjectUtil::LinkComponent(baseHero, healthBehaviour);

    auto userMovementBehaviour = std::make_shared<game::UserMovementBehaviour>(static_cast<float>(hero_velocity), idleAnimator, walkingAnimator, healthBehaviour);
    GameObjectUtil::LinkComponent(baseHero, userMovementBehaviour);

    auto attackBehaviour = std::make_shared<game::AttackBehaviour>(attack);
    GameObjectUtil::LinkComponent(baseHero, attackBehaviour);

    auto heroCollider = std::make_shared<spic::CircleCollider>((hero_width / 2) / hero_scale);
    GameObjectUtil::LinkComponent(baseHero, heroCollider);

    auto heroRigidBody = std::make_shared<spic::RigidBody>(hero_mass, 0, spic::BodyType::dynamicBody);
    GameObjectUtil::LinkComponent(baseHero, heroRigidBody);

    return baseHero;
}
