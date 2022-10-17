#include "Point.h"

unsigned int Point::mCount = 0;

Point::Point(int x, int y)
	: mX(x)
	, mY(y)
{
}

Point::Point(const Point& other)
	: mX(other.mX)
	, mY(other.mY)
{
	++mCount;
}

Point::~Point()
{
}
