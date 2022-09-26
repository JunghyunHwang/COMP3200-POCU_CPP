#pragma once

#include "Point.h"

namespace line
{
	class Line
	{
    public:
        Line(point::Point p1, point::Point p2);
        point::Point GetPoint1() const;
        point::Point GetPoint2() const;

    private:
        point::Point mP1;
        point::Point mP2;
	};
}
