#pragma once

#include <math.h>
#include "Person.h"

namespace assignment2
{
	enum
	{
		MIN_SAIL_SPEED = 20
	};

	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void Clear();
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalWeight() const;

	protected:
		const unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		const Person** mPassengers;
	};
}