#include "HelpScene.hpp"

#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Enums/Layer.hpp"

#include "Text.hpp"

#include <memory>

using namespace game;
using namespace spic;

HelpScene::HelpScene(const std::shared_ptr<spic::GameObject>& audio) : MenuScene("Help", true)
{
    auto creditsText = std::make_shared<Text>("Help Text", "text_help", Layer::HUD, 533, 400);
    creditsText->Transform().position = {366.5, 400};
    creditsText->Size(24);
    creditsText->TextColor(Color::white());
    creditsText->Content("Avans Wars WW2 heeft als doel het verdedigen van het eindpunt. Leg een pad van het beginpunt naar het eindpunt, plaats verschillende torens in je land en verras de vijanden met je geweldige verdediging! Start de waves en gebruik de speciale vaardigheid van je held om de vijanden uit je land te jagen! Als er geen vijandelijke troepen meer zijn heb je gewonnen, maar als er te veel vijanden bij je eindpunt zijn binnengedrongen veroveren ze je land en heb je verloren... Ben jij in staat om je land te verslaan?\n");

    auto controlsText = std::make_shared<Text>("Controls Text", "text_controls", Layer::HUD, 266.5, 400);
    controlsText->Transform().position = {866.25, 400};
    controlsText->Size(24);
    controlsText->TextColor(Color::white());
    controlsText->Content("Actie\n\nPauze/Hervatten\n\nHeld Beweging\nHeld Vaardigheid\nHeld Schieten\nHeld Schietrichting\n\nTegel Selectie\nTegel Interactie");

    auto controlsKeys = std::make_shared<Text>("Controls Text", "text_controls", Layer::HUD, 266.5, 400);
    controlsKeys->Transform().position = {1132.75, 400};
    controlsKeys->Size(24);
    controlsKeys->TextColor(Color::white());
    controlsKeys->Content("Toets\n\nESC\n\nWASD\nE\nLinkermuisknop\nMuis positie\n\nMuis positie\nLinkermuisknop");

    Contents().push_back(creditsText);
    Contents().push_back(controlsText);
    Contents().push_back(controlsKeys);
    Contents().push_back(audio);
}