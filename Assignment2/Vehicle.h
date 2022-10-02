#pragma once

#include <math.h>
#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		virtual ~Vehicle();
		Vehicle& operator=(const Vehicle& rhs);

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void Clear();
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalWeight() const;

	protected:
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		const Person** mPassengers;
	};
}