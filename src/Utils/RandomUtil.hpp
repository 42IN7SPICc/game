#ifndef KMINTAPP_RANDOM_HPP
#define KMINTAPP_RANDOM_HPP

#include <random>

namespace game
{
    class RandomUtil
    {
        private:
            static RandomUtil _instance;
            std::default_random_engine _engine;

            RandomUtil()
            {
                std::random_device device{};
                _engine = std::default_random_engine{device()};
            }

        public:
            static int Next(int min, int max)
            {
                std::uniform_int_distribution<int> dist{min, max};
                return dist(_instance._engine);
            }
    };
}

#endif //KMINTAPP_RANDOM_HPP
