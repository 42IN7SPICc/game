#include <cmath>
#include "PointUtil.hpp"

spic::Point game::PointUtil::CalculateDirectionalPoint(const spic::Point& from, const spic::Point& to, double multiplier)
{
    auto posDiff = spic::Point{to.x - from.x, to.y - from.y};
    double distance = sqrt(posDiff.x * posDiff.x + posDiff.y * posDiff.y);
    return {posDiff.x / distance * multiplier, posDiff.y / distance * multiplier};
}