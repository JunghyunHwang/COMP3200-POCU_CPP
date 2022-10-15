#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class Vehicle;

	class DeusExMachina
	{
	public:
		~DeusExMachina();
		static DeusExMachina* GetInstance();
		static void DeleteInstance();
		void Travel() const;
		void ClearVehicles();
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicleOrNull(unsigned int i);

	private:
		DeusExMachina();
		DeusExMachina(const DeusExMachina& other);
		DeusExMachina& operator=(const DeusExMachina& rhs);

	private:
		enum
		{
			MAX_VEHICLES_COUNT = 10
		};
		static DeusExMachina* mInstance;
		unsigned int mVehiclesCount;
		Vehicle* mVehicles[MAX_VEHICLES_COUNT] = { nullptr };
	};
}