#include "TowerPrefabFactory.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Utils/GameObjectUtil.hpp"

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

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBaseTower(const types::sprite_vector& shootingSprites, std::shared_ptr<AttackBehaviour> attackBehaviour)
{
    auto baseTower = std::make_shared<spic::GameObject>("Tower", "tower", Layer::Game);

    auto defaultSprite = std::make_shared<spic::Sprite>(shootingSprites[0]->Texture(), false, false, SortingLayer::Tower, 0);
    GameObjectUtil::LinkComponent(baseTower, defaultSprite);

    auto shootingAnimator = std::make_shared<spic::Animator>(static_cast<int>(shootingSprites.size()), shootingSprites);
    GameObjectUtil::LinkComponent(baseTower, shootingAnimator);

    attackBehaviour->FollowTarget(true);
    attackBehaviour->Animator(shootingAnimator);
    GameObjectUtil::LinkComponent(baseTower, attackBehaviour);

    return baseTower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBomber()
{
    types::sprite_vector shootingSprites = AnimatorUtil::CreateSpriteVector(1, "resources/sprites/towers/shooting/tower_shooting_", SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Bomb, 3, 200, 25, 10, 50);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateShotgun()
{
    types::sprite_vector shootingSprites = AnimatorUtil::CreateSpriteVector(1, "resources/sprites/towers/shooting/tower_shooting_", SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Normal, 5, 250, 20, 15);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateFlamethrower()
{
    types::sprite_vector shootingSprites = AnimatorUtil::CreateSpriteVector(1, "resources/sprites/towers/shooting/tower_shooting_", SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("enemy", BulletType::Penetrating, 3, 150, 2, 20);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateSniper()
{
    types::sprite_vector shootingSprites = AnimatorUtil::CreateSpriteVector(1, "resources/sprites/towers/shooting/tower_shooting_", SortingLayer::Enemy);

    auto attackBehaviour = std::make_shared<AttackBehaviour>("hero", BulletType::Normal, 8, 500, 50, 30);

    auto tower = CreateBaseTower(shootingSprites, attackBehaviour);

    return tower;
}
