#include <cassert>
#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
	{
		mPassengers = new const Person*[mMaxPassengersCount];
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
	{
		mPassengers = new const Person*[mMaxPassengersCount];

		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			mPassengers[i] = new Person(*other.mPassengers[i]);
		}
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			delete mPassengers[i];
		}

		delete[] mPassengers;
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		Clear();
		delete[] mPassengers;

		mMaxPassengersCount = rhs.mMaxPassengersCount;
		mPassengersCount = rhs.mPassengersCount;

		mPassengers = new const Person*[mMaxPassengersCount];

		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			mPassengers[i] = new Person(*rhs.mPassengers[i]);
		}

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		assert(person != nullptr);

		if (mPassengersCount >= mMaxPassengersCount)
		{
			return false;
		}

		mPassengers[mPassengersCount++] = person;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengersCount)
		{
			return false;
		}

		assert(mPassengers[i] != nullptr);

		delete mPassengers[i];
		--mPassengersCount;

		for (size_t idx = i; idx < mPassengersCount; ++idx)
		{
			mPassengers[idx] = mPassengers[idx + 1];
		}

		mPassengers[mPassengersCount] = nullptr;

		return true;
	}

	void Vehicle::Clear()
	{
		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			delete mPassengers[i];
		}

		mPassengersCount = 0;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetTotalWeight() const
	{
		unsigned int totalWeight = 0;

		for (size_t i = 0; i < mPassengersCount; ++i)
		{
			totalWeight += mPassengers[i]->GetWeight();
		}

		return totalWeight;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mPassengersCount)
		{
			return nullptr;
		}

		assert(mPassengers[i] != nullptr);

		return mPassengers[i];
	}
}