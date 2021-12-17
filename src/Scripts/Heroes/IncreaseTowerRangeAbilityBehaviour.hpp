#ifndef SPIC_GAME_INCREASETOWERRANGEABILITY_HPP
#define SPIC_GAME_INCREASETOWERRANGEABILITY_HPP

#include "AbilityBehaviour.hpp"

namespace game
{
    /**
     * @brief A script for handling the Tower Range ability for Franklin D Roosevelt
     */
    class IncreaseTowerRangeAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            bool _abilityActivated;

        public:
            /**
             * @brief Constructor for the IncreaseTowerRangeAbilityBehaviour
             */
            IncreaseTowerRangeAbilityBehaviour();

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;
    };
}


#endif
