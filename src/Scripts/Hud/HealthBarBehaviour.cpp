#include "HealthBarBehaviour.hpp"

#include "GameObject.hpp"

#include "../../Constants.hpp"

#include <cmath>
#include <stdexcept>

game::HealthBarBehaviour::HealthBarBehaviour(std::shared_ptr<HealthBehaviour> healthBehaviour) : _healthBehaviour(healthBehaviour),
                                                                                                 _prevHealth(-1)
{
    if (!_healthBehaviour)
    {
        throw std::runtime_error("The HealthBarBehaviour requires an active HealthBehaviour.");
    }
}

void game::HealthBarBehaviour::OnStart()
{
    auto parent = GameObject().lock();

    if (parent->Children().size() != HealthBarChunks)
    {
        throw std::runtime_error("The health bar must contain 10 children.");
    }
}

void game::HealthBarBehaviour::OnUpdate()
{
    auto health = _healthBehaviour->Health();
    if (health != _prevHealth)
    {
        auto parent = GameObject().lock();

        int barsNeeded = std::round(HealthBarChunks / _healthBehaviour->MaxHealth() * health);
        for (int i = 0; i < HealthBarChunks; ++i)
        {
            parent->Children()[i]->Active(barsNeeded > i);
        }
    }

    _prevHealth = health;
}

void game::HealthBarBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void game::HealthBarBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void game::HealthBarBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}
