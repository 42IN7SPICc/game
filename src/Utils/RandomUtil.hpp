#ifndef SPIC_GAME_RANDOMUTIL_HPP
#define SPIC_GAME_RANDOMUTIL_HPP

#include <random>

namespace game
{
    class RandomUtil
    {
        private:
            static RandomUtil _instance;
            std::random_device _randomDevice;
            std::default_random_engine _engine;

            RandomUtil();

        public:
            static int Next(int min, int max);

            static double NextDouble(double min, double max);
    };
}

#endif //SPIC_GAME_RANDOMUTIL_HPP
