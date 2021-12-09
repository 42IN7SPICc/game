#include "EnemyInvisibleBehaviour.hpp"

#include "../../Utils/GameObjectUtil.hpp"

#include "Color.hpp"

#include <stdexcept>

const spic::Color ActiveColor = spic::Color(1, 1, 1, 0.5);
const spic::Color InactiveColor = spic::Color::transparent();

game::EnemyInvisibleBehaviour::EnemyInvisibleBehaviour(int effectTime, int coolDownTime) : _effectTime(effectTime),
                                                                                           _coolDownTime(coolDownTime + effectTime)
{
}

void game::EnemyInvisibleBehaviour::OnStart()
{
    auto parent = GameObject().lock();

    _healthBehaviour = parent->GetComponent<HealthBehaviour>();
    if (!_healthBehaviour)
    {
        throw std::runtime_error("The EnemyInvisibleBehaviour requires a HealthBehaviour");
    }

    _sprite = parent->GetComponent<spic::Sprite>();

    _effectCoolDown = std::make_shared<CoolDownBehaviour>(_coolDownTime);
    GameObjectUtil::LinkComponent(parent, _effectCoolDown);

    _effectTimer = std::make_shared<CoolDownBehaviour>(_effectTime);
    _effectTimer->CooledDown(true);
    GameObjectUtil::LinkComponent(parent, _effectTimer);
}

void game::EnemyInvisibleBehaviour::OnUpdate()
{
    if (_effectCoolDown->CooledDown())
    {
        _effectCoolDown->CooledDown(false);
        _effectTimer->CooledDown(false);
    }

    bool isActive = !_effectTimer->CooledDown() && _healthBehaviour->Health() > 0;
    _healthBehaviour->Invincibility(isActive);
    if (_sprite) _sprite->Color(isActive ? ActiveColor : InactiveColor);
}

void game::EnemyInvisibleBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void game::EnemyInvisibleBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void game::EnemyInvisibleBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}
