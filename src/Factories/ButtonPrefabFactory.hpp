#ifndef SPIC_GAME_BUTTONPREFABFACTORY_HPP
#define SPIC_GAME_BUTTONPREFABFACTORY_HPP

#include "Button.hpp"

#include <memory>
#include <string>

namespace game
{
    class ButtonPrefabFactory
    {
        public:
            static std::shared_ptr<spic::Button> CreateOutlineButton(const std::string& name, const std::string& tag, const std::string& text, const spic::Point position = {
                    0,
                    0
            });
    };
}

#endif //SPIC_GAME_BUTTONPREFABFACTORY_HPP
