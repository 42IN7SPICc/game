#include "BulletFactory.hpp"

#include "CircleCollider.hpp"
#include "Engine.hpp"
#include "Sprite.hpp"

#include "../Enums/Layer.hpp"
#include "../Enums/SortingLayer.hpp"
#include "../Scripts/Common/BulletBehaviour.hpp"
#include "../Utils/GameObjectUtil.hpp"

#include <stdexcept>

using namespace game;

std::shared_ptr<spic::GameObject> BulletFactory::CreateBullet(BulletType bulletType, const spic::Point& position, const std::string& targetTag, const spic::Point& direction, int range, int damage, double bombRadius)
{
    auto bullet = std::make_shared<spic::GameObject>("bullet", "bullet", Layer::Game);
    bullet->Transform().position = position;

    // Collider
    auto collider = std::make_shared<spic::CircleCollider>(8);
    collider->IsTrigger(true);
    GameObjectUtil::LinkComponent(bullet, collider);

    // Behaviour scripts
    GameObjectUtil::LinkComponent(bullet, std::make_shared<BulletBehaviour>(bulletType, direction, range));
    GameObjectUtil::LinkComponent(bullet, std::make_shared<DamageBehaviour>(damage, targetTag, (bulletType == BulletType::Bomb ? bombRadius : 0)));

    // Sprite
    GameObjectUtil::LinkComponent(bullet, std::make_shared<spic::Sprite>(GetBulletSprite(bulletType), false, false, SortingLayer::Bullet, 0));
    spic::Engine::Instance().PeekScene()->Contents().push_back(bullet);

    return bullet;
}

std::string BulletFactory::GetBulletSprite(BulletType bulletType)
{
    switch (bulletType)
    {
        case BulletType::Normal:
            return "resources/sprites/bullet.png";
        case BulletType::Bomb:
            return "resources/sprites/bullet.png";
    }

    throw std::runtime_error("The given bullet does not have a linked sprite");
}
