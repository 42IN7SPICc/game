#include "EnemyMedicBehaviour.hpp"

#include "../Common/HealthBehaviour.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../Utils/PointUtil.hpp"

#include "Engine.hpp"

#include <stdexcept>
#include <vector>

using namespace game;

EnemyMedicBehaviour::EnemyMedicBehaviour(int healPercentage, double healRange, int healCoolDown) : _healPercentage(healPercentage),
                                                                                                   _healRange(healRange),
                                                                                                   _healCoolDown(healCoolDown)
{
    if (_healRange <= 0)
    {
        throw std::runtime_error("The heal range has to be between bigger than 0.");
    }
    if (_healCoolDown <= 0)
    {
        throw std::runtime_error("The heal cool down has to be between bigger than 0.");
    }
    if (_healPercentage <= 0 || _healPercentage > 100)
    {
        throw std::runtime_error("The heal percentage has to be between 1 and 100.");
    }
}

void EnemyMedicBehaviour::OnStart()
{
    _healCoolDownBehaviour = std::make_shared<CoolDownBehaviour>(_healCoolDown);

    GameObjectUtil::LinkComponent(GameObject().lock(), _healCoolDownBehaviour);
}

void EnemyMedicBehaviour::OnUpdate()
{
    if (_healCoolDownBehaviour->CooledDown())
    {
        auto absPosition = GameObject().lock()->AbsoluteTransform().position;

        std::vector<std::shared_ptr<HealthBehaviour>> healthBehaviours{};
        for (const auto& target: spic::Engine::Instance().PeekScene()->Contents())
        {
            if (target->Tag() != "enemy") continue;

            auto healthBehaviour = target->GetComponent<HealthBehaviour>();
            if (!healthBehaviour || healthBehaviour->Health() <= 0) continue;

            auto distance = PointUtil::Distance(absPosition, target->AbsoluteTransform().position);
            if (distance > _healRange) continue;

            healthBehaviours.push_back(healthBehaviour);
        }

        for (const auto& healthBehaviour: healthBehaviours)
        {
            auto health = 100.0 / healthBehaviour->MaxHealth() * _healPercentage;
            healthBehaviour->Damage(-health);
        }

        _healCoolDownBehaviour->CooledDown(false);
    }
}

void EnemyMedicBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void EnemyMedicBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void EnemyMedicBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}
