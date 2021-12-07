#ifndef SPIC_GAME_HELPSCENE_HPP
#define SPIC_GAME_HELPSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    /**
     * @brief A scene that contains help for the user.
     */
    class HelpScene : public MenuScene
    {
        public:
            /**
             * @brief Constructs a new instance of a HelpScene.
             * @param audio the audio source to use as background music
             */
            explicit HelpScene(const std::shared_ptr<spic::GameObject>& audio);
    };
}

#endif //SPIC_GAME_HELPSCENE_HPP
