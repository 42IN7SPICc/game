#include "HealAbilityBehaviour.hpp"
#include "Input.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../../HeroConstants.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"

game::HealAbilityBehaviour::HealAbilityBehaviour() : AbilityBehaviour(DesmondDossHealAbilityCoolDown)
{

}

void game::HealAbilityBehaviour::OnUpdate()
{
    if(_healthBehaviour->Health() <= 0) return;

    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::HealAbility, true, false, 1.0);
            spic::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);
            _healthBehaviour->Health(_healthBehaviour->Health() + DesmondDossHealAbilityAmount);
            _coolDownBehaviour->CooledDown(false);
        }
    }
}
