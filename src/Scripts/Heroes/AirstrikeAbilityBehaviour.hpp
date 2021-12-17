#ifndef SPIC_GAME_AIRSTRIKEABILITYBEHAVIOUR_HPP
#define SPIC_GAME_AIRSTRIKEABILITYBEHAVIOUR_HPP

#include <AudioSource.hpp>
#include "BehaviourScript.hpp"
#include "../Common/CoolDownBehaviour.hpp"
#include "../Common/HealthBehaviour.hpp"

namespace game {
    /**
     * @brief A script for handling the airstrike ability for Franklin D Roosevelt
     */
    class AirstrikeAbilityBehaviour : public spic::BehaviourScript
    {
        private:
            std::shared_ptr<game::CoolDownBehaviour> _coolDownBehaviour;
            std::shared_ptr<game::HealthBehaviour> _healthBehaviour;
            std::shared_ptr<spic::AudioSource> _audioSource;
            bool _bombIsDropped;

        public:
            /**
             * @brief Constructs a new instance of a AirstrikeAbilityBehaviour.
             */
            AirstrikeAbilityBehaviour();

            /**
             * @brief Triggers when the scripts starts for the first time.
             */
            void OnStart() override;

            /**
             * @brief Triggers every frame when the script is active.
             */
            void OnUpdate() override;

            /**
             * @brief Triggers when the script collides with a collider.
             * @param collider The collider that collided.
             */
            void OnTriggerEnter2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers when the script stopped colliding with a collider.
             * @param collider The collider that stop colliding.
             */
            void OnTriggerExit2D(const spic::Collider& collider) override;

            /**
             * @brief Triggers while an collider is colliding with a collider.
             * @param collider The collider is colliding.
             */
            void OnTriggerStay2D(const spic::Collider& collider) override;

            /**
             * Getter for the _coolDownBehaviour field
             * @return the coolDownBehaviour
             */
            std::shared_ptr<game::CoolDownBehaviour>& GetCoolDownBehaviour();
    };
}


#endif
