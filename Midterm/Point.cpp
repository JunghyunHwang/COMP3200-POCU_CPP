#include "Point.h"

Point::Point(int x, int y)
	: mX(x)
	, mY(y)
{
}

Point::Point(const Point& other)
	: mX(other.mX)
	, mY(other.mY)
{
}

Point::~Point()
{
}

int Point::GetX() const
{
	return mX;
}

int Point::GetY() const
{
	return mY;
}