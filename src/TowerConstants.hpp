#ifndef SPIC_GAME_TOWERCONSTANTS_HPP
#define SPIC_GAME_TOWERCONSTANTS_HPP

//Tower Shotgun - 10 dps (has more range then flamethrower)
const int ShotgunTowerCost = 300; // The amount of money it takes or the player to buy one
const double ShotgunTowerFireRate = 2; // The shooting interval of the shotgun tower
const int ShotgunTowerRange = 250; // The detection range of the hero for the shotgun tower
const int ShotgunTowerDamage = 20; // The damage of a bullet for the shotgun tower
const int ShotgunTowerBulletSpeed = 15; // The bullet velocity of the shotgun tower
template<typename T>
spic::Color ShotgunTowerColor()
{
    return T::red();
}

//Tower Flamethrower - 60 dps (stronger but less range then shotgun and low accuracy)
const int FlamethrowerTowerCost = 350; // The amount of money it takes or the player to buy one
const double FlamethrowerTowerFireRate = 0.1; // The shooting interval of the flamethrower tower
const int FlamethrowerTowerRange = 60; // The detection range of the hero for the flamethrower tower
const int FlamethrowerTowerDamage = 6; // The damage of a bullet for the flamethrower tower
const int FlamethrowerTowerBulletSpeed = 30; // The bullet velocity of the flamethrower tower
template<typename T>
spic::Color FlamethrowerTowerColor()
{
    return T::green();
}

//Tower Bomber - 3 dps (but it multi target)
const int BomberTowerCost = 600; // The amount of money it takes or the player to buy one
const double BomberTowerFireRate = 5; // The shooting interval of the bomber tower
const int BomberTowerRange = 100; // The detection range of the hero for the bomber tower
const int BomberTowerDamage = 10; // The damage of a bullet for the bomber tower
const int BomberTowerBulletSpeed = 10; // The bullet velocity of the bomber tower
const int BomberTowerExplosionRange = 64; // The range of an explosion
template<typename T>
spic::Color BomberTowerColor()
{
    return T::blue();
}

//Tower Sniper - 6.25 dps
const int SniperTowerCost = 550; // The amount of money it takes or the player to buy one
const double SniperTowerFireRate = 8; // The shooting interval of the sniper tower
const int SniperTowerRange = 500; // The detection range of the hero for the sniper tower
const int SniperTowerDamage = 50; // The damage of a bullet for the sniper tower
const int SniperTowerBulletSpeed = 40; // The bullet velocity of the sniper tower
const int SniperMaxPenetrating = 3; // How many enemies a single bullet can hit
template<typename T>
spic::Color SniperTowerColor()
{
    return T::yellow();
}

#endif //SPIC_GAME_TOWERCONSTANTS_HPP
