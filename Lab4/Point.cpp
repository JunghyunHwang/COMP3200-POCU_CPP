#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
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

	Point Point::operator+(const Point& other) const
	{
		Point result(*this);
		
		result.mX += other.mX;
		result.mY += other.mY;
		
		return result;
	}

	Point Point::operator-(const Point& other) const
	{
		Point result(*this);

		result.mX -= other.mX;
		result.mY -= other.mY;

		return result;
	}

	float Point::Dot(const Point& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	Point Point::operator*(const float operand) const
	{
		Point result(*this);

		result.mX *= operand;
		result.mY *= operand;

		return result;
	}

	Point operator*(float operand, const Point& point)
	{
		Point result(point);

		result.mX *= operand;
		result.mY *= operand;

		return result;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}