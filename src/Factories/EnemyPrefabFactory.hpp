#ifndef SPIC_GAME_ENEMYPREFABFACTORY_HPP
#define SPIC_GAME_ENEMYPREFABFACTORY_HPP

#include "GameObject.hpp"

#include "../Enums/EnemyName.hpp"

namespace game
{
    class EnemyPrefabFactory
    {
        public:
            static std::shared_ptr<spic::GameObject> CreateEnemy(game::EnemyName name);

        private:
            static std::shared_ptr<spic::GameObject> CreateBaseEnemy(int attack, int defense);
    };
}


#endif //SPIC_GAME_ENEMYPREFABFACTORY_HPP
