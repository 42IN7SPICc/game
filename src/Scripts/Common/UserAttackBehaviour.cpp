#include "UserAttackBehaviour.hpp"

#include <Engine.hpp>
#include <Input.hpp>

#include "BulletBehaviour.hpp"
#include "../../Factories/BulletFactory.hpp"
#include "../../Utils/PointUtil.hpp"

using namespace game;

UserAttackBehaviour::UserAttackBehaviour(int damage, double velocityMultiplier) : _damage(damage),
                                                                                  _velocityMultiplier(velocityMultiplier)
{
}

void UserAttackBehaviour::OnStart()
{
}

void UserAttackBehaviour::OnUpdate()
{
    if (spic::Input::GetKeyDown(spic::Input::KeyCode::SPACE))
    {
        auto parent = GameObject().lock();
        auto parentPosition = parent->AbsoluteTransform().position;
        auto mousePosition = spic::Input::MousePosition();

        auto force = PointUtil::CalculateDirectionalPoint(parentPosition, mousePosition, _velocityMultiplier);

        // Bullet game object
        auto bullet = BulletFactory::CreateBullet(BulletType::Normal, parentPosition, "enemy", force, 500, _damage);
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
