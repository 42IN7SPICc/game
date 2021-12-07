#include "EnemySpeedBoostBehaviour.hpp"

#include "EnemyMovementBehaviour.hpp"
#include "../../Utils/PointUtil.hpp"
#include "../../Utils/GameObjectUtil.hpp"

#include "Engine.hpp"
#include "GameObject.hpp"

#include <stdexcept>

game::EnemySpeedBoostBehaviour::EnemySpeedBoostBehaviour(int boostCoolDown, double speedBoost, int boostTime, double boostRange) : _boostCoolDown(boostCoolDown),
                                                                                                                                   _speedBoost(speedBoost),
                                                                                                                                   _boostTime(boostTime),
                                                                                                                                   _boostRange(boostRange)
{
    if (_boostCoolDown <= 0)
    {
        throw std::runtime_error("The boost cool down has to be between bigger than 0.");
    }
    if (_speedBoost <= 0)
    {
        throw std::runtime_error("The speed boost has to be between bigger than 0.");
    }
}

void game::EnemySpeedBoostBehaviour::OnStart()
{
    _coolDownBehaviour = std::make_shared<CoolDownBehaviour>(_boostCoolDown);

    GameObjectUtil::LinkComponent(GameObject().lock(), _coolDownBehaviour);
}

void game::EnemySpeedBoostBehaviour::OnUpdate()
{
    if (_coolDownBehaviour->CooledDown())
    {
        auto parent = GameObject().lock();
        auto absPosition = parent->AbsoluteTransform().position;

        std::vector<std::shared_ptr<EnemyMovementBehaviour>> movementBehaviours{};
        for (const auto& target: spic::Engine::Instance().PeekScene()->Contents())
        {
            if (target == parent) continue;

            if (target->Tag() != "enemy") continue;

            auto distance = PointUtil::Distance(absPosition, target->AbsoluteTransform().position);
            if (distance > _boostRange) continue;

            movementBehaviours.push_back(target->GetComponent<EnemyMovementBehaviour>());
        }

        for (const auto& movementBehaviour: movementBehaviours)
        {
            movementBehaviour->Boost(_boostTime, _speedBoost);
        }

        _coolDownBehaviour->CooledDown(false);
    }
}

void game::EnemySpeedBoostBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void game::EnemySpeedBoostBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void game::EnemySpeedBoostBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}
