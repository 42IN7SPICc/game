#ifndef SPIC_GAME_INCREASETOWERFIRERATEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_INCREASETOWERFIRERATEABILITYBEHAVIOUR_HPP

#include <AudioSource.hpp>
#include "AbilityBehaviour.hpp"

namespace game
{
    /**
     * @brief A script for handling the Tower Fire Rate Ability for Winston Churchill
     */
    class IncreaseTowerFireRateAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            std::shared_ptr<spic::AudioSource> _audioSource;
            bool _abilityActivated;

        public:
            /**
             * @brief Constructor for the IncreaseTowerFireRateAbilityBehaviour
             */
            IncreaseTowerFireRateAbilityBehaviour();

            /**
            * @brief Triggers when the scripts starts for the first time.
            */
            void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;
    };
}

#endif
