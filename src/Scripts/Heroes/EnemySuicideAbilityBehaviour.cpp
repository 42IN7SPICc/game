#include "EnemySuicideAbilityBehaviour.hpp"
#include "../../Constants.hpp"
#include "Input.hpp"
#include "GameObject.hpp"
#include "../Common/AttackBehaviour.hpp"
#include "../../Enums/Layer.hpp"
#include "Engine.hpp"
#include "../../Utils/GameObjectUtil.hpp"

game::EnemySuicideAbilityBehaviour::EnemySuicideAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(JosephStalinAbilityCooldown))),
                                                                     _abilityActive(false)
{

}

void game::EnemySuicideAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    game::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
}

void game::EnemySuicideAbilityBehaviour::OnUpdate()
{
    if (_abilityActive)
    {
        auto enemySuicideObject = spic::GameObject::Find("enemySuicideObject");
        if (enemySuicideObject && enemySuicideObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            enemySuicideObject->Destroy(enemySuicideObject);
            _abilityActive = false;
            _coolDownBehaviour->CooledDown(true);
            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for(auto& enemy : enemies) {
                auto attackBehaviour = enemy->GetComponent<game::AttackBehaviour>();
                attackBehaviour->TargetTag("hero");
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
            GameObjectUtil::LinkComponent(enemySuicideObject, abilityTimer);

            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for(auto& enemy : enemies) {
                auto attackBehaviour = enemy->GetComponent<game::AttackBehaviour>();
                attackBehaviour->TargetTag("enemy");
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
