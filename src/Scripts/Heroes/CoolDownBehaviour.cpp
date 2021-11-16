#include "CoolDownBehaviour.hpp"
#include "Time.hpp"

game::CoolDownBehaviour::CoolDownBehaviour(int coolDown) : _cooledDown(false), _coolDown(coolDown)
{

}

void game::CoolDownBehaviour::OnStart()
{

}

void game::CoolDownBehaviour::OnUpdate()
{
    if(_cooledDown) return;

    double time_reference = spic::Time::DeltaTime() * spic::Time::TimeScale();
    _coolDown -= time_reference;

    if(_cooledDown <= 0) {
        _cooledDown = true;
    }
}

void game::CoolDownBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::CoolDownBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::CoolDownBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}

bool game::CoolDownBehaviour::CooledDown() const
{
    return _cooledDown;
}

void game::CoolDownBehaviour::CooledDown(bool cooledDown)
{
    _cooledDown = cooledDown;
}
