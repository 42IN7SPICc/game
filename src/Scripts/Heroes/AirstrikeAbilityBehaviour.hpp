#ifndef SPIC_GAME_AIRSTRIKEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_AIRSTRIKEABILITYBEHAVIOUR_HPP

#include <AudioSource.hpp>
#include "AbilityBehaviour.hpp"

namespace game {
    /**
     * @brief A script for handling the airstrike ability for Franklin D Roosevelt
     */
    class AirstrikeAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            std::shared_ptr<spic::AudioSource> _audioSource;
            bool _bombIsDropped;

        public:
            /**
             * @brief Constructs a new instance of a AirstrikeAbilityBehaviour.
             */
            AirstrikeAbilityBehaviour();

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;
    };
}


#endif
