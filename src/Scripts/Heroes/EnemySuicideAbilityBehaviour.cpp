#include "EnemySuicideAbilityBehaviour.hpp"
#include "../../HeroConstants.hpp"
#include "Input.hpp"
#include "GameObject.hpp"
#include "../Common/AttackBehaviour.hpp"
#include "../../Enums/Layer.hpp"
#include "Engine.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"

game::EnemySuicideAbilityBehaviour::EnemySuicideAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(JosephStalinAbilityCooldown))),
                                                                     _abilityActive(false)
{

}

void game::EnemySuicideAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _healthBehaviour = parent->GetComponent<game::HealthBehaviour>();
    spic::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
}

void game::EnemySuicideAbilityBehaviour::OnUpdate()
{
    if(_healthBehaviour->Health() <= 0) return;

    if (_abilityActive)
    {
        auto enemySuicideObject = spic::GameObject::Find("enemySuicideObject");
        if (enemySuicideObject && enemySuicideObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            enemySuicideObject->Destroy(enemySuicideObject);
            _abilityActive = false;
            _coolDownBehaviour->CooledDown(false);
            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for(auto& enemy : enemies) {
                auto attackBehaviour = enemy->GetComponent<game::AttackBehaviour>();
                if (attackBehaviour)
                {
                    attackBehaviour->TargetTag("hero");
                }
            }
        }
        return;
    }

    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            //Get all enemies
            auto scene = spic::Engine::Instance().PeekScene();
            auto enemySuicideObject = std::make_shared<spic::GameObject>("enemySuicideObject", "enemySuicideObject", Layer::Game);

            auto abilityTimer = std::make_shared<CoolDownBehaviour>(JosephStalinAbilityDuration);
            spic::GameObjectUtil::LinkComponent(enemySuicideObject, abilityTimer);

            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::SuicideAbility, true, false, 1.0);
            spic::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);

            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for(auto& enemy : enemies) {
                auto attackBehaviour = enemy->GetComponent<game::AttackBehaviour>();
                if (attackBehaviour)
                {
                    attackBehaviour->TargetTag("enemy");
                }
            }

            scene->Contents().push_back(enemySuicideObject);
            _abilityActive = true;
        }
    }
}

void game::EnemySuicideAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::EnemySuicideAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::EnemySuicideAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

std::shared_ptr<game::CoolDownBehaviour>& game::EnemySuicideAbilityBehaviour::GetCoolDownBehaviour()
{
    return _coolDownBehaviour;
}
