#include "Vector.h"

namespace practice
{
	Vector::Vector(int x, int y)
		: mX(x)
		, mY(y)
	{
	}

	Vector::~Vector()
	{
	}

	Vector Vector::operator+(const Vector& rhs) const
	{
		Vector v(mX + rhs.mX, mY + rhs.mY);

		return v;
	}

	Vector Vector::operator*(const Vector& rhs) const
	{
		Vector v(mX * rhs.mX, mY * rhs.mY);
		return v;
	}

	Vector Vector::operator-(const Vector& rhs) const
	{
		Vector v(mX - rhs.mX, mY - rhs.mY);

		return v;
	}

	Vector operator*(int lhs, const Vector& rhs)
	{
		Vector v(lhs * rhs.mX, lhs * rhs.mY);

		return v;
	}

	Vector& Vector::operator++()
	{
		++mX;
		++mY;
		return *this;
	}

	Vector Vector::operator++(int)
	{
		Vector v(*this);
		++mX;
		++mY;

		return v;
	}

	Vector& Vector::operator--()
	{
		--mX;
		--mY;
		return *this;
	}

	Vector Vector::operator--(int)
	{
		Vector v(*this);
		--mX;
		--mY;
		return v;
	}
}