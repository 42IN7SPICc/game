#ifndef SPIC_GAME_CONSTANTS_HPP
#define SPIC_GAME_CONSTANTS_HPP

#include "Color.hpp"

// Primary window
const int ScreenWidth = 1366; // Width of the screen
const int ScreenHeight = 768; // Height of the screen

//Game HUD and Level
const int HudWidth = 250; // Width of the HUD inside a level
const int VerticalTileCount = 25; // Amount of vertical tiles
const int HorizontalTileCount = 25; // Amount of horizontal tiles
const double TileSize = 128; // Size of a single TileSprite
const double TileButtonScale = 0.5; // Size of tile select button inside of the HUD
const double TowerButtonScale = 0.1; // Size of tile select button inside of the HUD
const double TowerSpriteSize = 550; // Size of tower select button inside of the HUD
const double TileMapScale = static_cast<double>(ScreenHeight) / VerticalTileCount / TileSize; // Scale of the entire 25 x 25 map
const int MapY = static_cast<int>(TileSize * TileMapScale / 2.0); // Starting y location of the map
const int MapX = static_cast<int>((ScreenWidth - HudWidth) / 2.0 - (TileSize * TileMapScale * (HorizontalTileCount - 1)) / 2.0 - MapY); // Starting x location of the map
const int EndTowerHealth = 10;
const int StartingLevelBalance = 1000;

//Confetti
const int AmountOfConfetti = 100;
const int ConfettiYRangeMin = -ScreenHeight - 200;
const int ConfettiYRangeMax = 0;
const int ConfettiXRangeMin = 16;
const int ConfettiXRangeMax = ScreenWidth - 16;
const double ConfettiMinSize = 0.03;
const double ConfettiMaxSize = 0.05;
const double ConfettiMinGravity = 0.7;
const double ConfettiMaxGravity = 1.4;

//Health Bar
const double HealthBarChunks = 10;

#endif
