#include "Point.h"

namespace test
{
    unsigned int Point::mCount = 0;
    
    Point::Point(int x, int y)
        : mX(x)
        , mY(y)
    {
        Increase();
    }

    Point::~Point()
    {
    }

    void Point::Increase()
    {
        // doMagic();
    }

    void Point::doMagic()
    {
        ++mCount;
    }
}