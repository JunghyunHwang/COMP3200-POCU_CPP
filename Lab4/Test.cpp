#include <iostream>

#include "Point.h"
#include "PolyLine.h"
#include "Test.h"

namespace testcase
{
    void testMinBoundingRectangle()
    {
        lab4::PolyLine pl1;

        pl1.AddPoint(1, 2);
        pl1.AddPoint(-3, -1);
        pl1.AddPoint(new lab4::Point(0, 0));
    }
}