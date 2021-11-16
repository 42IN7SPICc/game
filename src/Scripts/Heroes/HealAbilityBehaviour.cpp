#include "HealAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Input.hpp"

const int heal_ability_cool_down = 5;

game::HealAbilityBehaviour::HealAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(heal_ability_cool_down)))
{

}

void game::HealAbilityBehaviour::OnStart()
{
    _parent = GameObject().lock();
    _coolDownBehaviour->GameObject(_parent);
    _parent->AddComponent(_coolDownBehaviour);
    _healthBehaviour = _parent->GetComponent<HealthBehaviour>();
}

void game::HealAbilityBehaviour::OnUpdate()
{
    if (spic::Input::GetKey(spic::Input::KeyCode::SPACE))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _healthBehaviour->Health(_healthBehaviour->Health() + 1);
            _coolDownBehaviour->CooledDown(false);
        }
    }
}

void game::HealAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::HealAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::HealAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}
