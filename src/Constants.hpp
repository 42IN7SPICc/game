#ifndef SPIC_GAME_CONSTANTS_HPP
#define SPIC_GAME_CONSTANTS_HPP

#include "Color.hpp"

//Game HUD and Level
const double TileSize = 128; // Size of a single TileSprite
const double TileButtonScale = 0.5; // Size of tile select button inside of the HUD
const double TowerButtonScale = 0.1; // Size of tile select button inside of the HUD
const double TowerSpriteSize = 550; // Size of tower select button inside of the HUD
const double TileMapScale = 0.246; // Scale of the entire 25 x 25 map
const int MapX = TileSize / 2 + 155; // Starting x location of the map
const int MapY = 32 / 2; // Starting y location of the map
const int ScreenWidth = 1366; // Width of the screen
const int ScreenHeight = 786; // Height of the screen
const int HudWidth = 250; // Width of the HUD inside a level
const int EndTowerHealth = 10;

//Enemy
const int DefaultEnemyKillBalance = 50; // The money you get after killing an enemy

//Confetti
const int AmountOfConfetti = 100;
const int ConfettiYRangeMin = -800;
const int ConfettiYRangeMax = 0;
const int ConfettiXRangeMin = 16;
const int ConfettiXRangeMax = 1350;
const double ConfettiMinSize = 0.03;
const double ConfettiMaxSize = 0.05;
const double ConfettiMinGravity = 0.7;
const double ConfettiMaxGravity = 1.4;

//Health Bar
const double HealthBarChunks = 10;

#endif
