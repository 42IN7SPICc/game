#include "HealthBehaviour.hpp"
#include <Input.hpp>
#include <GameObject.hpp>
#include <Debug.hpp>
#include <Time.hpp>

game::HealthBehaviour::HealthBehaviour(std::shared_ptr<spic::Animator> diedAnimator, int maxHealth, double despawnTime) : _maxHealth(maxHealth),
                                                                                                                          _health(maxHealth),
                                                                                                                          _diedAnimator(std::move(diedAnimator)),
                                                                                                                          _despawnDuration(despawnTime),
                                                                                                                          _despawnTime(despawnTime),
                                                                                                                          _invincibility(false)
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
    if (health <= _maxHealth)
        _health = health;
}

void game::HealthBehaviour::Damage(int damage)
{
    if (_health > 0 && !_invincibility)
    {
        _health -= damage;

        if (_health <= 0)
        {
            _health = 0;
            if (_diedAnimator)
                _diedAnimator->Play(false);
        }
    }
}

void game::HealthBehaviour::OnStart()
{
    spic::Debug::Log("HealthBehaviour Started");
}

void game::HealthBehaviour::OnUpdate()
{
    if (_health <= 0 && _despawnTime != 0)
    {
        _despawnDuration -= spic::Time::DeltaTime() * spic::Time::TimeScale();

        if (_despawnDuration <= 0)
        {
            GameObject().lock()->Active(false);
        }
    }
}

void game::HealthBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    auto gameObject = GameObject().lock();
    if(gameObject->Tag() == "end_tile") {
        auto enemy = collider.GameObject().lock();
        if(enemy->Tag() == "enemy") {
            _health--;
            spic::GameObject::Destroy(enemy);
        }
    }
}

void game::HealthBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void game::HealthBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void game::HealthBehaviour::Invincibility(bool invincibility)
{
    _invincibility = invincibility;
}

bool game::HealthBehaviour::Invincibility() const
{
    return _invincibility;
}
