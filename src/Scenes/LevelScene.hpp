#ifndef SPIC_GAME_LEVELSCENE_HPP
#define SPIC_GAME_LEVELSCENE_HPP

#include <map>
#include "Scene.hpp"
#include "Button.hpp"
#include "../Structs/LevelWithTiles.hpp"
#include "../Controllers/LevelSelectionController.hpp"

namespace game
{
    class LevelScene : public spic::Scene
    {
        public:
            explicit LevelScene(LevelWithTiles& level);
    };
}


#endif