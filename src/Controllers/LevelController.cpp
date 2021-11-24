#include "LevelController.hpp"

using namespace game;

void LevelController::OnStart()
{

}

void LevelController::OnUpdate()
{
    //
}

void LevelController::OnTriggerEnter2D(const spic::Collider& collider)
{
    //
}

void LevelController::OnTriggerExit2D(const spic::Collider& collider)
{
    //
}

void LevelController::OnTriggerStay2D(const spic::Collider& collider)
{
    //
}

LevelController::LevelController(game::Level level, std::shared_ptr<game::HealthBehaviour> heroHealth, std::shared_ptr<game::HealthBehaviour> militaryBaseHealth, std::queue<game::WaveData> waves) : _level(std::move(level)),
                                                                                                                                                                                                      _levelData(game::LevelData{
                                                                                                                                                                                                              std::move(heroHealth),
                                                                                                                                                                                                              std::move(militaryBaseHealth),
                                                                                                                                                                                                              waves.size(), // Total waves
                                                                                                                                                                                                              500,
                                                                                                                                                                                                              std::move(waves)
                                                                                                                                                                                                      })
{
}

