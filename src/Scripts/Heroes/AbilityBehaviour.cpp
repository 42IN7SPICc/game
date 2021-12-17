#include "AbilityBehaviour.hpp"
#include "Utils/GameObjectUtil.hpp"

game::AbilityBehaviour::AbilityBehaviour(double coolDown) : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(coolDown)))
{

}

void game::AbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _healthBehaviour = parent->GetComponent<game::HealthBehaviour>();
    spic::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
}

std::shared_ptr<game::CoolDownBehaviour>& game::AbilityBehaviour::GetCoolDownBehaviour()
{
    return _coolDownBehaviour;
}

void game::AbilityBehaviour::OnUpdate()
{
    //
}

void game::AbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::AbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::AbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}
