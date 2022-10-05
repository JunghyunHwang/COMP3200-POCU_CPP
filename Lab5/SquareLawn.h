#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(unsigned int width);
		~SquareLawn();

		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		const unsigned int mWidth;
	};
}