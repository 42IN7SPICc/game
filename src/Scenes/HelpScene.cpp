#include "HelpScene.hpp"

#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Utils/Layer.hpp"

#include "Text.hpp"

#include <memory>

using namespace game;
using namespace spic;

HelpScene::HelpScene() : MenuScene("Help", true)
{
    auto creditsText = std::make_shared<Text>("Help Text", "text_help", Layer::HUD, 533, 400);
    creditsText->Transform().position = {366.5, 450};
    creditsText->Size(24);
    creditsText->TextColor(Color::white());
    creditsText->Content("Het spel word gespeeld door verschillende sopele rehgkjwer fthwerk ferewrhk erwehk errewhk ferthrewk");

    Contents().push_back(creditsText);
}