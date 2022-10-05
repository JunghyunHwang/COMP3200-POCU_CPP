#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return static_cast<unsigned int>((mWidth * 2 + mHeight * 2) / 0.25 + 0.5);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return (mWidth + mHeight) * 2 * RED_CEDAR_PRICE;
		case SPRUCE:
			return (mWidth + mHeight) * 2 * SPRUCE_PRICE;
		default:
			assert(false);
			return 0;
		}
	}
}