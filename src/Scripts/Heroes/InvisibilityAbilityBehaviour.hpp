#ifndef SPIC_GAME_INVISIBILITYABILITYBEHAVIOUR_HPP
#define SPIC_GAME_INVISIBILITYABILITYBEHAVIOUR_HPP

#include "AbilityBehaviour.hpp"

namespace game {
    /**
     * @brief A script for handling the invisibility ability for Bernard IJzerdraat
     */
    class InvisibilityAbilityBehaviour : public game::AbilityBehaviour
    {
        private:
            std::shared_ptr<spic::Sprite> _sprite;
            bool _abilityActive;

        public:
            /**
             * @brief Constructor for the InvisibilityBehaviour
             */
            InvisibilityAbilityBehaviour();

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
