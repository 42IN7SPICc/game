#include "RandomUtil.hpp"

using namespace game;

RandomUtil RandomUtil::_instance{};

RandomUtil::RandomUtil()
{
  std::random_device device{};
  _engine = std::default_random_engine{device()};
}
