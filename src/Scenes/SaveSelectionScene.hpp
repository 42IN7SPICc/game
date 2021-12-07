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
             */
            SaveSelectionScene();

        private:
            void LoadSave(const std::string& saveName);
    };
}

#endif //SPIC_GAME_SAVESELECTIONSCENE_HPP
