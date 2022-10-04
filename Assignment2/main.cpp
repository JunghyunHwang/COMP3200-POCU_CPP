#include <iostream>
#include <cassert>
#include "Test.h"

using namespace assignment2;

int main()
{
	Person* p1 = new Person("Ja", 90);
	Person* p2 = new Person("Baro", 83);
	Person* p3 = new Person("Seok", 76);

	Airplane a1(5);
	a1.AddPassenger(p1);
	a1.AddPassenger(p2);
	a1.AddPassenger(p3);

	Airplane a2(a1);
	assert(a2.GetPassengersCount() == 3);

	assert(*a2.GetPassenger(0) == *p1);
	assert(*a2.GetPassenger(1) == *p2);
	assert(*a2.GetPassenger(2) == *p3);

	TestOfficial();
	TestBaro();
	TestAirplane();
	TestVehicleSpeed();
	TestBoatplane();

	std::cout << "No prob" << std::endl;

	return 0;
}