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

//Desmond Doss
const int DesmondDossDamage = 2; // The damage Desmond Doss does
const int DesmondDossDefense = 3; // The defense Desmond Doss has
const int DesmondDossHealAbilityAmount = 5; // The amount Desmond Doss heals when activating his ability
template <typename T>
spic::Color DesmondDossColor() {
    return T::red();
}

//Bernard IJzerdraat
const int BernardIJzerdraatDamage = 5; // The damage Bernard IJzerdraat does
const int BernardIJzerdraatDefense = 3; // The defense Bernard IJzerdraat has
template <typename T>
spic::Color BernardIJzerdraatColor() {
    return T::lime();
}

//Franklin D Roosevelt
const int FranklinDRooseveltDamage = 4; // The damage Franklin D Roosevelt does
const int FranklinDRooseveltDefense = 2; // The defense Franklin D Roosevelt has
template <typename T>
spic::Color FranklinDRooseveltColor() {
    return T::cyan();
}

//Winston Churchill
const int WinstonChurchillDamage = 2; // The damage Winston Churchill does
const int WinstonChurchillDefense = 5; // The defense Winston Churchill has
template <typename T>
spic::Color WinstonChurchillColor() {
    return T::purple();
}

//Joseph Stalin
const int JosephStalinDamage = 5; // The damage Joseph Stalin does
const int JosephStalinDefense = 5; // The defense Joseph Stalin has
template <typename T>
spic::Color JosephStalinColor() {
    return T::orange();
}

//Enemy Panzer (first enemy)
const double PanzerEnemyFireRate = 3; // The shooting interval of the panzer enemy
const int PanzerEnemyRange = 200; // The detection range of the hero for the panzer enemy
const int PanzerEnemyDamage = 2; // The damage of a bullet for the panzer enemy
const int PanzerEnemyBulletSpeed = 25; // The bullet velocity of the panzer enemy
const int PanzerEnemyHealth = 100; // The bullet velocity of the panzer enemy

//Tower Shotgun
const double ShotgunTowerFireRate = 5; // The shooting interval of the shotgun tower
const int ShotgunTowerRange = 250; // The detection range of the hero for the shotgun tower
const int ShotgunTowerDamage = 20; // The damage of a bullet for the shotgun tower
const int ShotgunTowerBulletSpeed = 15; // The bullet velocity of the shotgun tower
template <typename T>
spic::Color ShotgunTowerColor() {
    return T::red();
}

//Tower Flamethrower
const double FlamethrowerTowerFireRate = 0.1; // The shooting interval of the flamethrower tower
const int FlamethrowerTowerRange = 200; // The detection range of the hero for the flamethrower tower
const int FlamethrowerTowerDamage = 1; // The damage of a bullet for the flamethrower tower
const int FlamethrowerTowerBulletSpeed = 5; // The bullet velocity of the flamethrower tower
template <typename T>
spic::Color FlamethrowerTowerColor() {
    return T::green();
}

//Tower Bomber
const double BomberTowerFireRate = 4; // The shooting interval of the bomber tower
const int BomberTowerRange = 250; // The detection range of the hero for the bomber tower
const int BomberTowerDamage = 20; // The damage of a bullet for the bomber tower
const int BomberTowerBulletSpeed = 10; // The bullet velocity of the bomber tower
const int BomberTowerExplosionRange = TileSize * 2; // The range of an explosion
template <typename T>
spic::Color BomberTowerColor() {
    return T::blue();
}

//Tower Sniper
const double SniperTowerFireRate = 8; // The shooting interval of the sniper tower
const int SniperTowerRange = 500; // The detection range of the hero for the sniper tower
const int SniperTowerDamage = 50; // The damage of a bullet for the sniper tower
const int SniperTowerBulletSpeed = 35; // The bullet velocity of the sniper tower
template <typename T>
spic::Color SniperTowerColor() {
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
