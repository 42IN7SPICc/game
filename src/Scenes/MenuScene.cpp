#include "MenuScene.hpp"

#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Utils/Layer.hpp"
#include "../Utils/Font.hpp"

#include "Text.hpp"

#include <memory>
#include <stdexcept>

using namespace game;
using namespace spic;

MenuScene::MenuScene(const std::string& title, bool hasBackButton, BackgroundName backgroundName)
{
    Contents().push_back(BackgroundPrefabFactory::CreateBackground(backgroundName));

    if (!title.empty())
    {
        auto titleText = std::make_shared<Text>("Title Text", "text_title", Layer::HUD, 1166, 100, title, Font::Title, 82, Alignment::left, Color::white());
        titleText->Transform().position = {683, 141};

        Contents().push_back(titleText);
    }

    if (hasBackButton)
    {
        Contents().push_back(ButtonPrefabFactory::CreateCloseButton());
    }
}