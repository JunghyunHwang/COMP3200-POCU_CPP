#include <iostream>
#include <cassert>
#include "Test.h"
#include "DeusExMachina.h"

int main()
{
	assignment2::TestAirplane();
	assignment2::TestVehicleSpeed();
	assignment2::TestBoatplane();

	assignment2::DeusExMachina* dex1 = assignment2::DeusExMachina::GetInstance();
	assignment2::DeusExMachina* dex2 = assignment2::DeusExMachina::GetInstance();
	assert(dex1 == dex2);

	std::cout << "No prob" << std::endl;

	return 0;
}