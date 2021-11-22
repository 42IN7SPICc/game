#include "CreditScene.hpp"

#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Utils/Layer.hpp"

#include "Text.hpp"

#include <memory>

using namespace game;
using namespace spic;

CreditScene::CreditScene()
{
    auto background = BackgroundPrefabFactory::CreateBackground(BackgroundName::Menu);

    auto titleText = std::make_shared<Text>("Title Text", "text_title", Layer::HUD, 1720, 100, "Credits", "resources/fonts/capture_it.otf", 82, Alignment::left, Color::white());
    titleText->Transform().position = {100, 100};

    auto creditsText = std::make_shared<Text>("Title Text", "text_title", Layer::HUD, 1720, 400);
    creditsText->Transform().position = {100, 250};
    creditsText->Size(24);
    creditsText->TextColor(Color::white());
    creditsText->Content("Avans Wars: WW2 has been created by\n\nDaan Hendriks\nMax van de Vossenberg\nSander Jochems\nTommy Hosewol");

    auto closeButton = ButtonPrefabFactory::CreateCloseButton({25, 25});

    Contents().push_back(background);
    Contents().push_back(closeButton);
    Contents().push_back(titleText);
    Contents().push_back(creditsText);
}
