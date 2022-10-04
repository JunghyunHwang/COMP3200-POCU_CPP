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

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int maxFlySpeed = GetFlySpeed();
		unsigned int maxDriveSpeed = GetDriveSpeed();

		unsigned int result = maxDriveSpeed > maxFlySpeed ? maxDriveSpeed : maxFlySpeed;

		return result;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(200 * exp((-1 * static_cast<int>(GetTotalWeight()) + 800.0) / 500) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return static_cast<unsigned int>(4 * exp((-1 * static_cast<int>(GetTotalWeight()) + 400.0) / 70) + 0.5);
	}

	bool Airplane::Move()
	{
		if (mCallMoveCount % eUnitMovement::AIRPLANE_MOVEMENT != 0)
		{
			++mCallMoveCount;
			return false;
		}

		mTraveledKilometers += GetMaxSpeed();
		++mCallMoveCount;

		return true;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(boat.GetMaxPassengersCount() + mMaxPassengersCount);

		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			bp.AddPassenger(new Person(*mPassengers[i]));
		}

		Clear();

		for (size_t i = 0; i < boat.GetPassengersCount(); ++i)
		{
			bp.AddPassenger(new Person(*boat.GetPassenger(i)));
		}

		boat.Clear();

		return bp;
	}
}