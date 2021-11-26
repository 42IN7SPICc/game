#ifndef SPIC_GAME_LEVELSCENE_HPP
#define SPIC_GAME_LEVELSCENE_HPP

#include "Scene.hpp"
#include "Button.hpp"

#include "../Structs/LevelWithTiles.hpp"
#include "../Controllers/LevelSelectionController.hpp"
#include "../Scripts/Common/HealthBehaviour.hpp"

#include <map>

namespace game
{
    class LevelScene : public spic::Scene
    {
        public:
            explicit LevelScene(LevelWithTiles& level);
    };
}


#endif