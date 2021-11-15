#ifndef SPIC_GAME_CHEATMANAGER_HPP
#define SPIC_GAME_CHEATMANAGER_HPP

#include "BehaviourScript.hpp"
#include "Collider.hpp"
#include "Input.hpp"
#include <map>
#include <functional>

using namespace spic;

class CheatManager : public spic::BehaviourScript {
private:
    std::map<Input::KeyCode, std::function<void()>> _cheats {};

public:
    void OnStart() override;

    void OnUpdate() override;

    void OnTriggerEnter2D(const Collider& collider) override;

    void OnTriggerExit2D(const Collider& collider) override;

    void OnTriggerStay2D(const Collider& collider) override;
};


#endif
