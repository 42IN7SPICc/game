#ifndef SPIC_GAME_BUTTONPREFABFACTORY_HPP
#define SPIC_GAME_BUTTONPREFABFACTORY_HPP

#include "Button.hpp"

#include <memory>
#include <string>

namespace game
{
    /**
     * @brief Factory for buttons.
     */
    class ButtonPrefabFactory
    {
        public:
            /**
             * @brief Create a button with an outline that the user can click on.
             * @param name The name of the button
             * @param tag The tag of the button
             * @param text The text inside the button
             * @param invert_color Whether to invert the button (false = white; true = black)
             * @return The button object.
             */
            static std::shared_ptr<spic::Button> CreateOutlineButton(const std::string& name, const std::string& tag, const std::string& text, bool invert_color = false);

            /**
             * @brief Create a button with an outline that the user can click on.
             * @param name The name of the button
             * @param tag The tag of the button
             * @param text The text inside the button
             * @return The button object.
             */
            static std::shared_ptr<spic::Button> CreateSquareOutlineButton(const std::string& name, const std::string& tag, const std::string& text);

            /**
             * @brief Create a button with a script that closes the current scene.
             * @param position The position of the button.
             * @return The button object.
             */
            static std::shared_ptr<spic::Button> CreateCloseButton(const spic::Point& position = {49, 49});

            /**
             * @brief Create a button for the hero switching
             * @param position The screen position for the button
             * @param callback The onlick action for the button
             * @return The button object
             */
            static std::shared_ptr<spic::Button> CreateSwitchHeroButton(const spic::Point& position, std::function<void()> callback);
    };
}

#endif //SPIC_GAME_BUTTONPREFABFACTORY_HPP
