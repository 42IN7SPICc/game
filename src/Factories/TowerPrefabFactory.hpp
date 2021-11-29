#ifndef SPIC_GAME_TOWERPREFABFACTORY_HPP
#define SPIC_GAME_TOWERPREFABFACTORY_HPP

#include "../Enums/TowerName.hpp"

#include "GameObject.hpp"

namespace game
{
    class TowerPrefabFactory
    {
        private:
            static std::shared_ptr<spic::GameObject> CreateDesmondDoss();

            static std::shared_ptr<spic::GameObject> CreateBernardIJzerdraat();

            static std::shared_ptr<spic::GameObject> CreateFranklinDRoosevelt();

            static std::shared_ptr<spic::GameObject> CreateWinstonChurchill();

            static std::shared_ptr<spic::GameObject> CreateJosephStalin();

            static std::shared_ptr<spic::GameObject> CreateBaseTower(int attack, int defense);

        public:
            static std::shared_ptr<spic::GameObject> CreateTower(TowerName name);
    };
}

#endif //SPIC_GAME_TOWERPREFABFACTORY_HPP
