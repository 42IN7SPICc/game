#include "HealAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "Text.hpp"

game::HealAbilityBehaviour::HealAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(5)))
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
    auto textField1 = std::dynamic_pointer_cast<spic::Text>(GameObject().lock()->Children()[0]);
    auto textField2 = std::dynamic_pointer_cast<spic::Text>(GameObject().lock()->Children()[1]);

    if(spic::Input::GetKey(spic::Input::KeyCode::SPACE))
    {
        if(_coolDownBehaviour->CooledDown()) {
            _healthBehaviour->Health(_healthBehaviour->Health() + 1);
            _coolDownBehaviour->CooledDown(false);
        }
    }

    if(spic::Input::GetKeyDown(spic::Input::KeyCode::LEFT_ALT))
    {
        _healthBehaviour->Health(_healthBehaviour->Health() - 1);
    }

    textField1->Content(std::to_string(_healthBehaviour->Health()));
    textField2->Content(std::to_string(_coolDownBehaviour->CoolDown()));
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
