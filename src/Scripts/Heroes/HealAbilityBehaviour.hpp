#ifndef SPIC_GAME_HEALABILITYBEHAVIOUR_HPP
#define SPIC_GAME_HEALABILITYBEHAVIOUR_HPP

#include <AudioSource.hpp>
#include "AbilityBehaviour.hpp"

namespace game
{
    /**
     * @brief A script to heal a hero when activated.
     */
    class HealAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            std::shared_ptr<spic::AudioSource> _audioSource;

        public:
            /**
             * @brief Constructs a new instance of a HealAbilityBehaviour.
             */
            HealAbilityBehaviour();

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;
    };
}

#endif
