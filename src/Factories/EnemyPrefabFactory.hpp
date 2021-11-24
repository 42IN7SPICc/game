#ifndef SPIC_GAME_ENEMYPREFABFACTORY_HPP
#define SPIC_GAME_ENEMYPREFABFACTORY_HPP

#include "GameObject.hpp"
#include "Sprite.hpp"

#include "../Enums/EnemyName.hpp"

namespace game
{
    namespace types
    {
        using sprite_vector = std::vector<std::shared_ptr<spic::Sprite>>;
    }

    class EnemyPrefabFactory
    {
        public:
            static std::shared_ptr<spic::GameObject> CreateEnemy(game::EnemyName name);

        private:
            static std::shared_ptr<spic::GameObject> CreatePanzer();

            static std::shared_ptr<spic::GameObject> CreateGruppenfuhrer();

            static std::shared_ptr<spic::GameObject> CreateSchutze();

            static std::shared_ptr<spic::GameObject> CreateErkunder();

            static std::shared_ptr<spic::GameObject> CreateGhillieAnzugSchutze();

            static std::shared_ptr<spic::GameObject> CreateStabsarzt();

            static std::shared_ptr<spic::GameObject> CreateRaupenschlepper();

            static std::shared_ptr<spic::GameObject> CreateBaseEnemy(int attack, int defense, const types::sprite_vector& idleSprites, const types::sprite_vector& walkingSprites, const types::sprite_vector& diedSprites);

            static types::sprite_vector CreateSpriteVector(int max, const std::string& prefix, const std::string& extension = ".png", bool flipX = false, bool flipY = false);
    };
}


#endif //SPIC_GAME_ENEMYPREFABFACTORY_HPP
