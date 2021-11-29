#include "TowerPrefabFactory.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Common/AttackBehaviour.hpp"
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

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBaseTower(const types::sprite_vector& sprites)
{
    auto baseTower = std::make_shared<spic::GameObject>("Tower", "tower", Layer::Game);

    auto defaultSprite = std::make_shared<spic::Sprite>(sprites[0]->Texture(), false, false, SortingLayer::Tower, 0);
    GameObjectUtil::LinkComponent(baseTower, defaultSprite);

    auto idleAnimator = std::make_shared<spic::Animator>(static_cast<int>(sprites.size()), sprites);
    GameObjectUtil::LinkComponent(baseTower, idleAnimator);

    return baseTower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBomber()
{
    types::sprite_vector sprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/towers/Idle/tower_idle_", SortingLayer::Enemy);

    auto tower = CreateBaseTower(sprites);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateShotgun()
{
    types::sprite_vector sprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/towers/Idle/tower_idle_", SortingLayer::Enemy);

    auto tower = CreateBaseTower(sprites);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateFlamethrower()
{
    types::sprite_vector sprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/towers/Idle/tower_idle_", SortingLayer::Enemy);

    auto tower = CreateBaseTower(sprites);

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateSniper()
{
    types::sprite_vector sprites = AnimatorUtil::CreateSpriteVector(10, "resources/sprites/towers/Idle/tower_idle_", SortingLayer::Enemy);

    auto tower = CreateBaseTower(sprites);

    return tower;
}
