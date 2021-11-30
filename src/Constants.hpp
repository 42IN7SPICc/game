#ifndef SPIC_GAME_CONSTANTS_HPP
#define SPIC_GAME_CONSTANTS_HPP

const double TileSize = 32;
const double TileButtonScale = 2.0;
const double TileMapScale = 0.985;
const int MapX = TileSize / 2 + 155;
const int MapY = TileSize / 2;
const int ScreenWidth = 1366;
const int ScreenHeight = 786;
const int HudWidth = 250;
const int HealAbilityCoolDown = 5;

//Enemey
const double EnemyScale = 0.1; //default scale on 1
const int EnemyWidth = 200; //width of enemy image
const int EnemyHeight = 320; //height of enemy image
const int EnemyMass = 50; //random chosen mass
const int EnemyVelocity = 50; //random chosen velocity

//Hero
const double HeroScale = 0.1; //default scale on 1
const int HeroWidth = 200; //width of hero image
const int HeroHeight = 320; //height of hero image
const int HeroMass = 50; //random chosen mass
const int HeroVelocity = 50; //random chosen velocity (looks good)
const double HeroBulletSpeed = 17.5; // random chosen bullet speed (looks alright)

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

#endif
