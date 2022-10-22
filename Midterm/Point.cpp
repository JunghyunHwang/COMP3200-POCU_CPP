#include "Point.h"

int Point::mCount = 0;

Point::Point()
	: mX(0)
	, mY(0)
{
	++mCount;
}

Point::Point(const Point& other)
	: mX(other.mX)
	, mY(other.mY)
{
	--mCount;
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

int Point::GetCount()
{
	return mCount;
}