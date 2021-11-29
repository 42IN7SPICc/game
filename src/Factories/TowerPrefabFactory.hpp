#ifndef SPIC_GAME_TOWERPREFABFACTORY_HPP
#define SPIC_GAME_TOWERPREFABFACTORY_HPP

#include "../Enums/TowerName.hpp"
#include "../Scripts/Common/AttackBehaviour.hpp"
#include "../Utils/AnimatorUtil.hpp"

#include "GameObject.hpp"

namespace game
{
    class TowerPrefabFactory
    {
        private:
            static std::shared_ptr<spic::GameObject> CreateBomber();

            static std::shared_ptr<spic::GameObject> CreateShotgun();

            static std::shared_ptr<spic::GameObject> CreateFlamethrower();

            static std::shared_ptr<spic::GameObject> CreateSniper();

            static std::shared_ptr<spic::GameObject> CreateBaseTower(const types::sprite_vector& shootingSprites, std::shared_ptr<AttackBehaviour> attackBehaviour);

        public:
            static std::shared_ptr<spic::GameObject> CreateTower(TowerName name);
    };
}

#endif //SPIC_GAME_TOWERPREFABFACTORY_HPP
