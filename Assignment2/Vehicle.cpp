#include <cassert>
#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengerCount(maxPassengersCount)
		, mPassengerCount(0)
	{
		mPassengers = new const Person*[mMaxPassengerCount];
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengerCount(other.mMaxPassengerCount)
		, mPassengerCount(other.mPassengerCount)
	{
		assert(mPassengerCount <= mMaxPassengerCount);

		mPassengers = new const Person*[mMaxPassengerCount];

		for (size_t i = 0; i < mPassengerCount; ++i)
		{
			mPassengers[i] = new Person(*other.mPassengers[i]);
		}
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mPassengerCount; ++i)
		{
			delete mPassengers[i];
		}

		delete[] mPassengers;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		assert(person != nullptr);

		if (mPassengerCount >= mMaxPassengerCount)
		{
			return false;
		}

		mPassengers[mPassengerCount++] = person;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengerCount)
		{
			return false;
		}

		assert(mPassengers[i] != nullptr);

		delete mPassengers[i];
		--mPassengerCount;

		for (size_t idx = i; idx < mPassengerCount; ++idx)
		{
			mPassengers[idx] = mPassengers[idx + 1];
		}

		mPassengers[mPassengerCount] = nullptr;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengerCount;
	}

	unsigned int Vehicle::GetTotalWeight() const
	{
		unsigned int totalWeight = 0;

		for (size_t i = 0; i < mPassengerCount; ++i)
		{
			totalWeight += mPassengers[i]->GetWeight();
		}

		return totalWeight;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mPassengerCount)
		{
			return nullptr;
		}

		assert(mPassengers[i] != nullptr);

		return mPassengers[i];
	}
}