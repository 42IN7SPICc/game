#ifndef SPIC_GAME_MAINSCENE_HPP
#define SPIC_GAME_MAINSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    /**
     * @brief A scene that show the title of the game and some information.
     */
    class MainScene : public MenuScene
    {
        public:
            /**
             * @brief Constructs a new instance of a MainScene.
             */
            explicit MainScene(const std::shared_ptr<spic::GameObject>& audio);
    };
}

#endif //SPIC_GAME_MAINSCENE_HPP
