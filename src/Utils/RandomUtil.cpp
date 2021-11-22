#include "RandomUtil.hpp"

using namespace game;

RandomUtil RandomUtil::_instance{};

RandomUtil::RandomUtil()
{
  std::random_device device{};
  _engine = std::default_random_engine{device()};
}

RandomUtil::Next(int min, int max)
{
  std::uniform_int_distribution<int> dist{min, max};
  return dist(_instance._engine);
}
