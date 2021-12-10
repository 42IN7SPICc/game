#include "CreditScene.hpp"

#include "../Factories/ButtonPrefabFactory.hpp"
#include "../Factories/BackgroundPrefabFactory.hpp"
#include "../Enums/Layer.hpp"

#include "Text.hpp"
#include "../Constants.hpp"

#include <memory>

using namespace game;
using namespace spic;

CreditScene::CreditScene(const std::shared_ptr<spic::GameObject>& audio) : MenuScene("Credits", true)
{
    auto creditsText = std::make_shared<Text>("Credits Text", "text_credits", Layer::HUD, 1166, 400);
    creditsText->Transform().position = {ScreenWidth / 2.0, 450};
    creditsText->Size(24);
    creditsText->TextColor(Color::white());
    creditsText->Content("Avans Wars: WW2 is gemaakt door:\n\nDaan Hendriks\nMax van de Vossenberg\nSander Jochems\nTommy Hosewol");

    Contents().push_back(creditsText);
    Contents().push_back(audio);
}
