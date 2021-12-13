#ifndef SPIC_GAME_STATSSCENE_HPP
#define SPIC_GAME_STATSSCENE_HPP

#include "MenuScene.hpp"

namespace game
{
    class StatsScene : public MenuScene
    {
        public:
            StatsScene(const std::shared_ptr<spic::GameObject>& audio);
    };
}

#endif //SPIC_GAME_STATSSCENE_HPP
