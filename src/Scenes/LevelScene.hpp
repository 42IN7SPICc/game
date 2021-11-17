#ifndef SPIC_GAME_LEVELSCENE_HPP
#define SPIC_GAME_LEVELSCENE_HPP

#include "Scene.hpp"
#include "../Structs/Level.hpp"
#include "../Controllers/LevelController.hpp"

namespace game
{
    class LevelScene : public spic::Scene
    {
        public:
            LevelScene(const std::string& levelName, LevelController& levelController);
    };
}


#endif