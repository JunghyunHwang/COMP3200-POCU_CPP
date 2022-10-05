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
		const static unsigned int MAX_PASSENGERS_COUNT;
		const static unsigned int UNIT_MOVEMENT;
		const static unsigned int MIN_SPEED;
	};
}