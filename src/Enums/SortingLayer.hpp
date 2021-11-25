#ifndef SPIC_GAME_SORTINGLAYER_HPP
#define SPIC_GAME_SORTINGLAYER_HPP

namespace game
{
    enum SortingLayer
    {
        Map = 10,
        Tower = 20,
        Enemy = 40,
        Hero = 60,
        Bullet = 80,

        HudBackground = 1000,
        HudText = 1100,
        HudButton = 1200,
    };
}

#endif //SPIC_GAME_SORTINGLAYER_HPP
