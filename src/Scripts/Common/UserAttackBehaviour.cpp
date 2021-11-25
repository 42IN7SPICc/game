#include <Debug.hpp>
#include <Input.hpp>
#include <Sprite.hpp>
#include <CircleCollider.hpp>
#include <Engine.hpp>
#include "UserAttackBehaviour.hpp"
#include "DamageBehaviour.hpp"
#include "BulletBehaviour.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../Enums/Layer.hpp"
#include "../../Utils/PointUtil.hpp"
#include "../../Enums/SortingLayer.hpp"

void game::UserAttackBehaviour::OnStart()
{
    // No implementation required
}

void game::UserAttackBehaviour::OnUpdate()
{
    if (spic::Input::GetKeyDown(spic::Input::KeyCode::SPACE))
    {
        auto parent = GameObject().lock();
        auto parentPosition = parent->AbsoluteTransform().position;
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
        GameObjectUtil::LinkComponent(bullet, std::make_shared<BulletBehaviour>(force, 1000));
        GameObjectUtil::LinkComponent(bullet, std::make_shared<DamageBehaviour>(_damage));

        // Sprite
        GameObjectUtil::LinkComponent(bullet, std::make_shared<spic::Sprite>("resources/sprites/bullet.png", false, false, SortingLayer::Bullet, 0));
        spic::Engine::Instance().PeekScene()->Contents().push_back(bullet);
    }
}

void game::UserAttackBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::UserAttackBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::UserAttackBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

game::UserAttackBehaviour::UserAttackBehaviour(int damage, double velocityMultiplier, spic::Point origin) : _damage(damage),
                                                                                                            _velocityMultiplier(velocityMultiplier),
                                                                                                            _origin(std::make_unique<spic::Point>(origin))
{
}
