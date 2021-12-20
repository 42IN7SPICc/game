#include "EnemySuicideAbilityBehaviour.hpp"
#include "Input.hpp"
#include "GameObject.hpp"
#include "Engine.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../Common/AttackBehaviour.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"
#include "../../Enums/Layer.hpp"
#include "../../HeroConstants.hpp"

game::EnemySuicideAbilityBehaviour::EnemySuicideAbilityBehaviour() : AbilityBehaviour(JosephStalinAbilityCooldown),
                                                                     _abilityActive(false)
{

}

void game::EnemySuicideAbilityBehaviour::OnStart()
{
    AbilityBehaviour::OnStart();
    auto parent = GameObject().lock();
    _audioSource = AudioSourcePrefabFactory::CreateAudioSource(game::AudioClipName::SuicideAbility, false, false, 1.0);
    spic::GameObjectUtil::LinkComponent(parent, _audioSource);
}


void game::EnemySuicideAbilityBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0) return;

    if (_abilityActive)
    {
        auto enemySuicideObject = spic::GameObject::Find("enemySuicideObject");
        if (enemySuicideObject && enemySuicideObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            enemySuicideObject->Destroy(enemySuicideObject);
            _abilityActive = false;
            _coolDownBehaviour->CooledDown(false);
            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for (auto& enemy: enemies)
            {
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

            _audioSource->Play(false);

            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for (auto& enemy: enemies)
            {
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