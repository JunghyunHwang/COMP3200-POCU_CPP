#include "Test.h"

namespace assignment2
{
	void TestOfficial()
	{
		Person* p = new Person("Bob", 85);

		assert(p->GetName() == std::string("Bob"));
		assert(p->GetWeight() == 85);

		Person* p2 = new Person("James", 75);
		Person* p3 = new Person("Tina", 52);

		Person* p4 = new Person("Peter", 78);
		Person* p5 = new Person("Jane", 48);
		Person* p6 = new Person("Steve", 88);

		Airplane a(5);
		a.AddPassenger(p);
		a.AddPassenger(p2);
		a.AddPassenger(p3);

		assert(a.GetMaxPassengersCount() == 5);
		assert(a.GetPassengersCount() == 3);
		assert(a.GetPassenger(1) == p2);
		assert(a.GetFlySpeed() == 648);
		assert(a.GetDriveSpeed() == 59);
		assert(a.GetMaxSpeed() == 648);

		Boat b(5);
		b.AddPassenger(p4);
		b.AddPassenger(p5);
		b.AddPassenger(p6);

		Boatplane bp = a + b;

		assert(bp.GetPassengersCount() == 6);
		assert(bp.GetMaxPassengersCount() == 10);

		assert(a.GetPassengersCount() == 0);
		assert(b.GetPassengersCount() == 0);

		DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
		DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

		bool bSame = deusExMachina1 == deusExMachina2;
		assert(bSame);

		Airplane* airplane = new Airplane(5);
		Boat* boat = new Boat(5);
		Boatplane* boatplane = new Boatplane(5);
		Motorcycle* motorcycle = new Motorcycle();
		Sedan* sedan = new Sedan();
		Sedan* sedan2 = new Sedan();
		UBoat* uboat = new UBoat();

		bool bAdded = sedan2->AddTrailer(new Trailer(50));
		assert(bAdded);

		bAdded = sedan2->AddTrailer(new Trailer(60));
		assert(!bAdded);

		bAdded = deusExMachina1->AddVehicle(airplane);
		assert(bAdded);

		deusExMachina1->AddVehicle(boat);
		deusExMachina1->AddVehicle(boatplane);
		deusExMachina1->AddVehicle(motorcycle);
		deusExMachina1->AddVehicle(sedan);
		deusExMachina1->AddVehicle(sedan2);
		deusExMachina1->AddVehicle(uboat);
		deusExMachina1->AddVehicle(new Airplane(5));
		deusExMachina1->AddVehicle(new Airplane(5));
		deusExMachina1->AddVehicle(new Airplane(5));

		bAdded = deusExMachina1->AddVehicle(new Airplane(5));

		assert(!bAdded);

		deusExMachina1->RemoveVehicle(9);
		deusExMachina1->RemoveVehicle(8);
		bool bRemoved = deusExMachina1->RemoveVehicle(7);
		assert(bRemoved);

		bRemoved = deusExMachina1->RemoveVehicle(9);
		assert(!bRemoved);

		deusExMachina1->Travel(); // 모든 운송 수단이 이동
		deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
		deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
		deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
		deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
		deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
		deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
		deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
		deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
		deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
		deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
		deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

		assert(deusExMachina1->GetFurthestTravelled() == boat);
	}

	void TestAirplane()
	{
		Person* p1 = new Person("Bob", 85);
		Person* p2 = new Person("James", 75);
		Person* p3 = new Person("Tina", 52);
		Person* people1[3] =  { p1, p2, p3 };

		Airplane a1(5);
		assert(a1.AddPassenger(p1));
		assert(a1.AddPassenger(p2));
		assert(a1.AddPassenger(p3));

		for (size_t i = 0; i < a1.GetPassengersCount(); ++i)
		{
			assert(a1.GetPassenger(i)->GetName() == people1[i]->GetName());
		}

		Person* p4 = new Person("Ja", 89);
		Person* p5 = new Person("Baro", 82);
		Person* p6 = new Person("Seok", 78);
		Person* people2[3] =  { p4, p5, p6 };

		Airplane a2(5);
		assert(a2.AddPassenger(p4));
		assert(a2.AddPassenger(p5));
		assert(a2.AddPassenger(p6));

		for (size_t i = 0; i < a2.GetPassengersCount(); ++i)
		{
			assert(a2.GetPassenger(i)->GetName() == people2[i]->GetName());
		}

		Airplane a3 = a2;
		assert(a3.GetMaxPassengersCount() == a2.GetMaxPassengersCount());

		for (size_t i = 0; i < a3.GetPassengersCount(); ++i)
		{
			assert(a3.GetPassenger(i)->GetName() == a2.GetPassenger(i)->GetName());
		}

		a2.RemovePassenger(0);
		a2.RemovePassenger(0);
		assert(a3.GetPassengersCount() != a2.GetPassengersCount());

		a3 = a1;
		assert(a3.GetMaxPassengersCount() == a1.GetMaxPassengersCount());

		for (size_t i = 0; i < a3.GetPassengersCount(); ++i)
		{
			assert(a3.GetPassenger(i)->GetName() == a1.GetPassenger(i)->GetName());
		}
	}

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
		
		assert(bp.GetFlySpeed() == 192);
		assert(bp.GetSailSpeed() == 76);
		assert(bp.GetMaxSpeed() == 192);
	}
}
