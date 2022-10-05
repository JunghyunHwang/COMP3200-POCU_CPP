#include "Test.h"
#define STR(name) #name

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

		assert(deusExMachina1->GetFurthestTravelled() == airplane);

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
	
	void TestCreateVehicle()
	{
		const unsigned int VEHICLE_COUNT = 7;

		Person* p1 = new Person("Bob", 85);
		Person* p2 = new Person("James", 75);
		Person* p3 = new Person("Tina", 52);
		Person* p4 = new Person("Ja", 89);
		Person* p5 = new Person("Baro", 82);
		Person* p6 = new Person("Seok", 78);
		Person* p7 = new Person("Jamm", 90);

		Person* people[7] = { p1, p2, p3, p4, p5, p6, p7 };

		Airplane* a = new Airplane(3);
		Boat* b = new Boat(3);
		Boatplane* bp = new Boatplane(3);
		Motorcycle* m = new Motorcycle();
		Sedan* s1 = new Sedan();
		Sedan* s2 = new Sedan();
		Trailer* t = new Trailer(250);
		UBoat* ub = new UBoat();
		Vehicle* vehicles1[7] = { a, b, bp, m, s1, s2, ub };
		s2->AddTrailer(t);

		a->AddPassenger(p1);
		b->AddPassenger(p2);
		bp->AddPassenger(p3);
		m->AddPassenger(p4);
		s1->AddPassenger(p5);
		s2->AddPassenger(p6);
		ub->AddPassenger(p7);

		Airplane* a2 = new Airplane(*a);
		Boat* b2 = new Boat(*b);
		Boatplane* bp2 = new Boatplane(*bp);
		Motorcycle* m2 = new Motorcycle(*m);
		Sedan* s3 = new Sedan(*s1);
		Sedan* s4 = new Sedan(*s2);
		Trailer* t2 = new Trailer(*t);
		UBoat* ub2 = new UBoat(*ub);
		Vehicle* vehicles2[7] = { a2, b2, bp2, m2, s3, s4, ub2 };

		for (size_t i = 0; i < VEHICLE_COUNT; ++i)
		{
			assert(vehicles1[i] != vehicles2[i]);
			assert(vehicles1[i]->GetPassenger(0) != vehicles2[i]->GetPassenger(0));
			assert(*vehicles1[i]->GetPassenger(0) == *vehicles2[i]->GetPassenger(0));
		}

		Airplane* a3 = a2;
		Boat* b3 = b2;
		Boatplane* bp3 = bp2;
		Motorcycle* m3 = m2;
		Sedan* s5 = s3;
		Sedan* s6 = s4;
		Trailer* t3 = t2;
		UBoat* ub3 = ub2;
		Vehicle* vehicles3[7] = { a3, b3, bp3, m3, s5, s6, ub3 };

		for (size_t i = 0; i < VEHICLE_COUNT; ++i)
		{
			assert(vehicles2[i] != vehicles3[i]);
			assert(vehicles2[i]->GetPassenger(0) != vehicles3[i]->GetPassenger(0));
			assert(*vehicles2[i]->GetPassenger(0) == *vehicles3[i]->GetPassenger(0));
		}

		for (size_t i = 0; i < VEHICLE_COUNT; ++i)
		{
			delete vehicles1[i];
			delete vehicles2[i];
			delete vehicles3[i];
		}
	}

	void TestBaro()
	{
		DeusExMachina::DeleteInstance();
		DeusExMachina* d = DeusExMachina::GetInstance();

		uint32_t traveledDistanceArr[7][13] =
		{
			{ 1213, 1213, 1213, 1213, 2426, 2426, 2426, 2426, 3639, 3639, 3639, 3639, 4852 },
			{ 800, 1600, 1600, 2400, 3200, 3200, 4000, 4800, 4800, 5600, 6400, 6400, 7200 },
			{ 800, 800, 800, 800, 1600, 1600, 1600, 1600, 2400, 2400, 2400, 2400, 3200 },
			{ 400, 800, 1200, 1600, 2000, 2000, 2400, 2800, 3200, 3600, 4000, 4000, 4400 },
			{ 480, 960, 1440, 1920, 2400, 2400, 2880, 3360, 3840, 4320, 4800, 4800, 5280 },
			{ 480, 960, 1440, 1920, 2400, 2400, 2400, 2880, 3360, 3840, 4320, 4800, 4800 },
			{ 550, 1100, 1100, 1100, 1100, 1100, 1650, 2200, 2200, 2200, 2200, 2200, 2750 }
		};

		Airplane* t1 = new Airplane(2);
		Boat* t2 = new Boat(2);
		Boatplane* t3 = new Boatplane(2);
		Motorcycle* t4 = new Motorcycle();
		Sedan* t5 = new Sedan();
		Sedan* t6 = new Sedan();
		t6->AddTrailer(new Trailer(1));
		UBoat* t7 = new UBoat();

		Vehicle* vArr[7] = { t1, t2, t3, t4, t5, t6, t7 };
				
		for (size_t j = 0; j < 7; ++j)
		{
			d->AddVehicle(vArr[j]);
			for (size_t i = 0; i < 13; ++i)
			{
				d->Travel();
				assert(traveledDistanceArr[j][i] == d->GetVehicleOrNull(0)->GetTraveledKilometers());
			}

			d->RemoveVehicle(0);
		}
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
