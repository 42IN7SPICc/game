#include "HealAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "Text.hpp"

game::HealAbilityBehaviour::HealAbilityBehaviour() : _coolDownBehaviour(CoolDownBehaviour(5))
{

}

void game::HealAbilityBehaviour::OnStart()
{
    _parent = GameObject().lock();
    _healthBehaviour = _parent->GetComponent<HealthBehaviour>();
}

void game::HealAbilityBehaviour::OnUpdate()
{
    auto textField = std::dynamic_pointer_cast<spic::Text>(GameObject().lock()->Children()[0]);

    if(spic::Input::GetKeyDown(spic::Input::KeyCode::SPACE))
    {
        _healthBehaviour->Health(_healthBehaviour->Health() + 1);
    }

    if(spic::Input::GetKeyDown(spic::Input::KeyCode::LEFT_ALT))
    {
        _healthBehaviour->Health(_healthBehaviour->Health() - 1);
    }

    textField->Content(std::to_string(_healthBehaviour->Health()));
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
