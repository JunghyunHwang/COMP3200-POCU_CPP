#include "Test.h"

namespace assignment2
{
	void TestVehicleSpeed()
	{
		Person* p1 = new Person("Bob", 85);
		Person* p2 = new Person("James", 75);
		Person* p3 = new Person("Tina", 52);

		Airplane a(5);
		a.AddPassenger(p1);
		a.AddPassenger(p2);
		a.AddPassenger(p3);

		assert(a.GetMaxSpeed() == 648);
	}

	void TestBoatplane()
	{
		Person* p1 = new Person("Bob", 85);
		Person* p2 = new Person("James", 75);
		Person* p3 = new Person("Tina", 52);

		Person* p4 = new Person("Peter", 78);
		Person* p5 = new Person("Jane", 48);
		Person* p6 = new Person("Steve", 88);

		std::string names[10];
		names[0] = "Bob";
		names[1] = "James";
		names[2] = "Tina";
		names[3] = "Peter";
		names[4] = "Jane";
		names[5] = "Steve";

		Airplane a(5);
		a.AddPassenger(p1);
		a.AddPassenger(p2);
		a.AddPassenger(p3);

		Boat b(5);
		b.AddPassenger(p4);
		b.AddPassenger(p5);
		b.AddPassenger(p6);

		Boatplane bp = a + b;
		
		for (size_t i = 0; i < 6; ++i)
		{
			assert(bp.GetPassenger(i)->GetName() == names[i]);
		}
		
		assert(bp.GetFlySpeed() == 191);
		assert(bp.GetSailSpeed() == 75);
		assert(bp.GetMaxSpeed() == 191);
	}
}
