#ifndef SPIC_GAME_WAVECONTROLLER_HPP
#define SPIC_GAME_WAVECONTROLLER_HPP

#include "BehaviourScript.hpp"

namespace game
{
    class WaveController : public spic::BehaviourScript
    {
            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;
    };
}

#endif