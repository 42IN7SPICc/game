#ifndef SPIC_GAME_VICTORYSCENE_HPP
#define SPIC_GAME_VICTORYSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    /**
     * @brief A scene that contains a victory screen.
     */
    class VictoryScene : public MenuScene
    {
        private:
            static std::shared_ptr<spic::GameObject> GenerateConfetti();

        public:
            /**
             * @brief Constructs a new instance of a VictoryScene.
             */
            VictoryScene();
    };
}

#endif //SPIC_GAME_VICTORYSCENE_HPP
