#include "CheatManager.hpp"
#include "Input.hpp"
#include <iostream>

using namespace spic;
using namespace game;

void UnlimitedMoney() {
    std::cout << "Fired Unlimited Money Cheat" << std::endl;
}

void Invincibility() {
    std::cout << "Fired Invincibility Cheat" << std::endl;
}

void Butcher() {
    std::cout << "Fired Butcher Cheat" << std::endl;
}

void Victory() {
    std::cout << "Fired Victory Cheat" << std::endl;
}

void SkipWave() {
    std::cout << "Fired Skip Wave Cheat" << std::endl;
}

void NoCoolDown() {
    std::cout << "Fired No Cooldown Cheat" << std::endl;
}

void UnlockLevels() {
    std::cout << "Fired Unlock Levels Cheat" << std::endl;
}

void UnlimitedPath() {
    std::cout << "Fired Unlimited Path Cheat" << std::endl;
}

void StrongPath() {
    std::cout << "Fired Strong Path Cheat" << std::endl;
}

void ExpBoost() {
    std::cout << "Fired Exp Boost Cheat" << std::endl;
}

void CheatManager::OnStart() {
    _cheats[Input::KeyCode::U] = []() { return UnlimitedMoney(); };
    _cheats[Input::KeyCode::I] = []() { return Invincibility(); };
    _cheats[Input::KeyCode::B] = []() { return Butcher(); };
    _cheats[Input::KeyCode::V] = []() { return Victory(); };
    _cheats[Input::KeyCode::S] = []() { return SkipWave(); };
    _cheats[Input::KeyCode::N] = []() { return NoCoolDown(); };
    _cheats[Input::KeyCode::A] = []() { return UnlockLevels(); };
    _cheats[Input::KeyCode::P] = []() { return UnlimitedPath(); };
    _cheats[Input::KeyCode::Q] = []() { return StrongPath(); };
    _cheats[Input::KeyCode::E] = []() { return ExpBoost(); };
}

void CheatManager::OnUpdate() {
    for(const auto& cheat : _cheats) {
        if(Input::GetKey(Input::KeyCode::LEFT_CONTROL) &&
            Input::GetKey(Input::KeyCode::LEFT_SHIFT) &&
            Input::GetKeyDown(cheat.first)) {
            cheat.second();
            break;
        }
    }
}

void CheatManager::OnTriggerEnter2D(const Collider &collider) {
    std::cout << "CheatManager trigger entered" << std::endl;
}

void CheatManager::OnTriggerExit2D(const Collider &collider) {
    std::cout << "CheatManager trigger existed" << std::endl;
}

void CheatManager::OnTriggerStay2D(const Collider &collider) {
    std::cout << "CheatManager trigger stay" << std::endl;
}
