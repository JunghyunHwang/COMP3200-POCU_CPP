#include "EquilateralTriangleLawn.h"
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side)
		: mSide(side)
	{
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(sqrt(3) / 4 * mSide * mSide + 0.5);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return static_cast<unsigned int>(mSide * 3 / 0.25 + 0.5);
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return mSide * 3 * RED_CEDAR_PRICE;
		case SPRUCE:
			return mSide * 3 * SPRUCE_PRICE;
		default:
			assert(false);
			return 0;
		}
	}
}