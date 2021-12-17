#ifndef SPIC_GAME_INCREASETOWERFIRERATEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_INCREASETOWERFIRERATEABILITYBEHAVIOUR_HPP

#include "AbilityBehaviour.hpp"

namespace game {
    /**
     * @brief A script for handling the Tower Fire Rate Ability for Winston Churchill
     */
    class IncreaseTowerFireRateAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            bool _abilityActivated;

        public:
            /**
             * @brief Constructor for the IncreaseTowerFireRateAbilityBehaviour
             */
            IncreaseTowerFireRateAbilityBehaviour();

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;
    };
}


#endif
