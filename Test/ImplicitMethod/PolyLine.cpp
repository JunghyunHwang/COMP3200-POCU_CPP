#include "PolyLine.h"

namespace test
{
    PolyLine::~PolyLine()
    {
    }

    float PolyLine::GetDistanceSquare() const
    {
        int width = mP1.GetX() - mP2.GetX();
        int height = mP1.GetY() - mP2.GetY();

        return static_cast<float>(width * width + height * height);
    }

    Point PolyLine::GetP1() const
    {
        return mP1;
    }

    Point PolyLine::GetP2() const
    {
        return mP2;
    }
}