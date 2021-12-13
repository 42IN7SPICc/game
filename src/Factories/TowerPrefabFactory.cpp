#include "TowerPrefabFactory.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../TowerConstants.hpp"

#include <stdexcept>
#include <Animator.hpp>

using namespace game;

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateTower(TowerName name)
{
    switch (name)
    {
        case TowerName::Bomber:
            return CreateBomber();
        case TowerName::Shotgun:
            return CreateShotgun();
        case TowerName::Flamethrower:
            return CreateFlamethrower();
        case TowerName::Sniper:
            return CreateSniper();
    }

    throw std::runtime_error("Tower not implemented.");
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBaseTower(const spic::types::sprite_vector& shootingSprites, std::shared_ptr<AttackBehaviour> attackBehaviour)
{
    auto baseTower = std::make_shared<spic::GameObject>("Tower", "tower", Layer::Game);

    auto shootingAnimator = std::make_shared<spic::Animator>(static_cast<int>(shootingSprites.size()), shootingSprites);
    spic::GameObjectUtil::LinkComponent(baseTower, shootingAnimator);

    attackBehaviour->FollowTarget(true);
    attackBehaviour->Animator(shootingAnimator);
    spic::GameObjectUtil::LinkComponent(baseTower, attackBehaviour);

    return baseTower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBomber()
{
    spic::types::sprite_vector shootingSprites = spic::AnimatorUtil::CreateSpriteVector(6, "resources/sprites/towers/shooting/tower_shooting_", BomberTowerColor<spic::Color>(), SortingLayer::Enemy);
    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Bomb, BomberTowerFireRate, BomberTowerRange, BomberTowerDamage, BomberTowerBulletSpeed, INT16_MAX, BomberTowerExplosionRange);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);
    auto defaultSprite = std::make_shared<spic::Sprite>(shootingSprites[0]->Texture(), BomberTowerColor<spic::Color>(), false, false, SortingLayer::Tower, 0);

    spic::GameObjectUtil::LinkComponent(tower, defaultSprite);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateShotgun()
{
    spic::types::sprite_vector shootingSprites = spic::AnimatorUtil::CreateSpriteVector(6, "resources/sprites/towers/shooting/tower_shooting_", ShotgunTowerColor<spic::Color>(), SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Normal, ShotgunTowerFireRate, ShotgunTowerRange, ShotgunTowerDamage, ShotgunTowerBulletSpeed);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);
    auto defaultSprite = std::make_shared<spic::Sprite>(shootingSprites[0]->Texture(), ShotgunTowerColor<spic::Color>(), false, false, SortingLayer::Tower, 0);

    spic::GameObjectUtil::LinkComponent(tower, defaultSprite);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateFlamethrower()
{
    spic::types::sprite_vector shootingSprites = spic::AnimatorUtil::CreateSpriteVector(6, "resources/sprites/towers/shooting/tower_shooting_", FlamethrowerTowerColor<spic::Color>(), SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Penetrating, FlamethrowerTowerFireRate, FlamethrowerTowerRange, FlamethrowerTowerDamage, FlamethrowerTowerBulletSpeed);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);
    auto defaultSprite = std::make_shared<spic::Sprite>(shootingSprites[0]->Texture(), FlamethrowerTowerColor<spic::Color>(), false, false, SortingLayer::Tower, 0);

    spic::GameObjectUtil::LinkComponent(tower, defaultSprite);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateSniper()
{
    spic::types::sprite_vector shootingSprites = spic::AnimatorUtil::CreateSpriteVector(6, "resources/sprites/towers/shooting/tower_shooting_", SniperTowerColor<spic::Color>(), SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Normal, SniperTowerFireRate, SniperTowerRange, SniperTowerDamage, SniperTowerBulletSpeed, SniperMaxPenetrating);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);
    auto defaultSprite = std::make_shared<spic::Sprite>(shootingSprites[0]->Texture(), SniperTowerColor<spic::Color>(), false, false, SortingLayer::Tower, 0);

    spic::GameObjectUtil::LinkComponent(tower, defaultSprite);

    return tower;
}
