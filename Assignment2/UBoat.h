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
		void Move();

	private:
		const static unsigned int MAX_PASSENGERS_COUNT = 50;
		const static unsigned int MIN_SPEED = 200;
		const static unsigned int UNIT_MOVEMENT = 6;
	};
}