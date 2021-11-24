#ifndef SPIC_GAME_VICTORYSCENE_HPP
#define SPIC_GAME_VICTORYSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    class VictoryScene : public MenuScene
    {
        private:
            static std::shared_ptr<spic::GameObject> GenerateConfetti();
        public:
            VictoryScene();
    };
}

#endif //SPIC_GAME_VICTORYSCENE_HPP
