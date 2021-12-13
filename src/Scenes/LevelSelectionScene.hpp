#ifndef SPIC_GAME_LEVELSELECTIONSCENE_HPP
#define SPIC_GAME_LEVELSELECTIONSCENE_HPP

#include "MenuScene.hpp"
#include "../Controllers/LevelSelectionController.hpp"

namespace game
{
    /**
     * @brief A scene that contains all the levels.
     */
    class LevelSelectionScene : public MenuScene
    {
        private:
            std::shared_ptr<game::LevelSelectionController> _levelSelectionController;
            std::vector<game::Level> _levels;

        public:
            /**
             * @brief Constructs a new instance of a LevelSelectionScene.
             * @param audio the audio source to use as background music
             */
            explicit LevelSelectionScene(const std::shared_ptr<spic::GameObject>& audio);

            /**
             * Load the level buttons into the scene
             * @param reload If the old buttons should be replaced with new ones
             */
            void LoadLevels(bool reload);
    };
}


#endif //SPIC_GAME_LEVELSELECTIONSCENE_HPP
