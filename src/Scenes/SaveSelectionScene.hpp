#ifndef SPIC_GAME_SAVESELECTIONSCENE_HPP
#define SPIC_GAME_SAVESELECTIONSCENE_HPP

#include "MenuScene.hpp"

#include <string>

namespace game
{
    class SaveSelectionScene : public MenuScene
    {
        public:
            SaveSelectionScene();

        private:
            void LoadSave(const std::string& saveName);
    };
}

#endif //SPIC_GAME_SAVESELECTIONSCENE_HPP
