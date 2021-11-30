#ifndef SPIC_GAME_TOWERPREFABFACTORY_HPP
#define SPIC_GAME_TOWERPREFABFACTORY_HPP

#include "../Enums/TowerName.hpp"
#include "../Scripts/Common/AttackBehaviour.hpp"
#include "../Utils/AnimatorUtil.hpp"

#include "GameObject.hpp"

namespace game
{
    /**
     * @brief Factory for tower.
     */
    class TowerPrefabFactory
    {
        private:
            /**
             * @brief Create a new Bomber tower.
             * @return The tower object.
             */
            static std::shared_ptr<spic::GameObject> CreateBomber();

            /**
             * @brief Create a new Shotgun tower.
             * @return The tower object.
             */
            static std::shared_ptr<spic::GameObject> CreateShotgun();

            /**
             * @brief Create a new Flamethrower tower.
             * @return The tower object.
             */
            static std::shared_ptr<spic::GameObject> CreateFlamethrower();

            /**
             * @brief Create a new Sniper tower.
             * @return The tower object.
             */
            static std::shared_ptr<spic::GameObject> CreateSniper();

            /**
             * @brief Create a new template tower with given settings.
             * @param shootingSprites A list of sprites when the tower is shooting.
             * @param attackBehaviour A script that handles attacking the enemies.
             * @return The tower object.
             */
            static std::shared_ptr<spic::GameObject> CreateBaseTower(const types::sprite_vector& shootingSprites, std::shared_ptr<AttackBehaviour> attackBehaviour);

        public:
            /**
             * @brief Create a new tower object based on a given name.
             * @param name The name of the tower.
             * @return The tower object.
             */
            static std::shared_ptr<spic::GameObject> CreateTower(TowerName name);
    };
}

#endif //SPIC_GAME_TOWERPREFABFACTORY_HPP
