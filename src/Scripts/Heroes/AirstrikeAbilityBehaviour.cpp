#include "AirstrikeAbilityBehaviour.hpp"
#include "../../Constants.hpp"
#include "../Common/CoolDownBehaviour.hpp"

game::AirstrikeAbilityBehaviour::AirstrikeAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(WinstonChurchillAirstrikeAbilityCooldown)))
{

}

void game::AirstrikeAbilityBehaviour::OnStart()
{
    //
}

void game::AirstrikeAbilityBehaviour::OnUpdate()
{
    //
}

void game::AirstrikeAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::AirstrikeAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::AirstrikeAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}
