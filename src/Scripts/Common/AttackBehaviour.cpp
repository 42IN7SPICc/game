#include "AttackBehaviour.hpp"

#include "BulletBehaviour.hpp"
#include "DamageBehaviour.hpp"
#include "HealthBehaviour.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Enums/SortingLayer.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../Utils/PointUtil.hpp"

#include "Debug.hpp"
#include "Engine.hpp"
#include "Sprite.hpp"

#include <algorithm>
#include <map>
#include <CircleCollider.hpp>

using namespace game;

AttackBehaviour::AttackBehaviour(const std::string& targetTag, double fireRate, double range, double damage, bool multiTargeting, double bulletSpeed) : _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(fireRate)),
                                                                                                                                                        _targetTag(targetTag),
                                                                                                                                                        _range(range),
                                                                                                                                                        _damage(damage),
                                                                                                                                                        _multiTargeting(multiTargeting),
                                                                                                                                                        _bulletSpeed(bulletSpeed)
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

    auto direction = PointUtil::CalculateDirectionalPoint(absTransform.position, target.second->AbsoluteTransform().position);
    direction.x *= _bulletSpeed;
    direction.y *= _bulletSpeed;

    Shoot(direction);

    _coolDownBehaviour->CooledDown(false);
}

void AttackBehaviour::Shoot(const spic::Point& direction)
{
    auto bullet = std::make_shared<spic::GameObject>("bullet", "enemies", Layer::Game);
    bullet->Transform().position = GameObject().lock()->AbsoluteTransform().position;

    // Collider
    auto collider = std::make_shared<spic::CircleCollider>(8);
    collider->IsTrigger(true);
    GameObjectUtil::LinkComponent(bullet, collider);

    // Behaviour scripts
    GameObjectUtil::LinkComponent(bullet, std::make_shared<BulletBehaviour>(direction, _range));
    GameObjectUtil::LinkComponent(bullet, std::make_shared<DamageBehaviour>(_damage));

    // Sprite
    GameObjectUtil::LinkComponent(bullet, std::make_shared<spic::Sprite>("resources/sprites/bullet.png", false, false, SortingLayer::Bullet, 0));
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

double AttackBehaviour::Range() const
{
    return _range;
}

void AttackBehaviour::Range(double range)
{
    _range = range;
}

double AttackBehaviour::Damage() const
{
    return _damage;
}

void AttackBehaviour::Damage(double damage)
{
    _damage = damage;
}

bool AttackBehaviour::MultiTargeting() const
{
    return _multiTargeting;
}

void AttackBehaviour::MultiTargeting(bool multiTargeting)
{
    _multiTargeting = multiTargeting;
}

double AttackBehaviour::BulletSpeed() const
{
    return _bulletSpeed;
}

void AttackBehaviour::BulletSpeed(double bulletSpeed)
{
    _bulletSpeed = bulletSpeed;
}
