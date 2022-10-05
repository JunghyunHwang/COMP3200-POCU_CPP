#include <iostream>
#include <cassert>
#include "Test.h"

using namespace assignment2;

int main()
{
	// Person* p1 = new Person("Ja", 90);
	// Person* p2 = new Person("Baro", 83);
	// Person* p3 = new Person("Seok", 76);

	// Boat b1(5);
	// b1.AddPassenger(p1);
	// b1.AddPassenger(p2);
	// b1.AddPassenger(p3);

	// Boat b2(b1);
	// assert(b2.GetPassengersCount() == 3);

	// assert(*b2.GetPassenger(0) == *p1);
	// assert(*b2.GetPassenger(1) == *p2);
	// assert(*b2.GetPassenger(2) == *p3);

	// assert(b1.GetMaxSpeed() == 20);
	// assert(b2.GetMaxSpeed() == 20);

	// TestOfficial();
	// TestBaro();
	// TestAirplane();
	// TestVehicleSpeed();
	// TestBoatplane();

	TestCreateVehicle();

	std::cout << "No prob" << std::endl;

	return 0;
}