#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina::DeusExMachina()
		: mVehiclesCount(0)
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		ClearVehicles();
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new DeusExMachina();
		}

		return mInstance;
	}

	void DeusExMachina::DeleteInstance()
	{
		delete mInstance;
		mInstance = nullptr;
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mVehiclesCount; ++i)
		{
			mVehicles[i]->Move();
		}
	}

	void DeusExMachina::ClearVehicles()
	{
		for (size_t i = 0; i < mVehiclesCount; ++i)
		{
			delete mVehicles[i];
			mVehicles[i] = nullptr;
		}

		mVehiclesCount = 0;
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		assert(vehicle != nullptr);

		if (mVehiclesCount >= MAX_VEHICLES_COUNT)
		{
			return false;
		}

		mVehicles[mVehiclesCount++] = vehicle;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehiclesCount)
		{
			return false;
		}
		
		assert(mVehicles[i] != nullptr);

		delete mVehicles[i];
		--mVehiclesCount;

		for (size_t j = i; j < mVehiclesCount; ++j)
		{
			mVehicles[j] = mVehicles[j + 1];
		}

		mVehicles[mVehiclesCount] = nullptr;

		return true;
	}

	const Vehicle* DeusExMachina::GetVehicleOrNull(unsigned int i) const
	{
		if (i >= mVehiclesCount)
		{
			return nullptr;
		}

		assert(mVehicles[i] != nullptr);

		return mVehicles[i];
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehiclesCount == 0)
		{
			return nullptr;
		}

		unsigned int furthestIndex = 0;
		unsigned int furthestKilometers = mVehicles[0]->GetTraveledKilometers();

		for (size_t i = 1; i < mVehiclesCount; ++i)
		{
			unsigned int tmpKilometers = mVehicles[i]->GetTraveledKilometers();

			if (tmpKilometers > furthestKilometers)
			{
				furthestKilometers = tmpKilometers;
				furthestIndex = i;
			}
		}

		return mVehicles[furthestIndex];
	}
}