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

AttackBehaviour::AttackBehaviour(const std::string& targetTag, game::BulletType bulletType, double fireRate, int range, int damage, double bulletSpeed, double damageRadius, bool followTarget, std::shared_ptr<spic::Animator> animator) : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(fireRate)),
                                                                                                                                                                                                                                            _targetTag(targetTag),
                                                                                                                                                                                                                                            _bulletType(bulletType),
                                                                                                                                                                                                                                            _range(range),
                                                                                                                                                                                                                                            _damage(damage),
                                                                                                                                                                                                                                            _bulletSpeed(bulletSpeed),
                                                                                                                                                                                                                                            _damageRadius(damageRadius),
                                                                                                                                                                                                                                            _followTarget(followTarget),
                                                                                                                                                                                                                                            _animator(animator)
{
}

void AttackBehaviour::OnStart()
{
    auto parent = GameObject().lock();
    GameObjectUtil::LinkComponent(parent, _coolDownBehaviour);
}

void AttackBehaviour::OnUpdate()
{
    if (!_coolDownBehaviour->CooledDown() && !_followTarget) return;

    auto absPosition = GameObject().lock()->AbsoluteTransform().position;

    std::map<double, spic::Point> targets{};
    for (const auto& target: spic::Engine::Instance().PeekScene()->Contents())
    {
        if (target->Tag() != _targetTag) continue;

        auto healthBehaviour = target->GetComponent<HealthBehaviour>();
        if (!healthBehaviour || healthBehaviour->Health() <= 0) continue;

        auto targetPosition = target->AbsoluteTransform().position;
        auto distance = PointUtil::Distance(absPosition, targetPosition);
        if (distance > _range) continue;

        targets.emplace(distance, targetPosition);
    }

    if (targets.empty()) return;

    auto target = *targets.begin();

    if (_followTarget)
    {
        GameObject().lock()->Transform().rotation = PointUtil::Degrees(absPosition, target.second);
    }

    if (!_coolDownBehaviour->CooledDown()) return;

    auto direction = PointUtil::CalculateDirectionalPoint(absPosition, target.second, _bulletSpeed);

    Shoot(direction, absPosition);

    _coolDownBehaviour->CooledDown(false);
}

void AttackBehaviour::Shoot(const spic::Point& direction, const spic::Point& position)
{
    auto bullet = BulletFactory::CreateBullet(_bulletType, position, _targetTag, direction, _range, _damage, _damageRadius);

    if (_animator)
    {
        _animator->Play(false);
    }

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

bool AttackBehaviour::FollowTarget() const
{
    return _followTarget;
}

void AttackBehaviour::FollowTarget(bool followTarget)
{
    _followTarget = followTarget;
}

std::shared_ptr<spic::Animator> AttackBehaviour::Animator() const
{
    return _animator;
}

void AttackBehaviour::Animator(std::shared_ptr<spic::Animator> animator)
{
    _animator = animator;
}
