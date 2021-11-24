#include "RandomUtil.hpp"

using namespace game;

RandomUtil RandomUtil::_instance{};

RandomUtil::RandomUtil() : _randomDevice(std::random_device{}), _engine{_randomDevice()}
{
}

int RandomUtil::Next(int min, int max)
{
    std::uniform_int_distribution<int> dist{min, max};
    return dist(_instance._engine);
}

double RandomUtil::NextDouble(double min, double max)
{
    std::uniform_real_distribution<double> dist{min, max};
    return dist(_instance._engine);
}
