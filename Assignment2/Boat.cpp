#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int speed = 800 - 10 * GetTotalWeight();

		if (speed <= eMinSpeed::BOAT_SAIL)
		{
			return eMinSpeed::BOAT_SAIL;
		}

		return static_cast<unsigned int>(speed);
	}

	bool Boat::Move()
	{
		if (mCallMoveCount % eUnitMovement::BOAT_MOVEMENT == 2)
		{
			++mCallMoveCount;
			return false;
		}

		mTraveledKilometers += GetMaxSpeed();
		++mCallMoveCount;

		return true;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(plane.GetMaxPassengersCount() + mMaxPassengersCount);

		for (size_t i = 0; i < plane.GetPassengersCount(); ++i)
		{
			bp.AddPassenger(new Person(*plane.GetPassenger(i)));
		}

		plane.Clear();

		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			bp.AddPassenger(new Person(*mPassengers[i]));
		}

		Clear();

		return bp;
	}
}