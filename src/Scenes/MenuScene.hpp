#ifndef SPIC_GAME_MENUSCENE_HPP
#define SPIC_GAME_MENUSCENE_HPP

#include "Scene.hpp"

#include "../Enums/BackgroundName.hpp"

#include <string>

namespace game
{
    /**
     * @brief A abstract scene to use for the scene that require menu functionality.
     */
    class MenuScene : public spic::Scene
    {
        public:
            /**
             * @brief Constructs a new instance of a CreditScene.
             * @param title The title of the scene.
             * @param hasBackButton Whether the scene has a back button.
             * @param backgroundName The name of the background for the scene.
             */
            MenuScene(const std::string& title, bool hasBackButton, BackgroundName backgroundName = BackgroundName::Menu);
    };
}

#endif //SPIC_GAME_MENUSCENE_HPP
