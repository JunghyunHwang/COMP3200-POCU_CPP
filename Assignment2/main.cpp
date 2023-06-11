#include <iostream>
#include <cassert>
#include "Test.h"

using namespace assignment2;

int main()
{
	TestOfficial();
	TestVehicleCopyByZeroPassengers();
	TestVehicleCopyByManyPassengers();
	TestVehicleAssignByZeroPassengers();
	TestVehicleAssignByManyPassengers();
	TestSelfAssign();

	std::cout << "No prob" << std::endl;

	return 0;
}