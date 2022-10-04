#pragma once

#include "Vehicle.h"
#include "Airplane.h"
#include "ISailable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;

		bool Move();

		Boatplane operator+(Airplane& plane);
	};
}