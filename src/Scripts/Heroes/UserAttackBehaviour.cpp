#include "UserAttackBehaviour.hpp"

#include <Engine.hpp>
#include <Input.hpp>
#include <utility>
#include <stdexcept>

#include "../Common/BulletBehaviour.hpp"
#include "../../Factories/BulletFactory.hpp"
#include "../../Utils/PointUtil.hpp"
#include "../../Utils/GameObjectUtil.hpp"
#include "../../HeroConstants.hpp"
#include "../../Controllers/LevelController.hpp"

using namespace game;

UserAttackBehaviour::UserAttackBehaviour(int damage, double velocityMultiplier, std::shared_ptr<game::HealthBehaviour> healthBehaviour) : _damage(damage),
                                                                                                                                          _velocityMultiplier(velocityMultiplier),
                                                                                                                                          _healthBehaviour(std::move(healthBehaviour)),
                                                                                                                                          _coolDownBehaviour(std::make_shared<CoolDownBehaviour>(CoolDownBehaviour(HeroShootingCoolDown)))
{
}

void UserAttackBehaviour::OnStart()
{
    if (!_healthBehaviour)
    {
        throw std::runtime_error("A user attack behaviour requires a valid health behaviour.");
    }
    GameObjectUtil::LinkComponent(GameObject().lock(), _coolDownBehaviour);
}

void UserAttackBehaviour::OnUpdate()
{
    auto levelControllerGameObject = spic::GameObject::Find("LevelController");
    if (!levelControllerGameObject)
    {
        throw std::runtime_error("A user attack behaviour requires a level controller for level mode.");
    }

    auto levelController = levelControllerGameObject->GetComponent<game::LevelController>();

    if (_healthBehaviour->Health() <= 0 || !_coolDownBehaviour->CooledDown() || levelController->GetLevelMode() != LevelMode::WaveMode) return;

    if (spic::Input::GetMouseButton(spic::Input::MouseButton::LEFT))
    {
        auto parent = GameObject().lock();
        auto parentPosition = parent->AbsoluteTransform().position;
        auto mousePosition = spic::Input::MousePosition();

        auto force = PointUtil::CalculateDirectionalPoint(parentPosition, mousePosition, _velocityMultiplier);

        // Bullet game object
        auto bullet = BulletFactory::CreateBullet(BulletType::Normal, parentPosition, "enemy", force, HeroBulletRange, _damage);
        spic::Engine::Instance().PeekScene()->Contents().push_back(bullet);
        _coolDownBehaviour->CooledDown(false);
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
