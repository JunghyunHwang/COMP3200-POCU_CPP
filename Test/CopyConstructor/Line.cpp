#include "Line.h"

namespace line
{
    Line::Line(point::Point p1, point::Point p2)
        : mP1(p1)
        , mP2(p2)
    {
    }

    point::Point Line::GetPoint1() const
    {
        return mP1;
    }

    point::Point Line::GetPoint2() const
    {
        return mP2;
    }
}