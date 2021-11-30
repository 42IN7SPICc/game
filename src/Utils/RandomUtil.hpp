#ifndef SPIC_GAME_RANDOMUTIL_HPP
#define SPIC_GAME_RANDOMUTIL_HPP

#include <random>

namespace game
{
    /**
     * @brief
     */
    class RandomUtil
    {
        private:
            static RandomUtil _instance;
            std::random_device _randomDevice;
            std::default_random_engine _engine;

            RandomUtil();

        public:
            /**
             * @brief Get a random int between a minimum and maximum value.
             * @param min The minimum value.
             * @param max The maximum value.
             * @return The random int.
             */
            static int Next(int min, int max);

            /**
             * @brief Get a random double between a minimum and maximum value.
             * @param min The minimum value.
             * @param max The maximum value.
             * @return The random double.
             */
            static double NextDouble(double min, double max);

            /**
             * @brief Generate a random string with a given length.
             * @param maxLength The lenght of the string.
             * @return The randomly generated string.
             */
            static std::string NextString(int maxLength);
    };
}

#endif //SPIC_GAME_RANDOMUTIL_HPP
