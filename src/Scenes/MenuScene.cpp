#include "MenuScene.hpp"

#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Utils/Layer.hpp"

#include "Text.hpp"

#include <memory>
#include <stdexcept>

using namespace game;
using namespace spic;

const std::string TitleFont = "capture_it.otf";

MenuScene::MenuScene(const std::string& title, bool hasBackButton, BackgroundName backgroundName)
{
    if (title.empty())
    {
        throw std::runtime_error("The title of a menu cannot be empty.");
    }

    Contents().push_back(BackgroundPrefabFactory::CreateBackground(backgroundName));

    auto titleText = std::make_shared<Text>("Title Text", "text_title", Layer::HUD, 1166, 100, title, "resources/fonts/" + TitleFont, 82, Alignment::left, Color::white());
    titleText->Transform().position = {100, 100};

    Contents().push_back(titleText);

    if (hasBackButton)
    {
        Contents().push_back(ButtonPrefabFactory::CreateCloseButton({25, 25}));
    }
}