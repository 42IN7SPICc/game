#ifndef SPIC_GAME_HEROPREFABFACTORY_HPP
#define SPIC_GAME_HEROPREFABFACTORY_HPP

#include "GameObject.hpp"

namespace game
{
    enum HeroName
    {
        DesmondDoss,
        BernardIJzerdraat,
        FranklinDRoosevelt,
        WinstonChurchill,
        JosephStalin
    };

    class HeroPrefabFactory
    {
        private:
            static std::shared_ptr<spic::GameObject> CreateDesmondDoss();

            static std::shared_ptr<spic::GameObject> CreateBernardIJzerdraat();

            static std::shared_ptr<spic::GameObject> CreateFranklinDRoosevelt();

            static std::shared_ptr<spic::GameObject> CreateWinstonChurchill();

            static std::shared_ptr<spic::GameObject> CreateJosephStalin();

            static std::shared_ptr<spic::GameObject> CreateBaseHero(int attack, int defense);

        public:
            static std::shared_ptr<spic::GameObject> CreateHero(HeroName name);
    };
}


#endif //SPIC_GAME_HEROPREFABFACTORY_HPP
