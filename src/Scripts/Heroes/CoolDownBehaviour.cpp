#include "CoolDownBehaviour.hpp"
#include "Time.hpp"
#include "Debug.hpp"

game::CoolDownBehaviour::CoolDownBehaviour(int coolDown) : _cooledDown(false), _coolDown(coolDown), _minCoolDown(coolDown)
{

}

void game::CoolDownBehaviour::OnStart()
{
    spic::Debug::Log("CoolDownBehaviour Started");
}

void game::CoolDownBehaviour::OnUpdate()
{
    if(_cooledDown) return;

    double timescale = spic::Time::TimeScale();
    double deltaTime = spic::Time::DeltaTime();
    double time_difference = timescale * deltaTime;
    _coolDown -= time_difference;

    if(_coolDown <= 0) {
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
    if(!cooledDown) _coolDown = _minCoolDown;
}

double game::CoolDownBehaviour::CoolDown() const
{
    return _coolDown;
}

void game::CoolDownBehaviour::CooledDown(double coolDown)
{
    _coolDown = coolDown;
}
