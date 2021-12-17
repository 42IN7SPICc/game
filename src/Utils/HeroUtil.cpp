#include "HeroUtil.hpp"
#include "GameObject.hpp"
#include <stdexcept>
#include "BehaviourScript.hpp"
#include "../Scripts/Heroes/HealAbilityBehaviour.hpp"
#include "../Scripts/Heroes/InvisibilityAbilityBehaviour.hpp"
#include "../Scripts/Heroes/AirstrikeAbilityBehaviour.hpp"
#include "../Scripts/Heroes/IncreaseTowerFireRateAbilityBehaviour.hpp"
#include "../Scripts/Heroes/EnemySuicideAbilityBehaviour.hpp"

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

    throw std::runtime_error("The given hero doesn't have a name.");
}

std::string game::HeroUtil::NameToAbilityString(game::HeroName heroName)
{
    switch (heroName)
    {
        case DesmondDoss:
            return "Zichzelf helen";
        case BernardIJzerdraat:
            return "Ontzichtbaar worden voor vijanden";
        case FranklinDRoosevelt:
            return "Luchtaanvallen inroepen";
        case WinstonChurchill:
            return "Verhogen schietsnelheid van torens";
        case JosephStalin:
            return "Vijanden op elkaar laten schieten";
    }

    throw std::runtime_error("The given hero doesn't have an ability.");
}
