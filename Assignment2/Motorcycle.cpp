#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(MAX_PASSENGERS_COUNT)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		const unsigned int TOTAL_WEIGHT = GetTotalWeight();
		unsigned int speed = pow(-1 * (TOTAL_WEIGHT / 15.0), 3) + TOTAL_WEIGHT * 2 + 400 + 0.5;
		
		return (speed > MIN_SPEED ? speed : MIN_SPEED);
	}

	void Motorcycle::Move()
	{
		if (mCallMoveCount % UNIT_MOVEMENT == 5)
		{
			++mCallMoveCount;
			return;
		}

		mTraveledKilometers += GetMaxSpeed();
		++mCallMoveCount;
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}