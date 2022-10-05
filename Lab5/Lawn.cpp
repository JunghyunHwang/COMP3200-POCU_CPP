#include "Lawn.h"

namespace lab5
{
	const double Lawn::OVERPRICE = 0.9;
	const double Lawn::UNIT_ROLL_AREA = 0.3;

	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double result;

		switch (grassType)
		{
		case BERMUDA:
			result = GetArea() * BERMUDA_PRICE;
			break;
		case BAHIA:
			result = GetArea() * BAHIA_PRICE;
			break;
		case BENTGRASS:
			result = GetArea() * BENTGRASS_PRICE;
			break;
		case PERENNIAL_RYEGRASS:
			result = GetArea() * PERENNIAL_RYEGRASS_PRICE;
			break;
		case ST_AUGUSTINE:
			result = GetArea() * ST_AUGUSTINE_PRICE;
			break;
		default:
			assert(false);
			result = 0;
		}

		result /= 100;

		return static_cast<unsigned int>(result + OVERPRICE);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return static_cast<unsigned int>(GetArea() / UNIT_ROLL_AREA + OVERPRICE);
	}
}