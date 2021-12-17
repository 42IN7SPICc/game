#include "AirstrikeAbilityBehaviour.hpp"
#include "../../HeroConstants.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "Animator.hpp"
#include "GameObject.hpp"
#include "Time.hpp"
#include "../../Enums/SortingLayer.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Enums/AudioClipName.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "Utils/AnimatorUtil.hpp"
#include "../Common/HealthBehaviour.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"
#include "../../Constants.hpp"

game::AirstrikeAbilityBehaviour::AirstrikeAbilityBehaviour() : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(FranklinDRooseveltAirstrikeAbilityCooldown))),
                                                               _bombIsDropped(false)
{
}

void game::AirstrikeAbilityBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    _healthBehaviour = parent->GetComponent<game::HealthBehaviour>();
    spic::GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
    _audioSource = AudioSourcePrefabFactory::CreateAudioSource(game::AudioClipName::NukeAbility, true, false, 1.0);
    spic::GameObjectUtil::LinkComponent(parent, _audioSource);
}

void game::AirstrikeAbilityBehaviour::OnUpdate()
{
    if (_bombIsDropped)
    {
        auto bombObject = spic::GameObject::Find("airstrikeBomb");
        bombObject->Transform().scale *= 0.96 * (1 - spic::Time::DeltaTime() * spic::Time::TimeScale());
        if (bombObject && bombObject->GetComponent<CoolDownBehaviour>()->CooledDown())
        {
            _audioSource->Play(false);
            bombObject->Destroy(bombObject);
            _bombIsDropped = false;
            auto enemies = spic::GameObject::FindGameObjectsWithTag("enemy");
            for (auto& enemy: enemies)
            {
                auto health = enemy->GetComponent<HealthBehaviour>();
                health->Damage(FranklinDRooseveltAirstrikeAbilityDamage);
            }
        }
        return;
    }

    if (_healthBehaviour->Health() <= 0) return;

    if (spic::Input::GetKey(spic::Input::KeyCode::E))
    {
        if (_coolDownBehaviour->CooledDown())
        {
            _bombIsDropped = true;
            auto scene = spic::Engine::Instance().PeekScene();
            auto bombObject = std::make_shared<spic::GameObject>("airstrikeBomb", "airstrikeBomb", Layer::Game);
            bombObject->Transform().position = {ScreenWidth / 2.0 - 90, ScreenHeight / 2.0};
            bombObject->Transform().scale = 1;

            std::vector<std::shared_ptr<spic::Sprite>> airstrikeSprites = spic::AnimatorUtil::CreateSpriteVector(8, "resources/sprites/abilities/airstrike/airstrike_", SortingLayer::Hero);
            auto airstrikeAnimator = std::make_shared<spic::Animator>(static_cast<int>(airstrikeSprites.size()), airstrikeSprites);
            spic::GameObjectUtil::LinkComponent(bombObject, airstrikeAnimator);

            airstrikeAnimator->Play(true);

            auto defaultSprite = std::make_shared<spic::Sprite>(airstrikeSprites[0]->Texture(), false, false, SortingLayer::Hero, 0);
            spic::GameObjectUtil::LinkComponent(bombObject, defaultSprite);

            auto bombFallTimer = std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(1.5));
            spic::GameObjectUtil::LinkComponent(bombObject, bombFallTimer);

            scene->Contents().push_back(bombObject);
            _coolDownBehaviour->CooledDown(false);
        }
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

std::shared_ptr<game::CoolDownBehaviour>& game::AirstrikeAbilityBehaviour::GetCoolDownBehaviour()
{
    return _coolDownBehaviour;
}
