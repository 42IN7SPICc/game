#ifndef SPIC_GAME_LEVELSELECTIONSCENE_HPP
#define SPIC_GAME_LEVELSELECTIONSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    /**
     * @brief A scene that contains all the levels.
     */
    class LevelSelectionScene : public MenuScene
    {
        public:
            /**
             * @brief Constructs a new instance of a LevelSelectionScene.
             * @param audio the audio source to use as background music
             */
            explicit LevelSelectionScene(const std::shared_ptr<spic::GameObject>& audio);
    };
}


#endif //SPIC_GAME_LEVELSELECTIONSCENE_HPP
