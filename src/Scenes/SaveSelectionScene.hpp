#ifndef SPIC_GAME_SAVESELECTIONSCENE_HPP
#define SPIC_GAME_SAVESELECTIONSCENE_HPP

#include "MenuScene.hpp"

#include <string>

namespace game
{
    /**
     * @brief Scene for selection which save the user wants to play.
     */
    class SaveSelectionScene : public MenuScene
    {
        public:
            /**
             * @brief Constructs a new instance of a Save Selection Scene.
             * @param audio the audio source to use as background music
             */
            explicit SaveSelectionScene(const std::shared_ptr<spic::GameObject>& audio);

        private:
            std::shared_ptr<spic::GameObject> _mainMenuAudio;

            /**
             * @brief Loads a save game file by name and switches to main menu scene
             * @param saveName name of the save file to load
             */
            void LoadSave(const std::string& saveName);
            [[nodiscard]] bool SaveExists(const std::string& saveName) const;
    };
}

#endif //SPIC_GAME_SAVESELECTIONSCENE_HPP
