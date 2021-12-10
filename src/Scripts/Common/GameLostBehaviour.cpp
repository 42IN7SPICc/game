#include <Debug.hpp>
#include <Engine.hpp>
#include "GameLostBehaviour.hpp"
#include "../../Scenes/GameOverScene.hpp"
#include "../../Enums/AudioClipName.hpp"
#include "../../Factories/AudioSourcePrefabFactory.hpp"
#include "Time.hpp"
#include "../../Utils/GameObjectUtil.hpp"

void game::GameLostBehaviour::OnStart()
{
    spic::Debug::Log("Started");
}

void game::GameLostBehaviour::OnUpdate()
{
    if (_lost) return;

    if (_levelData.MilitaryBaseHealth->Health() <= 0)
    {
        if (!_dying) {
            _dying = true;

            auto explosionAudioSource = game::AudioSourcePrefabFactory::CreateAudioSource(AudioClipName::Explosion, true, false, 1.0);
            GameObjectUtil::LinkComponent(GameObject().lock(), explosionAudioSource);
        }

        if (_lostForTime >= 3.0) {
            OnLevelFailed();
        }

        _lostForTime += spic::Time::DeltaTime() * spic::Time::TimeScale();
    }
}

void game::GameLostBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::GameLostBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

void game::GameLostBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
    spic::Debug::LogWarning("Not implemented");
}

game::GameLostBehaviour::GameLostBehaviour(game::LevelData& levelData) : _levelData(levelData), _lost(false), _dying(false), _lostForTime(0.0)
{

}

void game::GameLostBehaviour::OnLevelFailed()
{
    if (_lost) return;
    _lost = true;

    spic::Debug::Log("Level completed!");

    spic::Engine::Instance().PopScene();
    spic::Engine::Instance().PopScene();
    spic::Engine::Instance().PushScene(std::make_shared<game::GameOverScene>());
}

bool game::GameLostBehaviour::IsLevelFailed() const
{
    return _dying;
}
