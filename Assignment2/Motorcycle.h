#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		bool Move();

	private:
		enum
		{
			MAX_PASSENGERS_COUNT = 2,
			UNIT_MOVEMENT = 4,
			MIN_SPEED = 20
		};
	};
}