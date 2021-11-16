#include "HealthBehaviour.hpp"
#include <Input.hpp>
#include <GameObject.hpp>
#include <Debug.hpp>

game::HealthBehaviour::HealthBehaviour(std::shared_ptr<spic::Animator> diedAnimator, int maxHealth) : _maxHealth(maxHealth),
                                                                                                      _health(maxHealth),
                                                                                                      _diedAnimator(std::move(diedAnimator))
{
}

int game::HealthBehaviour::Health() const
{
    return _health;
}

int game::HealthBehaviour::MaxHealth() const
{
    return _maxHealth;
}

void game::HealthBehaviour::Health(int health)
{
    _health = health;
}

void game::HealthBehaviour::Damage(int damage)
{
    if (_health <= 0) return;
    _health -= damage;
    if (_health <= 0)
        _diedAnimator->Play(false);
}

void game::HealthBehaviour::OnStart()
{
    spic::Debug::Log("HealthBehaviour Started");
}

void game::HealthBehaviour::OnUpdate()
{
    // Not implemented
}

void game::HealthBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::HealthBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::HealthBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}