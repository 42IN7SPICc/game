#ifndef SPIC_GAME_CHEATMANAGER_HPP
#define SPIC_GAME_CHEATMANAGER_HPP

#include "BehaviourScript.hpp"
#include "Collider.hpp"

class CheatManager : public spic::BehaviourScript {
public:
    void OnStart() override;

    void OnUpdate() override;

    void OnTriggerEnter2D(const spic::Collider& collider) override;

    void OnTriggerExit2D(const spic::Collider& collider) override;

    void OnTriggerStay2D(const spic::Collider& collider) override;
};


#endif
