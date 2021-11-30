#ifndef SPIC_GAME_HEROPREFABFACTORY_HPP
#define SPIC_GAME_HEROPREFABFACTORY_HPP

#include "GameObject.hpp"
#include "../Enums/HeroName.hpp"

namespace game
{
    /**
     * @brief Factory for heroes.
     */
    class HeroPrefabFactory
    {
        private:
            /**
             * @brief Create a new DesmondDoss hero.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateDesmondDoss();

            /**
             * @brief Create a new BernardIJzerdraat hero.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateBernardIJzerdraat();

            /**
             * @brief Create a new FranklinDRoosevelt hero.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateFranklinDRoosevelt();

            /**
             * @brief Create a new WinstonChurchill hero.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateWinstonChurchill();

            /**
             * @brief Create a new JosephStalin hero.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateJosephStalin();

            /**
             * @brief Create a new template hero with given settings.
             * @param attack The amount of damage the hero does on impact.
             * @param defense The amount of health the hero has.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateBaseHero(int attack, int defense);

        public:
            /**
             * @brief Create a new hero based on the given name.
             * @param name The name of the hero.
             * @return The hero object.
             */
            static std::shared_ptr<spic::GameObject> CreateHero(game::HeroName name);
    };
}


#endif //SPIC_GAME_HEROPREFABFACTORY_HPP
