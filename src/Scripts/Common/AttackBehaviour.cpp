#include "AttackBehaviour.hpp"

#include "Debug.hpp"

game::AttackBehaviour::AttackBehaviour(double fireRate, double range, double damage, bool multiTargeting, double bulletSpeed) : _fireRate(fireRate),
                                                                                                                                _range(range),
                                                                                                                                _damage(damage),
                                                                                                                                _multiTargeting(multiTargeting),
                                                                                                                                _bulletSpeed(bulletSpeed)
{
}

void game::AttackBehaviour::OnStart()
{
    spic::Debug::Log("AttackBehaviour Started");
}

void game::AttackBehaviour::OnUpdate()
{
    //spic::Debug::Log("AttackBehaviour Updated");
}

void game::AttackBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerEnter2D(collider);
}

void game::AttackBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerExit2D(collider);
}

void game::AttackBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    BehaviourScript::OnTriggerStay2D(collider);
}

double game::AttackBehaviour::FireRate() const
{
    return _fireRate;
}

void game::AttackBehaviour::FireRate(double fireRate)
{
    _fireRate = fireRate;
}

double game::AttackBehaviour::Range() const
{
    return _range;
}

void game::AttackBehaviour::Range(double range)
{
    _range = range;
}

double game::AttackBehaviour::Damage() const
{
    return _damage;
}

void game::AttackBehaviour::Damage(double damage)
{
    _damage = damage;
}

bool game::AttackBehaviour::MultiTargeting() const
{
    return _multiTargeting;
}

void game::AttackBehaviour::MultiTargeting(bool multiTargeting)
{
    _multiTargeting = multiTargeting;
}

double game::AttackBehaviour::BulletSpeed() const
{
    return _bulletSpeed;
}

void game::AttackBehaviour::BulletSpeed(double bulletSpeed)
{
    _bulletSpeed = bulletSpeed;
}
