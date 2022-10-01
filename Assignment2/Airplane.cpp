#include "Airplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengerCount)
		: Vehicle(maxPassengerCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return 200 * exp((-1 * static_cast<int>(GetTotalWeight()) + 800.0) / 500);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return 4 * exp((-1 * static_cast<int>(GetTotalWeight()) + 400.0) / 70);
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int maxFlySpeed = GetFlySpeed();
		unsigned int maxDriveSpeed = GetDriveSpeed();

		unsigned int result = maxDriveSpeed > maxFlySpeed ? maxDriveSpeed : maxFlySpeed;

		return result;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(0);
		return bp;
	}
}