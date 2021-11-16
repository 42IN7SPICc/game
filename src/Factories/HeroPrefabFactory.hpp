#ifndef SPIC_GAME_HEROPREFABFACTORY_HPP
#define SPIC_GAME_HEROPREFABFACTORY_HPP

#include "GameObject.hpp"

namespace game {
    enum HeroName {
        DesmondDoss,
        BernardIJzerdraat,
        FranklinDRoosevelt,
        WinstonChurchill,
        JosephStalin
    };

    class HeroPrefabFactory {
    private:
        static std::shared_ptr<spic::GameObject> CreateDesmondDoss(std::shared_ptr<spic::GameObject> base_hero);
        static std::shared_ptr<spic::GameObject> CreateBernardIJzerdraat(std::shared_ptr<spic::GameObject> base_hero);
        static std::shared_ptr<spic::GameObject> CreateFranklinDRoosevelt(std::shared_ptr<spic::GameObject> base_hero);
        static std::shared_ptr<spic::GameObject> CreateWinstonChurchill(std::shared_ptr<spic::GameObject> base_hero);
        static std::shared_ptr<spic::GameObject> CreateJosephStalin(std::shared_ptr<spic::GameObject> base_hero);
        static std::shared_ptr<spic::GameObject> CreateBaseHero();
    public:
        static std::shared_ptr<spic::GameObject> CreateHero(HeroName name);
    };
}


#endif //SPIC_GAME_HEROPREFABFACTORY_HPP
