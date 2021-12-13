#ifndef SPIC_GAME_HEROUTIL_HPP
#define SPIC_GAME_HEROUTIL_HPP

#include <string>
#include <vector>
#include "../Enums/HeroName.hpp"
#include "../Scripts/Common/CoolDownBehaviour.hpp"

namespace game
{
    /**
     * @brief A Utility for Heroes
     */
    class HeroUtil
    {
        public:
            /**
             * @brief Turns hero enum into std::string
             * @param heroName Name of the hero
             * @return String of the hero name
             */
            static std::string NameToString(game::HeroName heroName);

            /**
             * @brief Turns ability of a hero enum into std::string
             * @param heroName Name of the hero
             * @return String of the hero ability
             */
            static std::string NameToAbilityString(game::HeroName heroName);

            /**
             * @brief Get the abilityCooldownBehaviour of a hero
             * @param heroName heroName as a string
             * @return CoolDownBehaviour of the ability
             */
            static std::shared_ptr<game::CoolDownBehaviour> GetAbilityCoolDownBehaviour(std::shared_ptr<spic::GameObject> hero);
    };
}


#endif
