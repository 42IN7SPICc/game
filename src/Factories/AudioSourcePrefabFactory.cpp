#include "AudioSourcePrefabFactory.hpp"
#include "../Enums/Layer.hpp"
#include "Utils/GameObjectUtil.hpp"
#include "Utils/RandomUtil.hpp"
#include <stdexcept>

std::shared_ptr<spic::AudioSource> game::AudioSourcePrefabFactory::CreateAudioSource(game::AudioClipName audioClipName, bool playOnAwake, bool looping, double volume)
{
    std::string audioSrc{};
    switch (audioClipName)
    {
        case AudioClipName::MainMenu:
            audioSrc = "main_menu.wav";
            break;
        case AudioClipName::Victory:
            audioSrc = "victory.wav";
            break;
        case AudioClipName::GameOver:
            audioSrc = "game_over.wav";
            break;
        case AudioClipName::Game:
            audioSrc = "game.wav";
            break;
        case AudioClipName::Explosion:
            audioSrc = "explosion.wav";
            break;
        case AudioClipName::NukeAbility:
            audioSrc = "abilities/nuke.wav";
            break;
        case AudioClipName::ActivateAbility:
            audioSrc = "abilities/activate.wav";
            break;
        case AudioClipName::HealAbility:
            audioSrc = "abilities/heal.wav";
            break;
        case AudioClipName::SuicideAbility:
            audioSrc = "abilities/russian.wav";
            break;
        case AudioClipName::SceneSwap:
            audioSrc = "woosh.wav";
            break;
        default:
            throw std::runtime_error("Audio clip has not been defined.");
    }

    auto audioSource = std::make_shared<spic::AudioSource>("resources/audio/" + audioSrc, playOnAwake, looping, volume);
    return audioSource;
}

std::shared_ptr<spic::GameObject> game::AudioSourcePrefabFactory::CreateAudioObject(game::AudioClipName audioClipName, bool playOnAwake, bool looping, double volume)
{
    auto audioObject = std::make_shared<spic::GameObject>("audioSource_" + spic::RandomUtil::NextString(32), "audio", Layer::Background);
    spic::GameObjectUtil::LinkComponent(audioObject, CreateAudioSource(audioClipName, playOnAwake, looping, volume));
    return audioObject;
}
