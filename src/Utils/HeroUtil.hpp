#ifndef SPIC_GAME_HEROUTIL_HPP
#define SPIC_GAME_HEROUTIL_HPP

#include <string>
#include "../Enums/HeroName.hpp"

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
    };
}


#endif
