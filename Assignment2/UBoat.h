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
		const static unsigned int MAX_PASSENGERS_COUNT;
		const static unsigned int UNIT_MOVEMENT;
		const static unsigned int MIN_SPEED;
	};
}