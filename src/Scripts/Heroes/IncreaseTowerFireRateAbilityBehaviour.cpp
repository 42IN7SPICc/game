#include "IncreaseTowerFireRateAbilityBehaviour.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "GameObject.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "../Common/AttackBehaviour.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"
#include "../../HeroConstants.hpp"

game::IncreaseTowerFireRateAbilityBehaviour::IncreaseTowerFireRateAbilityBehaviour() : AbilityBehaviour(WinstonChurchillTowerFireRateAbilityCooldown),
                                                                                       _abilityActivated(false)
{

}

void game::IncreaseTowerFireRateAbilityBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0) return;

    if (_abilityActivated)
    {
        auto towerFireRateObject = spic::GameObject::Find("towerFireRateObject");
        if (towerFireRateObject && towerFireRateObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            towerFireRateObject->Destroy(towerFireRateObject);
            _abilityActivated = false;
            auto towers = spic::GameObject::FindGameObjectsWithTag("tower");
            for (auto& tower: towers)
            {
                auto attackBehaviour = tower->GetComponent<AttackBehaviour>();
                attackBehaviour->FireRate(attackBehaviour->FireRate() * 0.834);
            }
        }
        return;
    }

    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _abilityActivated = true;
            auto scene = spic::Engine::Instance().PeekScene();
            auto towerFireRateObject = std::make_shared<spic::GameObject>("towerFireRateObject", "towerFireRateObject", Layer::Game);
            auto towerFireRateCooldown = std::make_shared<CoolDownBehaviour>(10);
            spic::GameObjectUtil::LinkComponent(towerFireRateObject, towerFireRateCooldown);

            auto soundEffect = AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName::ActivateAbility, true, false, 1.0);
            spic::GameObjectUtil::LinkChild(GameObject().lock(), soundEffect);

            auto towers = spic::GameObject::FindGameObjectsWithTag("tower");
            for (auto& tower: towers)
            {
                auto attackBehaviour = tower->GetComponent<AttackBehaviour>();
                attackBehaviour->FireRate(attackBehaviour->FireRate() * 1.2);
            }
            scene->Contents().push_back(towerFireRateObject);
            _coolDownBehaviour->CooledDown(false);
        }
    }
}
