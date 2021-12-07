#ifndef SPIC_GAME_CREDITSCENE_HPP
#define SPIC_GAME_CREDITSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    /**
     * @brief A scene that contains credits to the developers.
     */
    class CreditScene : public MenuScene
    {
        public:
            /**
             * @brief Constructs a new instance of a CreditScene.
             * @param audio the audio source to use as background music
             */
            explicit CreditScene(const std::shared_ptr<spic::GameObject>& audio);
    };
}

#endif //SPIC_GAME_CREDITSCENE_HPP
