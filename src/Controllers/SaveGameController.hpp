#ifndef SPIC_GAME_SAVEGAMECONTROLLER_HPP
#define SPIC_GAME_SAVEGAMECONTROLLER_HPP

#include "BehaviourScript.hpp"
#include "../Structs/PlayerData.hpp"

#include <string>
#include <map>

namespace game
{
    class SaveGameController : public spic::BehaviourScript
    {
        public:
            void OnStart() override;

            void OnUpdate() override;

            void OnTriggerEnter2D(const spic::Collider& collider) override;

            void OnTriggerExit2D(const spic::Collider& collider) override;

            void OnTriggerStay2D(const spic::Collider& collider) override;

            void InitializeSaves();

            void Load(const std::string& saveGameName);

            void Save();

        private:
            std::map<std::string, PlayerData> _saves{};

    };
}


#endif //SPIC_GAME_SAVEGAMECONTROLLER_HPP
