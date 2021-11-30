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
    /**
     * @brief A scene that contains a level to play.
     */
    class LevelScene : public spic::Scene
    {
        public:
            /**
             * @brief Constructs a new instance of a LevelScene.
             * @param level The level with the tiles.
             */
            explicit LevelScene(LevelWithTiles& level);
    };
}


#endif