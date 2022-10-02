#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class Vehicle;

	class DeusExMachina
	{
	public:
		enum
		{
			MAX_VEHICLES_COUNT = 10
		};

		~DeusExMachina();
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina();
		DeusExMachina& operator=(const DeusExMachina& rhs);

	private:
		unsigned int mVehiclesCount;
		Vehicle* mVehicles[MAX_VEHICLES_COUNT] = { nullptr };
	};
}