#ifndef SPIC_GAME_ENEMYCONSTANTS_HPP
#define SPIC_GAME_ENEMYCONSTANTS_HPP

// Generic
const double EnemyScale = 0.1; // The scale of the enemy game object
const int EnemyWidth = 200; // The width of the enemy without scale
const int EnemyHeight = 320; // The height of the enemy without scale
const int EnemyMass = 50; // Random mass given to the hero
const int EnemyVelocity = 25; // The walking speed of an enemy
const int EnemyDeSpawnTime = 4; // The time it takes to de spawn an enemy after death

//Enemy Panzer (first enemy)
const double PanzerEnemyFireRate = 10; // The shooting interval of the panzer enemy
const int PanzerEnemyRange = 200; // The detection range of the hero for the panzer enemy
const int PanzerEnemyDamage = 30; // The damage of a bullet for the panzer enemy
const double PanzerEnemyVelocity = 0.5; // The movement speed
const int PanzerEnemyBulletSpeed = 6; // The bullet velocity of the panzer enemy
const int PanzerEnemyHealth = 1000; // The health / armor of the panzer tank
const int PanzerEnemyValue = 400; // Value of enemy

//Enemy Gruppenfuhrer
const double GruppenfuhrerEnemyFireRate = 3; // The shooting interval of the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyRange = 200; // The detection range of the hero for the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyDamage = 2; // The damage of a bullet for the Gruppenfuhrer enemy
const double GruppenfuhrerEnemyVelocity = 1; // The movement speed
const int GruppenfuhrerEnemyBulletSpeed = 15; // The bullet velocity of the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyHealth = 175; // The health of the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyValue = 60; // Value of enemy

const int GruppenfuhrerEnemyBoostCoolDown = 10; // The cool down between boost actions of the Gruppenfuhrer enemy
const double GruppenfuhrerEnemySpeedBoost = 1.5; // The boost to give to enemies of the Gruppenfuhrer enemy
const int GruppenfuhrerEnemyBoostTime = 5; // The time the boost lasts of the Gruppenfuhrer enemy
const double GruppenfuhrerEnemyBoostRange = 100; // The range enemies have to be in for the effect of the Gruppenfuhrer enemy
template <typename T>
spic::Color GruppenfuhrerColor() {
    return T::green();
}

//Enemy Schutze
const double SchutzeEnemyFireRate = 3; // The shooting interval of the Schutze enemy
const int SchutzeEnemyRange = 200; // The detection range of the hero for the Schutze enemy
const int SchutzeEnemyDamage = 2; // The damage of a bullet for the Schutze enemy
const double SchutzeEnemyVelocity = 1; // The movement speed
const int SchutzeEnemyBulletSpeed = 15; // The bullet velocity of the Schutze enemy
const int SchutzeEnemyHealth = 150; // The health of the Schutze enemy
const int SchutzeEnemyValue = 25; // Value of enemy

//Enemy Erkunder
const double ErkunderEnemyFireRate = 3; // The shooting interval of the Erkunder enemy
const int ErkunderEnemyRange = 200; // The detection range of the hero for the Erkunder enemy
const int ErkunderEnemyDamage = 2; // The damage of a bullet for the Erkunder enemy
const double ErkunderEnemyVelocity = 2; // The movement speed
const int ErkunderEnemyBulletSpeed = 15; // The bullet velocity of the Erkunder enemy
const int ErkunderEnemyHealth = 125; // The health of the Erkunder enemy
const int ErkunderEnemyValue = 50; // Value of enemy
template <typename T>
spic::Color ErkunderColor() {
    return T::yellow();
}

//Enemy GhillieAnzugSchutze
const double GhillieAnzugSchutzeEnemyFireRate = 3; // The shooting interval of the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyRange = 200; // The detection range of the hero for the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyDamage = 2; // The damage of a bullet for the GhillieAnzugSchutze enemy
const double GhillieAnzugEnemyVelocity = 1; // The movement speed
const int GhillieAnzugSchutzeEnemyBulletSpeed = 25; // The bullet velocity of the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyHealth = 150; // The health of the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyValue = 60; // Value of enemy

const int GhillieAnzugSchutzeEnemyInvisibleEffectTime = 3; // The time of the invisible effect of the GhillieAnzugSchutze enemy
const int GhillieAnzugSchutzeEnemyInvisibleCoolDownTime = 5; // The cool down time of the invisible effect of the GhillieAnzugSchutze enemy
template <typename T>
spic::Color GhillieAnzugSchutzeColor() {
    return T::red();
}

//Enemy Stabsarzt
const double StabsarztEnemyVelocity = 1.0; // The movement speed
const int StabsarztEnemyHealth = 175; // The health of the Stabsarzt enemy
const int StabsarztEnemyValue = 75; // Value of enemy

const int StabsarztHealCooldown = 10; // The time between healing actions of the Stabsarzt enemy
const double StabsarztHealRange = 100; // The maximum distance between the healer and other enemies to heal.
const int StabsarztHealPercentage = 10; // The percentage to heal other enemies.
template <typename T>
spic::Color StabsarztColor() {
    return T::cyan();
}

//Enemy Raupenschlepper
const double RaupenschlepperEnemyVelocity = 0.7; // The movement speed
const int RaupenschlepperEnemyHealth = 350; // The health of the Raupenschlepper enemy
const int RaupenschlepperEnemyValue = 150; // Value of enemy

#endif //SPIC_GAME_ENEMYCONSTANTS_HPP
