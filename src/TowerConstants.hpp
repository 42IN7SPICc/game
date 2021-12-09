#ifndef SPIC_GAME_TOWERCONSTANTS_HPP
#define SPIC_GAME_TOWERCONSTANTS_HPP

//Tower Shotgun
const double ShotgunTowerFireRate = 10; // The shooting interval of the shotgun tower
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
const int FlamethrowerTowerRange = 150; // The detection range of the hero for the flamethrower tower
const int FlamethrowerTowerDamage = 1; // The damage of a bullet for the flamethrower tower
const int FlamethrowerTowerBulletSpeed = 5; // The bullet velocity of the flamethrower tower
template<typename T>
spic::Color FlamethrowerTowerColor()
{
    return T::green();
}

//Tower Bomber
const double BomberTowerFireRate = 10; // The shooting interval of the bomber tower
const int BomberTowerRange = 200; // The detection range of the hero for the bomber tower
const int BomberTowerDamage = 10; // The damage of a bullet for the bomber tower
const int BomberTowerBulletSpeed = 10; // The bullet velocity of the bomber tower
const int BomberTowerExplosionRange = 64; // The range of an explosion
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

#endif //SPIC_GAME_TOWERCONSTANTS_HPP
