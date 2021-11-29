#include "TowerPrefabFactory.hpp"

#include <stdexcept>

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

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBaseTower()
{
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateBomber()
{
    auto tower = CreateBaseTower();

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateShotgun()
{
    auto tower = CreateBaseTower();

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateFlamethrower()
{
    auto tower = CreateBaseTower();

    return tower;
}

std::shared_ptr<spic::GameObject> TowerPrefabFactory::CreateSniper()
{
    auto tower = CreateBaseTower();

    return tower;
}
