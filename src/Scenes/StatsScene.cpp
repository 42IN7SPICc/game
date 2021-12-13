#include "StatsScene.hpp"

#include "../Constants.hpp"
#include "../Enums/Layer.hpp"
#include "../Structs/PlayerData.hpp"

#include "Text.hpp"

#include "sstream"

using namespace game;

const double FrameHeightOffset = 350;
const double FrameHeight = ScreenHeight - FrameHeightOffset;
const double FramePosY = FrameHeight * 0.5 + FrameHeightOffset - 100;

const double FrameWidthOffset = 100;
const int FrameItems = 2;
const double FrameItemWidth = ScreenWidth * (1.0 / FrameItems) - FrameWidthOffset;
const double FrameItemPosXOffset = FrameItemWidth * 0.5;

StatsScene::StatsScene(const std::shared_ptr<spic::GameObject>& audio) : MenuScene("Voortgang", 1, BackgroundName::Menu)
{
    auto textLeftObject = std::make_shared<spic::Text>("", "text_stats_left", Layer::HUD, FrameItemWidth, FrameHeight);
    textLeftObject->Transform().position = {ScreenCenterWidth - FrameItemPosXOffset, FramePosY};
    textLeftObject->TextColor(spic::Color::white());
    textLeftObject->TextAlignment(spic::Alignment::center);
    textLeftObject->Size(24);
    textLeftObject->Content("Levels voltooid\nTotaal aantal waves gespeeld\n\nTotaal aantal torens geplaatst\nMeeste toren geplaatst in een level\n\nTotaal aantal vijandend vermoord\nHeld dood gegaan\nHeld vaakst dood gegaan in een level");

    const auto& playerData = PlayerData::Instance();
    std::stringstream playerStats{};
    playerStats << playerData.LevelsCompleted << "\n";
    playerStats << playerData.WavesPlayed << "\n\n";
    playerStats << playerData.TowersPlaced << "\n";
    playerStats << playerData.MostTowersPlaced << "\n\n";
    playerStats << playerData.KillCount << "\n";
    playerStats << playerData.HeroDeaths << " keer\n";
    playerStats << playerData.MostHeroDeaths << " keer";

    auto textRightObject = std::make_shared<spic::Text>("", "text_stats_right", Layer::HUD, FrameItemWidth, FrameHeight);
    textRightObject->Transform().position = {ScreenCenterWidth + FrameItemPosXOffset, FramePosY};
    textRightObject->TextColor(spic::Color::white());
    textRightObject->TextAlignment(spic::Alignment::center);
    textRightObject->Size(24);
    textRightObject->Content(playerStats.str());

    Contents().push_back(audio);
    Contents().push_back(textLeftObject);
    Contents().push_back(textRightObject);
}
