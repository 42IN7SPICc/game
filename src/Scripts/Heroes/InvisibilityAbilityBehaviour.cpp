#include "InvisibilityAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Engine.hpp"
#include "Input.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"
#include "../../HeroConstants.hpp"

game::InvisibilityAbilityBehaviour::InvisibilityAbilityBehaviour() : AbilityBehaviour(BernardIJzerdraatAbilityCooldown),
                                                                     _abilityActive(false)
{

}

void game::InvisibilityAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _sprite = parent->GetComponent<spic::Sprite>();
}

void game::InvisibilityAbilityBehaviour::OnUpdate()
{
    if(_healthBehaviour->Health() <= 0) return;

    if (_abilityActive)
    {
        _sprite->Color(spic::Color(1, 1, 1, 0.5));
        auto invisibilityObject = spic::GameObject::Find("invisibilityDurationObject");
        if (invisibilityObject && invisibilityObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            invisibilityObject->Destroy(invisibilityObject);
            _abilityActive = false;
            _coolDownBehaviour->CooledDown(false);
            _healthBehaviour->Invincibility(false);
            _sprite->Color(spic::Color::transparent());
        }
        return;
    }

    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _abilityActive = true;
            _healthBehaviour->Invincibility(true);
            auto invisibilityDurationObject = std::make_shared<spic::GameObject>("invisibilityDurationObject", "invisibilityDurationObject", Layer::Game);
            auto invisibilityDurationCooldown = std::make_shared<CoolDownBehaviour>(BernardIJzerdraatAbilityDuration);
            spic::GameObjectUtil::LinkComponent(invisibilityDurationObject, invisibilityDurationCooldown);

            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::ActivateAbility, true, false, 1.0);
            spic::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);

            auto scene = spic::Engine::Instance().PeekScene();
            scene->Contents().push_back(invisibilityDurationObject);
        }
    }
}