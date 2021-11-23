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
    creditsText->Content("Het spel wordt een Tower Defence game. Dit valt onder de categorie strategy games. In het geval van Avans Wars WW2 zal het een wave based strategy game zijn. Het doel van Tower Defence games is het voorkomen dat vijanden tot de eindlocatie kunnen komen door torens te plaatsen die schade aanbrengen aan de vijanden en deze te verslaan.");

    Contents().push_back(creditsText);
}