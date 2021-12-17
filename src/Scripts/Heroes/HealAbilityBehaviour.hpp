#ifndef SPIC_GAME_HEALABILITYBEHAVIOUR_HPP
#define SPIC_GAME_HEALABILITYBEHAVIOUR_HPP

#include "AbilityBehaviour.hpp"

namespace game
{
    /**
     * @brief A script to heal a hero when activated.
     */
    class HealAbilityBehaviour : public game::AbilityBehaviour
    {
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
