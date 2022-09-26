#pragma once
#include "Point.h"

namespace line
{
    class Line
    {
    public:
        Line(point::Point p1, point::Point p2);
        virtual ~Line();
        point::Point GetPoint1() const;
        point::Point GetPoint2() const;
        int GetDistance() const;
        int GetGradient() const;

    private:
        point::Point mP1;
        point::Point mP2;
    };
}