#pragma once

#include <cassert>
#include "eGrassType.h"
#include "eGrassPrice.h"

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;
	private:
		const static double OVERPRICE;
		const static double UNIT_ROLL_AREA;
	};
}