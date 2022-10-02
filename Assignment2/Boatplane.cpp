#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		return (flySpeed > sailSpeed ? flySpeed : sailSpeed);
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		return 150 * exp((-1 * static_cast<int>(GetTotalWeight()) + 500.0) / 300);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int speed = 800 - 1.7 * GetTotalWeight();

		return (speed > MIN_SPEED ? speed : MIN_SPEED);
	}

	void Boatplane::Move()
	{
		if (mCallMoveCount % UNIT_MOVEMENT != 0)
		{
			++mCallMoveCount;
			return;
		}

		mTraveledKilometers += GetMaxSpeed();
		++mCallMoveCount;
	}
}