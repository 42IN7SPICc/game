#include <Debug.hpp>
#include <Input.hpp>
#include <Sprite.hpp>
#include <CircleCollider.hpp>
#include <Engine.hpp>
#include "UserAttackBehaviour.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "DamageBehaviour.hpp"
#include "BulletBehaviour.hpp"
#include "../../Utils/Layer.hpp"

using namespace game;

void UserAttackBehaviour::OnStart()
{
    _parent = GameObject().lock();
}

void UserAttackBehaviour::OnUpdate()
{
    if (spic::Input::GetKeyDown(spic::Input::KeyCode::SPACE))
    {
        auto parentPosition = _parent->AbsoluteTransform().position;
        auto mousePosition = spic::Input::MousePosition();

        auto posDiff = spic::Point{mousePosition.x - parentPosition.x, mousePosition.y - parentPosition.y};
        double distance = sqrt(posDiff.x * posDiff.x + posDiff.y * posDiff.y);
        spic::Point force{posDiff.x / distance * _velocityMultiplier, posDiff.y / distance * _velocityMultiplier};

        // Bullet game object
        auto bullet = std::make_shared<spic::GameObject>("bullet", "enemies", Layer::Game);
        bullet->Transform().position.x = parentPosition.x;
        bullet->Transform().position.y = parentPosition.y;

        // Collider
        auto collider = std::make_shared<spic::CircleCollider>(8);
        collider->IsTrigger(true);
        GameObjectUtil::LinkComponent(bullet, collider);

        // Behaviour scripts
        GameObjectUtil::LinkComponent(bullet, std::make_shared<BulletBehaviour>(force));
        GameObjectUtil::LinkComponent(bullet, std::make_shared<DamageBehaviour>(_damage));

        // Sprite
        GameObjectUtil::LinkComponent(bullet, std::make_shared<spic::Sprite>("resources/sprites/bullet.png", false, false, 0, 0));
        spic::Engine::Instance().PeekScene()->Contents().push_back(bullet);
    }
}

void UserAttackBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void UserAttackBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void UserAttackBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

UserAttackBehaviour::UserAttackBehaviour(int damage, double velocityMultiplier) : _damage(damage),
                                                                                  _velocityMultiplier(velocityMultiplier)
{
}
