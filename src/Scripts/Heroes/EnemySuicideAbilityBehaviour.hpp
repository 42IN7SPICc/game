#ifndef SPIC_GAME_ENEMYSUICIDEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_ENEMYSUICIDEABILITYBEHAVIOUR_HPP

#include <AudioSource.hpp>
#include "AbilityBehaviour.hpp"

namespace game
{
    /**
     * @brief A script for handling the Enemy Suidcide ability for Joseph Stalin
     */
    class EnemySuicideAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            bool _abilityActive;
            std::shared_ptr<spic::AudioSource> _audioSource;

        public:
            /**
             * @brief Constructor for the EnemySuicideAbilityBehaviour
             */
            EnemySuicideAbilityBehaviour();

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
