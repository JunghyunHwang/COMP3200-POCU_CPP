#pragma once

#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();

		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;
		unsigned int GetMaxSpeed() const;
		bool Move();
	private:
		enum
		{
			MAX_PASSENGERS_COUNT = 20,
			UNIT_MOVEMENT = 6,
			MIN_SPEED = 200
		};
	};
}