#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		: mWidth(width)
	{
	}

	SquareLawn::~SquareLawn()
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return mWidth * mWidth;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return static_cast<unsigned int>(mWidth * 4 / 0.25 + 0.5);
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return mWidth * 4 * RED_CEDAR_PRICE;
		case SPRUCE:
			return mWidth * 4 * SPRUCE_PRICE;
		default:
			assert(false);
			return 0;
		}
	}

}