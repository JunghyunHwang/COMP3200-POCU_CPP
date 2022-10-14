#include "Point.h"

namespace test
{
    Point::Point()
        : mX(0)
        , mY(0)
    {
    }

    Point::Point(int x, int y)
        : mX(x)
        , mY(y)
    {
    }
    
    Point::Point(const Point& other)
        : mX(other.mX)
        , mY(other.mY)
    {
        std::cout << "Copy Point" << std::endl;
    }

    Point::~Point()
    {
    }

    bool Point::operator==(const Point& rhs)
    {
        return (mX == rhs.mX && mY == rhs.mY);
    }
}