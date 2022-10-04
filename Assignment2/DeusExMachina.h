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
		static void DeleteInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicleOrNull(unsigned int i);

	private:
		DeusExMachina();
		DeusExMachina(const DeusExMachina& other);
		DeusExMachina& operator=(const DeusExMachina& rhs);

	private:
		static DeusExMachina* mInstance;
		unsigned int mVehiclesCount;
		Vehicle* mVehicles[MAX_VEHICLES_COUNT] = { nullptr };
	};
}