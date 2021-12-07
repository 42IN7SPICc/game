#include "HeroUtil.hpp"
#include <stdexcept>

std::string game::HeroUtil::NameToString(game::HeroName heroName)
{
    switch (heroName)
    {
        case DesmondDoss:
            return "Desmond Doss";
        case BernardIJzerdraat:
            return "Bernard IJzerdraat";
        case FranklinDRoosevelt:
            return "Franklin D Roosevelt";
        case WinstonChurchill:
            return "Winston Churchill";
        case JosephStalin:
            return "Joseph Stalin";
    }

    throw std::runtime_error("Couldn't find a string with this HeroName");
}