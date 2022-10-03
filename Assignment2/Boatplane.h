#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();
		
		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;

		bool Move();

	private:
		const static unsigned int MIN_SPEED = 20;
		const static unsigned int UNIT_MOVEMENT = 4;
	};
}