#include "Vector.h"

namespace test
{
	Vector::Vector(int x, int y)
		: mX(x)
		, mY(y)
	{
	}

	int Vector::GetX() const
	{
		return mX;
	}

	int Vector::GetY() const
	{
		return mY;
	}

	void Vector::DoMagic(std::shared_ptr<Vector> other)
	{
		std::shared_ptr<Vector> anotherV = other;

		mX += anotherV.use_count();
		mY += anotherV.use_count();
	}
}