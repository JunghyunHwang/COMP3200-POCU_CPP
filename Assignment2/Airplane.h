#pragma once

#include "Vehicle.h"
#include "Boat.h"
#include "IFlyable.h"
#include "IDrivable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;

		bool Move();

		Boatplane operator+(Boat& boat);
	private:
		enum
		{
			UNIT_MOVEMENT = 4
		};
	};
}

