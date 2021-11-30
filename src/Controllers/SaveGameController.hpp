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

            void InitializeSaves();

            void Load(const std::string& saveGameName);

            void Save();

        private:
            std::map<std::string, PlayerData> _saves{};

    };
}


#endif //SPIC_GAME_SAVEGAMECONTROLLER_HPP
