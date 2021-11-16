#include "CoolDownBehaviour.hpp"
#include "Time.hpp"

game::CoolDownBehaviour::CoolDownBehaviour(int coolDown) : _cooledDown(true), _coolDown(coolDown)
{

}

void game::CoolDownBehaviour::OnStart()
{

}

void game::CoolDownBehaviour::OnUpdate()
{
    double time_reference = spic::Time::DeltaTime() * spic::Time::TimeScale();
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
