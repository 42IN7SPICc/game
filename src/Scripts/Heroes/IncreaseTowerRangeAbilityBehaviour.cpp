#include "IncreaseTowerRangeAbilityBehaviour.hpp"
#include "../../HeroConstants.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "../../Enums/Layer.hpp"
#include "../Common/AttackBehaviour.hpp"
#include "../../Utils/GameObjectUtil.hpp"

game::IncreaseTowerRangeAbilityBehaviour::IncreaseTowerRangeAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(FranklinDRooseveltTowerRangeAbilityCooldown))),
                                                                                 _abilityActivated(false)
{

}

void game::IncreaseTowerRangeAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _healthBehaviour = parent->GetComponent<game::HealthBehaviour>();
    game::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
}

void game::IncreaseTowerRangeAbilityBehaviour::OnUpdate()
{
    if(_healthBehaviour->Health() <= 0) return;

    if(_abilityActivated) {
        auto towerRangeObject = spic::GameObject::Find("towerRangeObject");
        if (towerRangeObject && towerRangeObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            towerRangeObject->Destroy(towerRangeObject);
            _abilityActivated = false;
            auto towers = spic::GameObject::FindGameObjectsWithTag("tower");
            for(auto& tower : towers) {
                auto attackBehaviour = tower->GetComponent<AttackBehaviour>();
                attackBehaviour->Range(attackBehaviour->Range() * 0.834);
            }
        }
        return;
    }

    if (spic::Input::GetKey(spic::Input::KeyCode::Q))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _abilityActivated = true;
            auto scene = spic::Engine::Instance().PeekScene();
            auto towerRangeObject = std::make_shared<spic::GameObject>("towerRangeObject", "towerRangeObject", Layer::Game);
            auto towerRangeCooldown = std::make_shared<CoolDownBehaviour>(10);
            GameObjectUtil::LinkComponent(towerRangeObject, towerRangeCooldown);

            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::ActivateAbility, true, false, 1.0);
            game::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);

            auto towers = spic::GameObject::FindGameObjectsWithTag("tower");
            for (auto& tower: towers)
            {
                auto attackBehaviour = tower->GetComponent<AttackBehaviour>();
                attackBehaviour->Range(attackBehaviour->Range() * 1.2);
            }
            scene->Contents().push_back(towerRangeObject);
            _coolDownBehaviour->CooledDown(false);
        }
    }
}

void game::IncreaseTowerRangeAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::IncreaseTowerRangeAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::IncreaseTowerRangeAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}
