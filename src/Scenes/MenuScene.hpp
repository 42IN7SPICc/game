#ifndef SPIC_GAME_MENUSCENE_HPP
#define SPIC_GAME_MENUSCENE_HPP

#include "Scene.hpp"

#include "../Utils/BackgroundName.hpp"

#include <string>

namespace game
{
    class MenuScene : public spic::Scene
    {
        public:
            MenuScene(const std::string& title, bool hasBackButton, BackgroundName backgroundName = BackgroundName::Menu);
    };
}

#endif //SPIC_GAME_MENUSCENE_HPP
