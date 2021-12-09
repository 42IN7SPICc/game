#ifndef SPIC_GAME_ENEMYCONSTANTS_HPP
#define SPIC_GAME_ENEMYCONSTANTS_HPP

// Generic
const double EnemyScale = 0.1; // The scale of the enemy game object
const int EnemyWidth = 200; // The width of the enemy without scale
const int EnemyHeight = 320; // The height of the enemy without scale
const int EnemyMass = 50; // Random mass given to the hero
const int EnemyVelocity = 5; // The walking speed of an enemy
const int EnemyDeSpawnTime = 4; // The time it takes to de spawn an enemy after death

//Enemy Panzer (first enemy)
const double PanzerEnemyFireRate = 15; // The shooting interval of the panzer enemy
const int PanzerEnemyRange = 200; // The detection range of the hero for the panzer enemy
const int PanzerEnemyDamage = 20; // The damage of a bullet for the panzer enemy
const int PanzerEnemyBulletSpeed = 20; // The bullet velocity of the panzer enemy
const int PanzerEnemyHealth = 200; // The bullet velocity of the panzer enemy

#endif //SPIC_GAME_ENEMYCONSTANTS_HPP
