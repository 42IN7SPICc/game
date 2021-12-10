#ifndef SPIC_GAME_ENEMYPREFABFACTORY_HPP
#define SPIC_GAME_ENEMYPREFABFACTORY_HPP

#include "GameObject.hpp"
#include "Sprite.hpp"

#include "../Utils/AnimatorUtil.hpp"

#include "../Enums/EnemyName.hpp"

namespace game
{
    /**
     * @brief Factory for enemies.
     */
    class EnemyPrefabFactory
    {
        public:
            /**
             * @brief Create a new enemy based on the given name.
             * @param name The name of the enemy.
             * @param hasHealthBar Whether the hero has a health bar above themself.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateEnemy(game::EnemyName name, bool hasHealthBar);

        private:
            /**
             * @brief Create a new Panzer enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreatePanzer();

            /**
             * @brief Create a new Gruppenfuhrer enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateGruppenfuhrer();

            /**
             * @brief Create a new Schutze enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateSchutze();

            /**
             * @brief Create a new Erkunder enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateErkunder();

            /**
             * @brief Create a new GhillieAnzugSchutze enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateGhillieAnzugSchutze();

            /**
             * @brief Create a new Stabsarzt enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateStabsarzt();

            /**
             * @brief Create a new Raupenschlepper enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateRaupenschlepper();

            /**
             * @brief Create a enemy template with given settings.
             * @param attack The amount of damage the enemy does in impact.
             * @param health The health of the enemy.
             * @param speedMultiplier The speed multiplier for the enemy.
             * @param idleSprites A list of sprites when the enemy is idle.
             * @param walkingSprites A list of sprites when the enemy is walking.
             * @param diedSprites A list of sprites when the enemy is dying.
             * @param value Amount of money received on killing the enemy.
             * @return The enemy object.
             */
            static std::shared_ptr<spic::GameObject> CreateBaseEnemy(int attack, int health, double speedMultiplier, const types::sprite_vector& idleSprites, const types::sprite_vector& walkingSprites, const types::sprite_vector& diedSprites, int value);
    };
}


#endif //SPIC_GAME_ENEMYPREFABFACTORY_HPP
