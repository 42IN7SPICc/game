#include "EnemyMovementBehaviour.hpp"

#include "../../Constants.hpp"
#include "../../Controllers/LevelController.hpp"
#include "Utils/StringUtil.hpp"
#include "Utils/PointUtil.hpp"
#include "Utils/GameObjectUtil.hpp"

#include "GameObject.hpp"
#include "Time.hpp"

#include <stdexcept>

using namespace game;

EnemyMovementBehaviour::EnemyMovementBehaviour(std::shared_ptr<spic::Animator> walkingAnimator, float velocity) : _walkingAnimator(walkingAnimator),
                                                                                                                  _velocity(velocity),
                                                                                                                  _boostSpeedMultiplier(1)
{
}

bool CanWalk(TileType tileType)
{
    return tileType == TileType::Street || tileType == TileType::Grass || tileType == TileType::Sand || tileType == TileType::Bridge;
}

void EnemyMovementBehaviour::OnStart()
{
    auto parent = GameObject().lock();

    _healthBehaviour = parent->GetComponent<HealthBehaviour>();
    if (!_healthBehaviour)
    {
        throw std::runtime_error("No HealthBehaviour found on the enemy.");
    }
    _rigidBody = parent->GetComponent<spic::RigidBody>();
    if (!_rigidBody)
    {
        throw std::runtime_error("No RigidBody found on the enemy.");
    }
    _sprite = parent->GetComponent<spic::Sprite>();
    if (!_sprite)
    {
        throw std::runtime_error("No Sprite found on the enemy.");
    }

    auto gameObject = spic::GameObject::Find("LevelController");
    if (gameObject)
    {
        auto levelController = gameObject->GetComponent<game::LevelController>();
        if (_graph.empty()) _graph = levelController->GetGraph();
        if (_path.empty()) _path = levelController->GetPath();
    }

    _boostCoolDownBehaviour = std::make_shared<CoolDownBehaviour>(0);
    spic::GameObjectUtil::LinkComponent(parent, _boostCoolDownBehaviour);
}

void EnemyMovementBehaviour::Boost(int time, double multiplier)
{
    _boostCoolDownBehaviour->MinCoolDown(time);
    _boostCoolDownBehaviour->CooledDown(false);

    _boostSpeedMultiplier = multiplier;
}

void EnemyMovementBehaviour::OnUpdate()
{
    if (_healthBehaviour->Health() <= 0)
    {
        _walkingAnimator->Stop();
        return;
    }

    auto parent = GameObject().lock();

    auto enemyPosition = parent->AbsoluteTransform().position;
    double scaledTileSize = TileSize * TileMapScale;
    int tileXLocation = static_cast<int>(((enemyPosition.x - MapX) + (scaledTileSize / 2)) / scaledTileSize);
    int tileYLocation = static_cast<int>(((enemyPosition.y - MapY) + (scaledTileSize / 2)) / scaledTileSize);

    auto tileLocation = _graph[std::to_string(tileXLocation) + "-" + std::to_string(tileYLocation)];

    if (_path.empty()) return;

    double speedMultiplier = 1.0;
    if (tileLocation.TileType == TileType::Grass)
    {
        speedMultiplier = 0.75;
    }
    else if (tileLocation.TileType == TileType::Sand)
    {
        speedMultiplier = 0.5;
    }

    speedMultiplier *= _velocity * spic::Time::DeltaTime() * spic::Time::TimeScale();

    if (!_boostCoolDownBehaviour->CooledDown())
    {
        speedMultiplier *= _boostSpeedMultiplier;
    }

    auto toLocation = _graph[_path.front()];

    double distance;
    auto force = spic::PointUtil::CalculateDirectionalPoint(enemyPosition, toLocation.TileObject->AbsoluteTransform().position, speedMultiplier, distance);

    _rigidBody->AddForce(force);

    if (distance <= 2)
    {
        _path.pop();
    }

    _walkingAnimator->Play(true);
    _sprite->FlipX(force.x < 0);
    parent->Transform().rotation = 0;
}

void EnemyMovementBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void EnemyMovementBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void EnemyMovementBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

const std::queue<std::string>& EnemyMovementBehaviour::Path() const
{
    return _path;
}

void EnemyMovementBehaviour::Path(const std::queue<std::string>& path)
{
    _path = path;
}
