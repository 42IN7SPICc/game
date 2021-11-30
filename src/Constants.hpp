#ifndef SPIC_GAME_CONSTANTS_HPP
#define SPIC_GAME_CONSTANTS_HPP

//Game HUD and Level
const double TileSize = 32; // Size of a single TileSprite
const double TileButtonScale = 2.0; // Size of tile select button inside of the HUD
const double TileMapScale = 0.985; // Scale of the entire 25 x 25 map
const int MapX = TileSize / 2 + 155; // Starting x location of the map
const int MapY = TileSize / 2; // Starting y location of the map
const int ScreenWidth = 1366; // Width of the screen
const int ScreenHeight = 786; // Height of the screen
const int HudWidth = 250; // Width of the HUD inside a level
const int HealAbilityCoolDown = 5; // The default cool down of a hero ability

//Enemy
const double EnemyScale = 0.1; // The scale of the enemy game object
const int EnemyWidth = 200; // The width of the enemy without scale
const int EnemyHeight = 320; // The height of the enemy without scale
const int EnemyMass = 50; // Random mass given to the hero
const int EnemyVelocity = 5; // The walking speed of an enemy
const int EnemyDeSpawnTime = 4; // The time it takes to de spawn an enemy after death
const int DefaultEnemyKillBalance = 50; // The money you get after killing an enemy

//Hero
const double HeroScale = 0.1; //default scale on 1
const int BaseHeroHealth = 20; // Gets multiplied by the hero's defense rating
const int HeroWidth = 200; //width of hero image
const int HeroHeight = 320; //height of hero image
const int HeroMass = 50; //random chosen mass
const int HeroVelocity = 50; //random chosen velocity (looks good)
const double HeroBulletSpeed = 17.5; // random chosen bullet speed (looks alright)

//Enemy Panzer (first enemy)
const double PanzerEnemyFireRate = 3; // The shooting interval of the panzer enemy
const int PanzerEnemyRange = 500; // The detection range of the hero for the panzer enemy
const int PanzerEnemyDamage = 15; // The damage of a bullet for the panzer enemy
const int PanzerEnemyBulletSpeed = 25; // The bullet velocity of the panzer enemy

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
