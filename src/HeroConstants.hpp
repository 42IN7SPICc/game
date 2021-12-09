#ifndef SPIC_GAME_HEROCONSTANTS_HPP
#define SPIC_GAME_HEROCONSTANTS_HPP

// Generic
const double HeroScale = 0.1; //default scale on 1
const int BaseHeroHealth = 20; // Gets multiplied by the hero's defense rating
const int BaseHeroDamage = 6; // Gets multiplied by the hero's attack rating
const int HeroMass = 50; //random chosen mass
const int HeroVelocity = 15; //random chosen velocity (looks good)
const double HeroBulletSpeed = 17.5; // random chosen bullet speed (looks alright)
const double HeroBulletRange = 200; // random chosen bullet range (looks alright)
const double HeroShootingCoolDown = 0.5; // random chosen bullet speed (looks alright)
const int HeroWidth = 200; //width of hero image
const int HeroHeight = 320; //height of hero image

//Desmond Doss
const int DesmondDossDamage = 2; // The damage Desmond Doss does
const int DesmondDossDefense = 3; // The defense Desmond Doss has
const int DesmondDossHealAbilityAmount = 5; // The amount Desmond Doss heals when activating his ability
const int DesmondDossHealAbilityCoolDown = 5; // The default cool down of a hero ability
template<typename T>
spic::Color DesmondDossColor()
{
    return T::red();
}

//Bernard IJzerdraat
const int BernardIJzerdraatDamage = 5; // The damage Bernard IJzerdraat does
const int BernardIJzerdraatDefense = 3; // The defense Bernard IJzerdraat has
const int BernardIJzerdraatAbilityCooldown = 5; // Ability Cooldown for Bernard IJzerdraat
const int BernardIJzerdraatAbilityDuration = 5; // Ability Duration for Bernard IJzerdraat
template<typename T>
spic::Color BernardIJzerdraatColor()
{
    return T::lime();
}

//Franklin D Roosevelt
const int FranklinDRooseveltDamage = 4; // The damage Franklin D Roosevelt does
const int FranklinDRooseveltDefense = 2; // The defense Franklin D Roosevelt has
const int FranklinDRooseveltAirstrikeAbilityCooldown = 20; // The cooldown timer for the airstrike ability
const int FranklinDRooseveltAirstrikeAbilityDamage = 40; // The damage the airstrike ability does to every enemy on screen
const int FranklinDRooseveltTowerRangeAbilityCooldown = 20; // The cooldown timer for the tower range ability
template<typename T>
spic::Color FranklinDRooseveltColor()
{
    return T::cyan();
}

//Winston Churchill
const int WinstonChurchillDamage = 2; // The damage Winston Churchill does
const int WinstonChurchillDefense = 5; // The defense Winston Churchill has
const int WinstonChurchillTowerFireRateAbilityCooldown = 20; // The cooldown timer for the tower fire rate ability
template<typename T>
spic::Color WinstonChurchillColor()
{
    return T::purple();
}

//Joseph Stalin
const int JosephStalinDamage = 5; // The damage Joseph Stalin does
const int JosephStalinDefense = 5; // The defense Joseph Stalin has
const int JosephStalinAbilityCooldown = 15; // The defense Joseph Stalin has
const int JosephStalinAbilityDuration = 5; // The defense Joseph Stalin has
template<typename T>
spic::Color JosephStalinColor()
{
    return T::orange();
}

#endif //SPIC_GAME_HEROCONSTANTS_HPP
