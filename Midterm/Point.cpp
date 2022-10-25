#include "Point.h"

Point::Point()
	: mX(0)
	, mY(0)
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