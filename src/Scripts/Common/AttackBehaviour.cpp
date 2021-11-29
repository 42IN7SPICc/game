#include "AttackBehaviour.hpp"

#include "HealthBehaviour.hpp"
#include "../../Factories/BulletFactory.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../Utils/PointUtil.hpp"

#include "Engine.hpp"
#include "Sprite.hpp"

#include <algorithm>
#include <map>

using namespace game;

AttackBehaviour::AttackBehaviour(const std::string& targetTag, game::BulletType bulletType, double fireRate, int range, int damage, double bulletSpeed, double damageRadius) : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(fireRate)),
                                                                                                                                                                                              _targetTag(targetTag),
                                                                                                                                                                                              _bulletType(bulletType),
                                                                                                                                                                                              _range(range),
                                                                                                                                                                                              _damage(damage),
                                                                                                                                                                                              _bulletSpeed(bulletSpeed),
                                                                                                                                                                                              _damageRadius(damageRadius)
{
}

void AttackBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
}

void AttackBehaviour::OnUpdate()
{
    if (!_coolDownBehaviour->CooledDown()) return;

    auto absTransform = GameObject().lock()->AbsoluteTransform();

    std::map<double, std::shared_ptr<spic::GameObject>> targets{};
    for (const auto& target: spic::GameObject::FindGameObjectsWithTag(_targetTag))
    {
        auto healthBehaviour = target->GetComponent<HealthBehaviour>();
        if (!healthBehaviour || healthBehaviour->Health() <= 0) continue;

        auto distance = PointUtil::Distance(absTransform.position, target->AbsoluteTransform().position);
        if (distance > _range) continue;

        targets.emplace(distance, target);
    }

    if (targets.empty()) return;

    auto target = *targets.begin();
    auto direction = PointUtil::CalculateDirectionalPoint(absTransform.position, target.second->AbsoluteTransform().position, _bulletSpeed);

    Shoot(direction, absTransform.position);

    _coolDownBehaviour->CooledDown(false);
}

void AttackBehaviour::Shoot(const spic::Point& direction, const spic::Point& position)
{
    auto bullet = BulletFactory::CreateBullet(_bulletType, position, _targetTag, direction, _range, _damage, _damageRadius);

    spic::Engine::Instance().PeekScene()->Contents().push_back(bullet);
}

void AttackBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
//    BehaviourScript::OnTriggerEnter2D(collider);
}

void AttackBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
//    BehaviourScript::OnTriggerExit2D(collider);
}

void AttackBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
//    BehaviourScript::OnTriggerStay2D(collider);
}

double AttackBehaviour::FireRate() const
{
    return _coolDownBehaviour->MinCoolDown();
}

void AttackBehaviour::FireRate(double fireRate)
{
    _coolDownBehaviour->MinCoolDown(fireRate);
}

int AttackBehaviour::Range() const
{
    return _range;
}

void AttackBehaviour::Range(int range)
{
    _range = range;
}

int AttackBehaviour::Damage() const
{
    return _damage;
}

void AttackBehaviour::Damage(int damage)
{
    _damage = damage;
}

double AttackBehaviour::BulletSpeed() const
{
    return _bulletSpeed;
}

void AttackBehaviour::BulletSpeed(double bulletSpeed)
{
    _bulletSpeed = bulletSpeed;
}

const std::string& AttackBehaviour::TargetTag() const
{
    return _targetTag;
}

void AttackBehaviour::TargetTag(const std::string& targetTag)
{
    _targetTag = targetTag;
}

game::BulletType AttackBehaviour::BulletType() const
{
    return _bulletType;
}

void AttackBehaviour::BulletType(game::BulletType bulletType)
{
    _bulletType = bulletType;
}

double AttackBehaviour::DamageRadius() const
{
    return _damageRadius;
}

void AttackBehaviour::DamageRadius(double damageRadius)
{
    _damageRadius = damageRadius;
}
