#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(MAX_PASSENGERS_COUNT)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int speed = static_cast<unsigned int>(550 - GetTotalWeight() / 10.0 + 0.5);

		return (speed > MIN_SPEED ? speed : MIN_SPEED);
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>(500 * log((GetTotalWeight() + 150) / 150.0) + 30 + 0.5);
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		const unsigned int SAIL_SPEED = GetSailSpeed();
		const unsigned int DIVE_SPEED = GetDiveSpeed();

		return (SAIL_SPEED > DIVE_SPEED ? SAIL_SPEED : DIVE_SPEED);
	}

	bool UBoat::Move()
	{
		if (mCallMoveCount % UNIT_MOVEMENT > 1)
		{
			++mCallMoveCount;
			return false;
		}

		mTraveledKilometers += GetMaxSpeed();
		++mCallMoveCount;
		
		return true;
	}
}