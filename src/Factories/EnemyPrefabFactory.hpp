#ifndef SPIC_GAME_ENEMYPREFABFACTORY_HPP
#define SPIC_GAME_ENEMYPREFABFACTORY_HPP

#include "GameObject.hpp"
#include "Sprite.hpp"

#include "../Utils/AnimatorUtil.hpp"

#include "../Enums/EnemyName.hpp"

namespace game
{
    class EnemyPrefabFactory
    {
        public:
            static std::shared_ptr<spic::GameObject> CreateEnemy(EnemyName name);

        private:
            static std::shared_ptr<spic::GameObject> CreatePanzer();

            static std::shared_ptr<spic::GameObject> CreateGruppenfuhrer();

            static std::shared_ptr<spic::GameObject> CreateSchutze();

            static std::shared_ptr<spic::GameObject> CreateErkunder();

            static std::shared_ptr<spic::GameObject> CreateGhillieAnzugSchutze();

            static std::shared_ptr<spic::GameObject> CreateStabsarzt();

            static std::shared_ptr<spic::GameObject> CreateRaupenschlepper();

            static std::shared_ptr<spic::GameObject> CreateBaseEnemy(int attack, int defense, const types::sprite_vector& idleSprites, const types::sprite_vector& walkingSprites, const types::sprite_vector& diedSprites);
    };
}


#endif //SPIC_GAME_ENEMYPREFABFACTORY_HPP
