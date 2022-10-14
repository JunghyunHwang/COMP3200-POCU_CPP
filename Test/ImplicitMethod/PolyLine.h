#pragma once

#include "Point.h"

namespace test
{
    class PolyLine
    {
    public:
        ~PolyLine();

        float GetDistanceSquare() const;
        Point GetP1() const;
        Point GetP2() const;
    private:
        Point mP1;
        Point mP2;
    };
}