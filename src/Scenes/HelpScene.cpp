#include "HelpScene.hpp"

#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Enums/Layer.hpp"

#include "Text.hpp"

#include <memory>

using namespace game;
using namespace spic;

HelpScene::HelpScene() : MenuScene("Help", true)
{
    auto creditsText = std::make_shared<Text>("Help Text", "text_help", Layer::HUD, 533, 400);
    creditsText->Transform().position = {366.5, 400};
    creditsText->Size(24);
    creditsText->TextColor(Color::white());
    creditsText->Content("Het spel wordt een Tower Defence game. Dit valt onder de categorie strategy games. In het geval van Avans Wars WW2 zal het een wave based strategy game zijn. Het doel van Tower Defence games is het voorkomen dat vijanden tot de eindlocatie kunnen komen door torens te plaatsen die schade aanbrengen aan de vijanden en deze te verslaan.\n\n\n\n");

    auto controlsText = std::make_shared<Text>("Controls Text", "text_controls", Layer::HUD, 266.5, 400);
    controlsText->Transform().position = {866.25, 400};
    controlsText->Size(24);
    controlsText->TextColor(Color::white());
    controlsText->Content("Actie\n\nPauze/Hervatten\n\nHeld Beweging\nHeld Vaardigheid\nHeld Schieten\nHeld Schietrichting\n\nTegel Selectie\nTegel Interactie");

    auto controlsKeys = std::make_shared<Text>("Controls Text", "text_controls", Layer::HUD, 266.5, 400);
    controlsKeys->Transform().position = {1132.75, 400};
    controlsKeys->Size(24);
    controlsKeys->TextColor(Color::white());
    controlsKeys->Content("Toets\n\nESC\n\nWASD\nE\nSpatiebalk\nMuis positie\n\nMuis positie\nLinkermuisknop");

    Contents().push_back(creditsText);
    Contents().push_back(controlsText);
    Contents().push_back(controlsKeys);
}