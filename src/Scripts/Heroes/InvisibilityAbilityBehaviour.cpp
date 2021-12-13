#include "InvisibilityAbilityBehaviour.hpp"
#include "../../HeroConstants.hpp"
#include <stdexcept>
#include "GameObject.hpp"
#include "Engine.hpp"
#include "Input.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"

game::InvisibilityAbilityBehaviour::InvisibilityAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(BernardIJzerdraatAbilityCooldown))),
                                                                     _abilityActive(false)
{

}

void game::InvisibilityAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _healthBehaviour = parent->GetComponent<game::HealthBehaviour>();
    if (!_healthBehaviour)
    {
        throw std::runtime_error("The EnemyInvisibleBehaviour requires a HealthBehaviour");
    }
    _sprite = parent->GetComponent<spic::Sprite>();
    spic::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
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

void game::InvisibilityAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::InvisibilityAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::InvisibilityAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

std::shared_ptr<game::CoolDownBehaviour>& game::InvisibilityAbilityBehaviour::GetCoolDownBehaviour()
{
    return _coolDownBehaviour;
}
