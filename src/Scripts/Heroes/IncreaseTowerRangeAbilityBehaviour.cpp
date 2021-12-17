#include "IncreaseTowerRangeAbilityBehaviour.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "../Common/AttackBehaviour.hpp"
#include "../../Enums/Layer.hpp"
#include "../../HeroConstants.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"

game::IncreaseTowerRangeAbilityBehaviour::IncreaseTowerRangeAbilityBehaviour() : AbilityBehaviour(FranklinDRooseveltTowerRangeAbilityCooldown),
                                                                                 _abilityActivated(false)
{

}

void game::IncreaseTowerRangeAbilityBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0) return;

    if (_abilityActivated)
    {
        auto towerRangeObject = spic::GameObject::Find("towerRangeObject");
        if (towerRangeObject && towerRangeObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            towerRangeObject->Destroy(towerRangeObject);
            _abilityActivated = false;
            auto towers = spic::GameObject::FindGameObjectsWithTag("tower");
            for (auto& tower: towers)
            {
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
            spic::GameObjectUtil::LinkComponent(towerRangeObject, towerRangeCooldown);

            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::ActivateAbility, true, false, 1.0);
            spic::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);

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
