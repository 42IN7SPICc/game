#include "UserAttackBehaviour.hpp"

#include <Engine.hpp>
#include <Input.hpp>
#include <utility>
#include <stdexcept>

#include "../Common/BulletBehaviour.hpp"
#include "../../Factories/BulletFactory.hpp"
#include "../../Utils/PointUtil.hpp"
#include "../../Constants.hpp"

using namespace game;

UserAttackBehaviour::UserAttackBehaviour(int damage, double velocityMultiplier, std::shared_ptr<game::HealthBehaviour> healthBehaviour) : _damage(damage),
                                                                                                                                          _velocityMultiplier(velocityMultiplier),
                                                                                                                                          _healthBehaviour(std::move(healthBehaviour))
{
}

void UserAttackBehaviour::OnStart()
{
    if (!_healthBehaviour)
    {
        throw std::runtime_error("A user attack behaviour requires a valid health behaviour.");
    }
}

void UserAttackBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0) return;

    if (spic::Input::GetKeyDown(spic::Input::KeyCode::SPACE))
    {
        auto parent = GameObject().lock();
        auto parentPosition = parent->AbsoluteTransform().position;
        auto mousePosition = spic::Input::MousePosition();

        auto force = PointUtil::CalculateDirectionalPoint(parentPosition, mousePosition, _velocityMultiplier);

        // Bullet game object
        auto bullet = BulletFactory::CreateBullet(BulletType::Normal, parentPosition, "enemy", force, HeroBulletRange, _damage);
        spic::Engine::Instance().PeekScene()->Contents().push_back(bullet);
    }
}

void UserAttackBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void UserAttackBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void UserAttackBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}
