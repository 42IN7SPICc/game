#include "AirstrikeAbilityBehaviour.hpp"
#include "../../Constants.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "Animator.hpp"
#include "GameObject.hpp"
#include "Time.hpp"
#include "../../Enums/SortingLayer.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../Utils/AnimatorUtil.hpp"
#include "../Common/HealthBehaviour.hpp"

game::AirstrikeAbilityBehaviour::AirstrikeAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(FranklinDRooseveltAirstrikeAbilityCooldown))),
                                                               _bombIsDropped(false)
{

}

void game::AirstrikeAbilityBehaviour::OnStart()
{
    //
}

void game::AirstrikeAbilityBehaviour::OnUpdate()
{
    if(_bombIsDropped) {
        auto bombObject = spic::GameObject::Find("airstrikeBomb");
        bombObject->Transform().scale *= 0.96 * ( 1 - spic::Time::DeltaTime());
        if (bombObject && bombObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            bombObject->Destroy(bombObject);
            _bombIsDropped = false;
            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for(auto& enemy : enemies) {
                auto health = enemy->GetComponent<HealthBehaviour>();
                health->Damage(FranklinDRooseveltAirstrikeAbilityDamage);
            }
        }
        return;
    }

    if (spic::Input::GetKeyDown(spic::Input::KeyCode::E))
    {
        _bombIsDropped = true;
        auto scene = spic::Engine::Instance().PeekScene();
        auto bombObject = std::make_shared<spic::GameObject>("airstrikeBomb", "airstrikeBomb", Layer::Game);
        bombObject->Transform().position = {ScreenWidth / 2 - 90, ScreenHeight / 2};
        bombObject->Transform().scale = 1;

        std::vector<std::shared_ptr<spic::Sprite>> airstrikeSprites = AnimatorUtil::CreateSpriteVector(8, "resources/sprites/abilities/airstrike/airstrike_", SortingLayer::Hero);
        auto airstrikeAnimator = std::make_shared<spic::Animator>(static_cast<int>(airstrikeSprites.size()), airstrikeSprites);
        GameObjectUtil::LinkComponent(bombObject, airstrikeAnimator);

        airstrikeAnimator->Play(true);

        auto defaultSprite = std::make_shared<spic::Sprite>(airstrikeSprites[0]->Texture(), false, false, SortingLayer::Hero, 0);
        GameObjectUtil::LinkComponent(bombObject, defaultSprite);

        auto bombFallTimer = std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(1.5));
        GameObjectUtil::LinkComponent(bombObject, bombFallTimer);

        scene->Contents().push_back(bombObject);
    }
}

void game::AirstrikeAbilityBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void game::AirstrikeAbilityBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void game::AirstrikeAbilityBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}
