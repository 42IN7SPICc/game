#ifndef SPIC_GAME_HUDDATA_HPP
#define SPIC_GAME_HUDDATA_HPP

#include <memory>
#include <map>
#include "Button.hpp"

namespace game
{
    struct HudData
    {
        HudData()
        {
            SelectedButton = nullptr;
            ButtonTileAmounts = {};
            ButtonTowerCosts = {};
        }

        std::shared_ptr<spic::Button> SelectedButton;
        std::map<std::shared_ptr<spic::Button>, int> ButtonTileAmounts;
        std::map<std::shared_ptr<spic::Button>, int> ButtonTowerCosts;
    };
}

#endif
