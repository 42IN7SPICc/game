#ifndef SPIC_GAME_HEROUTIL_HPP
#define SPIC_GAME_HEROUTIL_HPP

#include <string>
#include "../Enums/HeroName.hpp"

namespace game
{
    class HeroUtil
    {
        public:
            static std::string NameToString(game::HeroName heroName);
    };
}


#endif
