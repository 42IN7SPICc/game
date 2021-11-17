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
#include "../../Utils/PointUtil.hpp"

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

        // Origin offsets
        parentPosition.x += _origin->x;
        parentPosition.y += _origin->y;

        auto force = PointUtil::CalculateDirectionalPoint(parentPosition, mousePosition, _velocityMultiplier);

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

UserAttackBehaviour::UserAttackBehaviour(int damage, double velocityMultiplier, spic::Point origin) : _damage(damage),
                                                                                                      _velocityMultiplier(velocityMultiplier),
                                                                                                      _origin(std::make_unique<spic::Point>(origin))
{
}
