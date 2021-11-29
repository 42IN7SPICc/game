#ifndef SPIC_GAME_AUDIOSOURCEPREFABFACTORY_HPP
#define SPIC_GAME_AUDIOSOURCEPREFABFACTORY_HPP

#include <memory>
#include <GameObject.hpp>
#include <AudioSource.hpp>
#include "../Enums/AudioClipName.hpp"

namespace game
{
    class AudioSourcePrefabFactory
    {
        public:
            static std::shared_ptr <spic::GameObject> CreateAudioObject(AudioClipName audioClipName, bool playOnAwake, bool looping, double volume);
            static std::shared_ptr <spic::AudioSource> CreateAudioSource(AudioClipName audioClipName, bool playOnAwake, bool looping, double volume);
    };
}

#endif //SPIC_GAME_AUDIOSOURCEPREFABFACTORY_HPP
