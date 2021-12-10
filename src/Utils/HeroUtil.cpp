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

    throw std::runtime_error("Couldn't find a string with this HeroName");
}

std::shared_ptr<game::CoolDownBehaviour> game::HeroUtil::GetAbilityCoolDownBehaviour(std::shared_ptr<spic::GameObject> hero)
{
    auto healAbility = hero->GetComponent<game::HealAbilityBehaviour>();
    if(healAbility) {
        return healAbility->GetCoolDownBehaviour();
    }
    auto invisibilityAbility = hero->GetComponent<game::InvisibilityAbilityBehaviour>();
    if(invisibilityAbility) {
        return invisibilityAbility->GetCoolDownBehaviour();
    }
    auto airstrikeAbility = hero->GetComponent<game::AirstrikeAbilityBehaviour>();
    if(airstrikeAbility) {
        return airstrikeAbility->GetCoolDownBehaviour();
    }
    auto fireRateAbility = hero->GetComponent<game::IncreaseTowerFireRateAbilityBehaviour>();
    if(fireRateAbility) {
        return fireRateAbility->GetCoolDownBehaviour();
    }
    auto suicideAbility = hero->GetComponent<game::EnemySuicideAbilityBehaviour>();
    if(suicideAbility) {
        return suicideAbility->GetCoolDownBehaviour();
    }

    throw std::runtime_error("Couldn't find a CoolDownBehaviour for this hero");
}
