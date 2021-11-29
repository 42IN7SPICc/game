#ifndef SPIC_GAME_POINTUTIL_HPP
#define SPIC_GAME_POINTUTIL_HPP

#define _USE_MATH_DEFINES

#include <Point.hpp>

#include <cmath>

namespace game
{
    class PointUtil
    {
        public:
            static spic::Point CalculateDirectionalPoint(const spic::Point& from, const spic::Point& to, double multiplier = 1.0);

            static double Distance(const spic::Point& from, const spic::Point& to);

            static double Distance(const spic::Point& pointDiff);

            static spic::Point PointDiff(const spic::Point& point1, const spic::Point& point2);

            static double Degrees(const spic::Point& point1, const spic::Point& point2);
    };
}

#endif //SPIC_GAME_POINTUTIL_HPP
