#include "HeroPrefabFactory.hpp"

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateHero(game::HeroName name)
{
    auto base_hero = CreateBaseHero();
    switch (name)
    {
        case DesmondDoss:
            return CreateDesmondDoss(base_hero);
        case BernardIJzerdraat:
            return CreateBernardIJzerdraat(base_hero);
        case FranklinDRoosevelt:
            return CreateFranklinDRoosevelt(base_hero);
        case WinstonChurchill:
            return CreateWinstonChurchill(base_hero);
        case JosephStalin:
            return CreateJosephStalin(base_hero);
    }
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateDesmondDoss(std::shared_ptr<spic::GameObject> base_hero)
{
    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateBernardIJzerdraat(std::shared_ptr<spic::GameObject> base_hero)
{
    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateFranklinDRoosevelt(std::shared_ptr<spic::GameObject> base_hero)
{
    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateWinstonChurchill(std::shared_ptr<spic::GameObject> base_hero)
{
    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateJosephStalin(std::shared_ptr<spic::GameObject> base_hero)
{
    return base_hero;
}

std::shared_ptr<spic::GameObject> game::HeroPrefabFactory::CreateBaseHero()
{
    auto base_hero = std::shared_ptr<spic::GameObject>();
    return base_hero;
}
