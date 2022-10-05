#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);
		~CircleLawn();

		unsigned int GetArea() const;
	private:
		const static double PI;
		const unsigned int mRadius;
	};
}
