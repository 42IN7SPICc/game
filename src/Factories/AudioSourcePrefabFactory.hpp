#ifndef SPIC_GAME_AUDIOSOURCEPREFABFACTORY_HPP
#define SPIC_GAME_AUDIOSOURCEPREFABFACTORY_HPP

#include <memory>
#include <GameObject.hpp>
#include <AudioSource.hpp>
#include "../Enums/AudioClipName.hpp"

namespace game
{
    /**
     * @brief Factory for audio sources.
     */
    class AudioSourcePrefabFactory
    {
        public:
            /**
             * @brief Create a GameObject containing a AudioSource component with given settings.
             * @param audioClipName The name of the audio clip.
             * @param playOnAwake Whether to play the audio clip on start.
             * @param looping Whether the audio clips is looping after finishing.
             * @param volume The volume the audio clip is played at.
             * @return The game object containing the audio source component.
             */
            static std::shared_ptr<spic::GameObject> CreateAudioObject(game::AudioClipName audioClipName, bool playOnAwake, bool looping, double volume);

            /**
             * @brief Create a AudioSource component with given settings.
             * @param audioClipName The name of the audio clip.
             * @param playOnAwake Whether to play the audio clip on start.
             * @param looping Whether the audio clips is looping after finishing.
             * @param volume The volume the audio clip is played at.
             * @return The audio source component.
             */
            static std::shared_ptr<spic::AudioSource> CreateAudioSource(game::AudioClipName audioClipName, bool playOnAwake, bool looping, double volume);
    };
}

#endif //SPIC_GAME_AUDIOSOURCEPREFABFACTORY_HPP
