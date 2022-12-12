#include "Vector.h"

namespace test
{
	Vector::Vector(int x, int y)
		: mX(x)
		, mY(y)
	{
	}

	bool Vector::operator==(const Vector& rhs) const
	{
		return (mX == rhs.mX && mY == rhs.mY);
	}
}

