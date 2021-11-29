#include "PointUtil.hpp"

spic::Point game::PointUtil::CalculateDirectionalPoint(const spic::Point& from, const spic::Point& to, double multiplier)
{
    auto pointDiff = PointDiff(from, to);
    auto distance = Distance(pointDiff);
    return {pointDiff.x / distance * multiplier, pointDiff.y / distance * multiplier};
}

double game::PointUtil::Distance(const spic::Point& from, const spic::Point& to)
{
    auto pointDiff = PointDiff(from, to);
    return sqrt(pointDiff.x * pointDiff.x + pointDiff.y * pointDiff.y);
}

double game::PointUtil::Distance(const spic::Point& pointDiff)
{
    return sqrt(pointDiff.x * pointDiff.x + pointDiff.y * pointDiff.y);
}

spic::Point game::PointUtil::PointDiff(const spic::Point& point1, const spic::Point& point2)
{
    return {point2.x - point1.x, point2.y - point1.y};
}

double game::PointUtil::Degrees(const spic::Point& point1, const spic::Point& point2)
{
    return atan2(point1.y - point2.y, point1.x - point2.x) * 180 / M_PI - 90;
}
