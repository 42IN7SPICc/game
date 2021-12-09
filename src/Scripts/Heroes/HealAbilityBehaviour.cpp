#include "HealAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../Constants.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"

game::HealAbilityBehaviour::HealAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(HealAbilityCoolDown)))
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
            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::HealAbility, true, false, 1.0);
            game::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);
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
