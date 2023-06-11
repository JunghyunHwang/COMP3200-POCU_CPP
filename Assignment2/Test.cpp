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

	void TestVehicleCopyByZeroPassengers()
	{
		const int MAX_PASSENGERS_NUM = 4;
		
		Airplane ap(MAX_PASSENGERS_NUM);
		Boat b(MAX_PASSENGERS_NUM);
		Motorcycle m;
		Sedan s;
		UBoat ub;

		// Airplane
		{
			Airplane cpy(ap);
			assert(cpy.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == ap.GetPassengersCount());
		}

		// Boat
		{
			Boat cpy(b);
			assert(cpy.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == b.GetPassengersCount());
		}

		// Motorcycle
		{
			Motorcycle cpy(m);
			assert(cpy.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == m.GetMaxPassengersCount());
		}

		// Sedan
		{
			Sedan cpy(s);
			assert(cpy.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == s.GetPassengersCount());
		}

		// Uboat
		{
			UBoat cpy(ub);
			assert(cpy.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == ub.GetPassengersCount());
		}
	}

	void TestVehicleCopyByManyPassengers()
	{
		const int MAX_PASSENGERS_NUM = 4;
		const int MAX_MOTORCYCLE_NUM = 2;
		
		Airplane ap(MAX_PASSENGERS_NUM);
		Boat b(MAX_PASSENGERS_NUM);
		Motorcycle m;
		Sedan s;
		UBoat ub;

		// Airplane
		{
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(ap.AddPassenger(p[i]));
			}

			Airplane cpy(ap);
			assert(cpy.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == ap.GetPassengersCount());
			
			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(ap.GetPassenger(i) != cpy.GetPassenger(i));
			}

			assert(ap.RemovePassenger(0));
			assert(ap.GetPassengersCount() == 3);
			assert(ap.RemovePassenger(2));
			assert(ap.GetPassengersCount() == 2);

			assert(ap.RemovePassenger(0));
			assert(ap.RemovePassenger(0));

			assert(cpy.GetPassengersCount() == MAX_PASSENGERS_NUM);
			assert(cpy.GetMaxPassengersCount() == MAX_PASSENGERS_NUM);
		}

		// Boat
		{
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(b.AddPassenger(p[i]));
			}

			Boat cpy(b);
			assert(cpy.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == b.GetPassengersCount());
			
			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(b.GetPassenger(i) != cpy.GetPassenger(i));
			}

			assert(b.RemovePassenger(0));
			assert(b.GetPassengersCount() == 3);
			assert(b.RemovePassenger(2));
			assert(b.GetPassengersCount() == 2);

			assert(b.RemovePassenger(0));
			assert(b.RemovePassenger(0));

			assert(cpy.GetPassengersCount() == MAX_PASSENGERS_NUM);
			assert(cpy.GetMaxPassengersCount() == MAX_PASSENGERS_NUM);
		}

		// Motorcycle
		{
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(m.AddPassenger(p[i]));
			}

			Motorcycle cpy(m);
			assert(cpy.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == m.GetPassengersCount());
			
			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(m.GetPassenger(i) != cpy.GetPassenger(i));
			}

			assert(m.RemovePassenger(0));
			assert(m.GetPassengersCount() == 3);
			assert(m.RemovePassenger(2));
			assert(m.GetPassengersCount() == 2);

			assert(m.RemovePassenger(0));
			assert(m.RemovePassenger(0));

			assert(cpy.GetPassengersCount() == MAX_MOTORCYCLE_NUM);
			assert(cpy.GetMaxPassengersCount() == MAX_MOTORCYCLE_NUM);
		}

		// Sedan
		{
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(s.AddPassenger(p[i]));
			}

			Sedan cpy(s);
			assert(cpy.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == s.GetPassengersCount());
			
			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(s.GetPassenger(i) != cpy.GetPassenger(i));
			}

			assert(s.RemovePassenger(0));
			assert(s.GetPassengersCount() == 3);
			assert(s.RemovePassenger(2));
			assert(s.GetPassengersCount() == 2);

			assert(s.RemovePassenger(0));
			assert(s.RemovePassenger(0));

			assert(cpy.GetPassengersCount() == MAX_PASSENGERS_NUM);
			assert(cpy.GetMaxPassengersCount() == MAX_PASSENGERS_NUM);
		}

		// Uboat
		{
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(ub.AddPassenger(p[i]));
			}

			UBoat cpy(ub);
			assert(cpy.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(cpy.GetPassengersCount() == ub.GetPassengersCount());
			
			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(ub.GetPassenger(i) != cpy.GetPassenger(i));
			}

			assert(ub.RemovePassenger(0));
			assert(ub.GetPassengersCount() == 3);
			assert(ub.RemovePassenger(2));
			assert(ub.GetPassengersCount() == 2);

			assert(ub.RemovePassenger(0));
			assert(ub.RemovePassenger(0));

			assert(cpy.GetPassengersCount() == MAX_PASSENGERS_NUM);
			assert(cpy.GetMaxPassengersCount() == MAX_PASSENGERS_NUM);
		}
	}

	void TestVehicleAssignByZeroPassengers()
	{
		const int MAX_PASSENGERS_NUM = 4;
		const int MAX_MOTORCYCLE_NUM = 2;
		
		Airplane ap(MAX_PASSENGERS_NUM);
		Boat b(MAX_PASSENGERS_NUM);
		Motorcycle m;
		Sedan s;
		UBoat ub;

		// Airplane
		{
			Airplane assign1(MAX_PASSENGERS_NUM + 1);
			
			assign1 = ap;
			assert(assign1.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == ap.GetPassengersCount());

			Airplane assign2(MAX_PASSENGERS_NUM);
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = ap;
			assert(assign2.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == ap.GetPassengersCount());

			// All Person objects within variable p have been released
		}

		// Boat
		{
			Boat assign1(MAX_PASSENGERS_NUM + 1);
			
			assign1 = b;
			assert(assign1.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == b.GetPassengersCount());

			Boat assign2(MAX_PASSENGERS_NUM);
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = b;
			assert(assign2.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == b.GetPassengersCount());
			// All Person objects within variable p have been released
		}

		// Motorcycle
		{
			Motorcycle assign1;
			
			assign1 = m;
			assert(assign1.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == m.GetPassengersCount());

			Motorcycle assign2;
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = m;
			assert(assign2.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == m.GetPassengersCount());
		}

		// Sedan
		{
			Sedan assign1;
			
			assign1 = s;
			assert(assign1.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == s.GetPassengersCount());

			Sedan assign2;
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = s;
			assert(assign2.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == s.GetPassengersCount());
			// All Person objects within variable p have been released
		}

		// UBoat
		{
			UBoat assign1;
			
			assign1 = ub;
			assert(assign1.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == ub.GetPassengersCount());

			UBoat assign2;
			Person** p = get4Passengers();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = ub;
			assert(assign2.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == ub.GetPassengersCount());
			// All Person objects within variable p have been released
		}
	}

	void TestVehicleAssignByManyPassengers()
	{
		const int MAX_PASSENGERS_NUM = 4;
		const int MAX_MOTORCYCLE_NUM = 2;
		
		Airplane ap(MAX_PASSENGERS_NUM);
		Boat b(MAX_PASSENGERS_NUM);
		Motorcycle m;
		Sedan s;
		UBoat ub;

		Person** p = get4Passengers();

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			ap.AddPassenger(p[i]);
		}

		p = get4Passengers();
		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			b.AddPassenger(p[i]);
		}

		p = get4Passengers();
		for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
		{
			m.AddPassenger(p[i]);
		}

		p = get4Passengers();
		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			s.AddPassenger(p[i]);
		}

		p = get4Passengers();
		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			ub.AddPassenger(p[i]);
		}

		// Airplane
		{
			Airplane assign1(MAX_PASSENGERS_NUM);
			assign1 = ap;
			assert(assign1.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == ap.GetPassengersCount());

			Airplane assign2(MAX_PASSENGERS_NUM);
			
			assign2.AddPassenger(new Person("Charlie", 52));
			assign2.AddPassenger(new Person("Tyler", 52));
			assign2.AddPassenger(new Person("Ruel", 52));

			assign2 = ap;
			assert(assign2.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == ap.GetPassengersCount());

			assert(assign2.GetPassenger(0) != ap.GetPassenger(0));
			assert(assign2.GetPassenger(1) != ap.GetPassenger(1));
			assert(assign2.GetPassenger(2) != ap.GetPassenger(2));
			assert(assign2.GetPassenger(3) != ap.GetPassenger(3));

			assert(assign2.GetPassenger(0)->GetName() == ap.GetPassenger(0)->GetName());
			assert(assign2.GetPassenger(1)->GetName() == ap.GetPassenger(1)->GetName());
			assert(assign2.GetPassenger(2)->GetName() == ap.GetPassenger(2)->GetName());
			assert(assign2.GetPassenger(3)->GetName() == ap.GetPassenger(3)->GetName());
		}

		// Boat
		{
			Boat assign1(MAX_PASSENGERS_NUM);
			assign1 = b;
			assert(assign1.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == b.GetPassengersCount());

			Boat assign2(MAX_PASSENGERS_NUM);
			
			assign2.AddPassenger(new Person("Charlie", 52));
			assign2.AddPassenger(new Person("Tyler", 52));
			assign2.AddPassenger(new Person("Ruel", 52));

			assign2 = b;
			assert(assign2.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == b.GetPassengersCount());

			assert(assign2.GetPassenger(0) != b.GetPassenger(0));
			assert(assign2.GetPassenger(1) != b.GetPassenger(1));
			assert(assign2.GetPassenger(2) != b.GetPassenger(2));
			assert(assign2.GetPassenger(3) != b.GetPassenger(3));

			assert(assign2.GetPassenger(0)->GetName() == b.GetPassenger(0)->GetName());
			assert(assign2.GetPassenger(1)->GetName() == b.GetPassenger(1)->GetName());
			assert(assign2.GetPassenger(2)->GetName() == b.GetPassenger(2)->GetName());
			assert(assign2.GetPassenger(3)->GetName() == b.GetPassenger(3)->GetName());
		}

		// Motorcycle
		{
			Motorcycle assign1;
			assign1 = m;
			assert(assign1.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == m.GetPassengersCount());

			Motorcycle assign2;
			
			assign2.AddPassenger(new Person("Charlie", 52));
			assign2.AddPassenger(new Person("Tyler", 52));
			assign2.AddPassenger(new Person("Ruel", 52));

			assign2 = m;
			assert(assign2.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == m.GetPassengersCount());

			assert(assign2.GetPassenger(0) != m.GetPassenger(0));
			assert(assign2.GetPassenger(1) != m.GetPassenger(1));
			assert(assign2.GetPassenger(2) != m.GetPassenger(2));
			assert(assign2.GetPassenger(3) != m.GetPassenger(3));

			assert(assign2.GetPassenger(0)->GetName() == m.GetPassenger(0)->GetName());
			assert(assign2.GetPassenger(1)->GetName() == m.GetPassenger(1)->GetName());
			assert(assign2.GetPassenger(2)->GetName() == m.GetPassenger(2)->GetName());
			assert(assign2.GetPassenger(3)->GetName() == m.GetPassenger(3)->GetName());
		}

		// Sedan
		{
			Sedan assign1;
			assign1 = s;
			assert(assign1.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == s.GetPassengersCount());

			Sedan assign2;
			
			assign2.AddPassenger(new Person("Charlie", 52));
			assign2.AddPassenger(new Person("Tyler", 52));
			assign2.AddPassenger(new Person("Ruel", 52));

			assign2 = s;
			assert(assign2.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == s.GetPassengersCount());

			assert(assign2.GetPassenger(0) != s.GetPassenger(0));
			assert(assign2.GetPassenger(1) != s.GetPassenger(1));
			assert(assign2.GetPassenger(2) != s.GetPassenger(2));
			assert(assign2.GetPassenger(3) != s.GetPassenger(3));

			assert(assign2.GetPassenger(0)->GetName() == s.GetPassenger(0)->GetName());
			assert(assign2.GetPassenger(1)->GetName() == s.GetPassenger(1)->GetName());
			assert(assign2.GetPassenger(2)->GetName() == s.GetPassenger(2)->GetName());
			assert(assign2.GetPassenger(3)->GetName() == s.GetPassenger(3)->GetName());
		}

		// UBoat
		{
			UBoat assign1;
			assign1 = ub;
			assert(assign1.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == ub.GetPassengersCount());

			UBoat assign2;
			
			assign2.AddPassenger(new Person("Charlie", 52));
			assign2.AddPassenger(new Person("Tyler", 52));
			assign2.AddPassenger(new Person("Ruel", 52));

			assign2 = ub;
			assert(assign2.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == ub.GetPassengersCount());

			assert(assign2.GetPassenger(0) != ub.GetPassenger(0));
			assert(assign2.GetPassenger(1) != ub.GetPassenger(1));
			assert(assign2.GetPassenger(2) != ub.GetPassenger(2));
			assert(assign2.GetPassenger(3) != ub.GetPassenger(3));

			assert(assign2.GetPassenger(0)->GetName() == ub.GetPassenger(0)->GetName());
			assert(assign2.GetPassenger(1)->GetName() == ub.GetPassenger(1)->GetName());
			assert(assign2.GetPassenger(2)->GetName() == ub.GetPassenger(2)->GetName());
			assert(assign2.GetPassenger(3)->GetName() == ub.GetPassenger(3)->GetName());
		}
	}
	
	Person** get4Passengers()
	{
		Person* p1 = new Person("Ja", 84);
		Person* p2 = new Person("Andrew", 85);
		Person* p3 = new Person("John", 88);
		Person* p4 = new Person("Alex", 73);

		Person* passengers[4] = { p1, p2, p3, p4 };

		return passengers;
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
