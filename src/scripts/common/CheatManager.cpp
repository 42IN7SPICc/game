#include "CheatManager.hpp"
#include "Input.hpp"
#include <iostream>

using namespace spic;

void UnlimitedMoney() {
    std::cout << "Fired Unlimited Money Cheat" std::endl;
}

void Invincibility() {
    std::cout << "Fired Invincibility Cheat" std::endl;
}

void Butcher() {
    std::cout << "Fired Butcher Cheat" std::endl;
}

void Victory() {
    std::cout << "Fired Victory Cheat" std::endl;
}

void SkipWave() {
    std::cout << "Fired Skip Wave Cheat" std::endl;
}

void NoCooldown() {
    std::cout << "Fired No Cooldown Cheat" std::endl;
}

void UnlockLevels() {
    std::cout << "Fired Unlock Levels Cheat" std::endl;
}

void UnlimitedPath() {
    std::cout << "Fired Unlimited Path Cheat" std::endl;
}

void StrongPath() {
    std::cout << "Fired Strong Path Cheat" std::endl;
}

void ExpBoost() {
    std::cout << "Fired Exp Boost Cheat" std::endl;
}

void CheatManager::OnStart() {
    _cheatMap[Input::KeyCode::U] = UnlimitedMoney();
    _cheatMap[Input::KeyCode::I] = Invincibility();
    _cheatMap[Input::KeyCode::B] = Butcher();
    _cheatMap[Input::KeyCode::V] = Victory();
    _cheatMap[Input::KeyCode::S] = SkipWave();
    _cheatMap[Input::KeyCode::N] = NoCooldown();
    _cheatMap[Input::KeyCode::A] = UnlockLevels();
    _cheatMap[Input::KeyCode::P] = UnlimitedPath();
    _cheatMap[Input::KeyCode::Q] = StrongPath();
    _cheatMap[Input::KeyCode::E] = ExpBoost();
}

void CheatManager::OnUpdate() {
    std::cout << "CheatManager updated" << std::endl;
    for(const auto& cheat : cheatMap) {
        if(Input::GetKeyDown(Input::KeyCode::LEFT_CONTROL) &&
           Input::GetKeyDown(Input::KeyCode::LEFT_SHIFT) &&
           Input::GetKeyDown(cheat.first)) {
            cheat.second();
        }
    }
}

void CheatManager::OnTriggerEnter2D(const spic::Collider &collider) {
    std::cout << "CheatManager trigger entered" << std::endl;
}

void CheatManager::OnTriggerExit2D(const spic::Collider &collider) {
    std::cout << "CheatManager trigger existed" << std::endl;
}

void CheatManager::OnTriggerStay2D(const spic::Collider &collider) {
    std::cout << "CheatManager trigger stay" << std::endl;
}
