#ifndef SPIC_GAME_POINTUTIL_HPP
#define SPIC_GAME_POINTUTIL_HPP

#include <Point.hpp>

namespace game
{
    class PointUtil
    {
        public:
            static spic::Point CalculateDirectionalPoint(const spic::Point& from, const spic::Point& to, double multiplier = 1.0);
    };
}

#endif //SPIC_GAME_POINTUTIL_HPP
