#include "CircleLawn.h"

namespace lab5
{
	const double CircleLawn::PI = 3.14;

	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return static_cast<unsigned int>(PI * mRadius * mRadius + 0.5);
	}
}