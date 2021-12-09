#include "HealAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../HeroConstants.hpp"

game::HealAbilityBehaviour::HealAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(DesmondDossHealAbilityCoolDown)))
{

}

void game::HealAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    game::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
    _healthBehaviour = parent->GetComponent<HealthBehaviour>();
}

void game::HealAbilityBehaviour::OnUpdate()
{
    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _healthBehaviour->Health(_healthBehaviour->Health() + DesmondDossHealAbilityAmount);
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
