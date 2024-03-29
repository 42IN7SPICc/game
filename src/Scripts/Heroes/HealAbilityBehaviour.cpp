#include "HealAbilityBehaviour.hpp"
#include "Input.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../../HeroConstants.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"

game::HealAbilityBehaviour::HealAbilityBehaviour() : AbilityBehaviour(DesmondDossHealAbilityCoolDown)
{

}

void game::HealAbilityBehaviour::OnStart()
{
    game::AbilityBehaviour::OnStart();
    auto parent = GameObject().lock();
    spic::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
    _healthBehaviour = parent->GetComponent<HealthBehaviour>();
    _audioSource = AudioSourcePrefabFactory::CreateAudioSource(game::AudioClipName::HealAbility, false, false, 1.0);
    spic::GameObjectUtil::LinkComponent(parent, _audioSource);

}

void game::HealAbilityBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0) return;

    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _audioSource->Play(false);
            _healthBehaviour->Health(_healthBehaviour->Health() + DesmondDossHealAbilityAmount);
            _coolDownBehaviour->CooledDown(false);
        }
    }
}
