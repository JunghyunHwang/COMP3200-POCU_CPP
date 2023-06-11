#pragma once

#include <cassert>
#include <string>

#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "DeusExMachina.h"
#include "Motorcycle.h"
#include "Person.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "Vehicle.h"

namespace assignment2
{
	void TestOfficial();

	void TestVehicleCopyByZeroPassengers();
	void TestVehicleCopyByManyPassengers();
	void TestVehicleAssignByZeroPassengers();
	void TestVehicleAssignByManyPassengers();
	void TestSelfAssign();

	void TestAirplane();
	void TestVehicleSpeed();
	void TestBoatplane();

	Person** get4PassengersMalloc();
	Person** get2PassengersMalloc();
}
