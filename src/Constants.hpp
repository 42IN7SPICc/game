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
const int BaseHeroDamage = 5; // Gets multiplied by the hero's attack rating
const int HeroWidth = 200; //width of hero image
const int HeroHeight = 320; //height of hero image
const int HeroMass = 50; //random chosen mass
const int HeroVelocity = 15; //random chosen velocity (looks good)
const double HeroBulletSpeed = 17.5; // random chosen bullet speed (looks alright)
const double HeroBulletRange = 500; // random chosen bullet speed (looks alright)
const double HeroShootingCoolDown = 0.5; // random chosen bullet speed (looks alright)

//Desmond Doss (first hero)
const int DesmondDossDamage = 2; // The damage Desmond Doss does
const int DesmondDossDefense = 3; // The defense Desmond Doss has
const int DesmondDossHealAbilityAmount = 5; // The amount Desmond Doss heals when activating his ability

//Enemy Panzer
const double PanzerEnemyFireRate = 3; // The shooting interval of the panzer enemy
const int PanzerEnemyRange = 200; // The detection range of the hero for the panzer enemy
const int PanzerEnemyDamage = 2; // The damage of a bullet for the panzer enemy
const int PanzerEnemyBulletSpeed = 25; // The bullet velocity of the panzer enemy
const int PanzerEnemyHealth = 100; // The bullet velocity of the panzer enemy

//Enemy Gruppenfuhrer
const double GruppenfuhrerEnemyFireRate = 3; // The shooting interval of the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyRange = 200; // The detection range of the hero for the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyDamage = 2; // The damage of a bullet for the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyBulletSpeed = 25; // The bullet velocity of the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyHealth = 100; // The bullet velocity of the Gruppenfuhrer enemy

//Enemy Schutze
const double SchutzeEnemyFireRate = 3; // The shooting interval of the Schutze enemy
const int SchutzeEnemyRange = 200; // The detection range of the hero for the Schutze enemy
const int SchutzeEnemyDamage = 2; // The damage of a bullet for the Schutze enemy
const int SchutzeEnemyBulletSpeed = 25; // The bullet velocity of the Schutze enemy
const int SchutzeEnemyHealth = 100; // The bullet velocity of the Schutze enemy

//Enemy Erkunder
const double ErkunderEnemyFireRate = 3; // The shooting interval of the Erkunder enemy
const int ErkunderEnemyRange = 200; // The detection range of the hero for the Erkunder enemy
const int ErkunderEnemyDamage = 2; // The damage of a bullet for the Erkunder enemy
const int ErkunderEnemyBulletSpeed = 25; // The bullet velocity of the Erkunder enemy
const int ErkunderEnemyHealth = 100; // The bullet velocity of the Erkunder enemy

//Enemy GhillieAnzugSchutze
const double GhillieAnzugSchutzeEnemyFireRate = 3; // The shooting interval of the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyRange = 200; // The detection range of the hero for the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyDamage = 2; // The damage of a bullet for the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyBulletSpeed = 25; // The bullet velocity of the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyHealth = 100; // The bullet velocity of the GhillieAnzugSchutze enemy

//Enemy Stabsarzt
const int StabsarztHealCooldown = 10; // The time between healing actions of the Stabsarzt enemy
const double StabsarztHealRange = 100; // The maximum distance between the healer and other enemies to heal.
const int StabsarztHealPercentage = 10; // The percentage to heal other enemies.

//Tower Shotgun
const double ShotgunTowerFireRate = 5; // The shooting interval of the shotgun tower
const int ShotgunTowerRange = 250; // The detection range of the hero for the shotgun tower
const int ShotgunTowerDamage = 20; // The damage of a bullet for the shotgun tower
const int ShotgunTowerBulletSpeed = 15; // The bullet velocity of the shotgun tower
template<typename T>
spic::Color ShotgunTowerColor()
{
    return T::red();
}

//Tower Flamethrower
const double FlamethrowerTowerFireRate = 0.1; // The shooting interval of the flamethrower tower
const int FlamethrowerTowerRange = 200; // The detection range of the hero for the flamethrower tower
const int FlamethrowerTowerDamage = 1; // The damage of a bullet for the flamethrower tower
const int FlamethrowerTowerBulletSpeed = 5; // The bullet velocity of the flamethrower tower
template<typename T>
spic::Color FlamethrowerTowerColor()
{
    return T::green();
}

//Tower Bomber
const double BomberTowerFireRate = 4; // The shooting interval of the bomber tower
const int BomberTowerRange = 250; // The detection range of the hero for the bomber tower
const int BomberTowerDamage = 20; // The damage of a bullet for the bomber tower
const int BomberTowerBulletSpeed = 10; // The bullet velocity of the bomber tower
const int BomberTowerExplosionRange = TileSize * 2; // The range of an explosion
template<typename T>
spic::Color BomberTowerColor()
{
    return T::blue();
}

//Tower Sniper
const double SniperTowerFireRate = 8; // The shooting interval of the sniper tower
const int SniperTowerRange = 500; // The detection range of the hero for the sniper tower
const int SniperTowerDamage = 50; // The damage of a bullet for the sniper tower
const int SniperTowerBulletSpeed = 35; // The bullet velocity of the sniper tower
template<typename T>
spic::Color SniperTowerColor()
{
    return T::yellow();
}

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
