#pragma once

#include <math.h>
#include <cassert>

#include "Person.h"
#include "DeusExMachina.h"

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
		virtual void Move() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void Clear();
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalWeight() const;
		unsigned int GetTraveledKilometers() const;

	protected:
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		unsigned int mCallMoveCount;
		unsigned int mTraveledKilometers;
		const Person** mPassengers;
	};
}