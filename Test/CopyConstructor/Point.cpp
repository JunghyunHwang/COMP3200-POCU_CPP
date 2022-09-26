#include <iostream>
#include "Point.h"

namespace point
{
    Point::Point(int x, int y)
        : mX(x)
        , mY(y)
    {
    }

    Point::Point(const Point& other)
        : mX(other.mX)
        , mY(other.mY)
    {
        std::cout << "Call Point copy constructor!" << std::endl;
    }

    void Point::SetX(int x)
    {
        mX = x;
    }

    void Point::SetY(int y)
    {
        mY = y;
    }

    int Point::GetX() const
    {
        return mX;
    }

    int Point::GetY() const
    {
        return mY;
    }
}