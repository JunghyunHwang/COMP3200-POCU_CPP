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
			assert(cpy.GetPassengersCount() == m.GetPassengersCount());
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
			Person** p = get4PassengersMalloc();

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
			delete[] p;
		}

		// Boat
		{
			Person** p = get4PassengersMalloc();

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
			delete[] p;
		}

		// Motorcycle
		{
			Person** p = get2PassengersMalloc();

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
			assert(m.GetPassengersCount() == 1);
			assert(m.RemovePassenger(0));
			assert(m.GetPassengersCount() == 0);

			assert(cpy.GetPassengersCount() == MAX_MOTORCYCLE_NUM);
			assert(cpy.GetMaxPassengersCount() == MAX_MOTORCYCLE_NUM);
			delete[] p;
		}

		// Sedan
		{
			Person** p = get4PassengersMalloc();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
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
			delete[] p;
		}

		// Uboat
		{
			Person** p = get4PassengersMalloc();

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
			delete[] p;
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
			Person** p = get4PassengersMalloc();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = ap;
			assert(assign2.GetMaxPassengersCount() == ap.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == ap.GetPassengersCount());

			delete[] p;
		}

		// Boat
		{
			Boat assign1(MAX_PASSENGERS_NUM + 1);
			
			assign1 = b;
			assert(assign1.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == b.GetPassengersCount());

			Boat assign2(MAX_PASSENGERS_NUM);
			Person** p = get4PassengersMalloc();

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = b;
			assert(assign2.GetMaxPassengersCount() == b.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == b.GetPassengersCount());

			delete[] p;
		}

		// Motorcycle
		{
			Motorcycle assign1;
			
			assign1 = m;
			assert(assign1.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == m.GetPassengersCount());

			Motorcycle assign2;
			Person** p = get2PassengersMalloc();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = m;
			assert(assign2.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == m.GetPassengersCount());

			delete[] p;
		}

		// Sedan
		{
			Sedan assign1;
			
			assign1 = s;
			assert(assign1.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == s.GetPassengersCount());

			Sedan assign2;
			Person** p = get4PassengersMalloc();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = s;
			assert(assign2.GetMaxPassengersCount() == s.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == s.GetPassengersCount());

			delete[] p;
		}

		// UBoat
		{
			UBoat assign1;
			
			assign1 = ub;
			assert(assign1.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(assign1.GetPassengersCount() == ub.GetPassengersCount());

			UBoat assign2;
			Person** p = get4PassengersMalloc();

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(assign2.AddPassenger(p[i]));
			}

			assign2 = ub;
			assert(assign2.GetMaxPassengersCount() == ub.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == ub.GetPassengersCount());

			delete[] p;
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

		Person** p1 = get4PassengersMalloc();
		Person** p2 = get4PassengersMalloc();
		Person** p3 = get2PassengersMalloc();
		Person** p4 = get4PassengersMalloc();
		Person** p5 = get4PassengersMalloc();

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(ap.AddPassenger(p1[i]));
		}

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(b.AddPassenger(p2[i]));
		}

		for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
		{
			assert(m.AddPassenger(p3[i]));
		}

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(s.AddPassenger(p4[i]));
		}

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(ub.AddPassenger(p5[i]));
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

			assign2 = m;
			assert(assign2.GetMaxPassengersCount() == m.GetMaxPassengersCount());
			assert(assign2.GetPassengersCount() == m.GetPassengersCount());

			assert(assign2.GetPassenger(0) != m.GetPassenger(0));
			assert(assign2.GetPassenger(1) != m.GetPassenger(1));

			assert(assign2.GetPassenger(0)->GetName() == m.GetPassenger(0)->GetName());
			assert(assign2.GetPassenger(1)->GetName() == m.GetPassenger(1)->GetName());
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

		delete[] p1;
		delete[] p2;
		delete[] p3;
		delete[] p4;
		delete[] p5;
	}

	void TestSelfAssign()
	{
		const int MAX_PASSENGERS_NUM = 4;
		const int MAX_MOTORCYCLE_NUM = 2;

		Airplane ap(MAX_PASSENGERS_NUM);
		Boat b(MAX_PASSENGERS_NUM);
		Motorcycle m;
		Sedan s;
		UBoat ub;

		Person** p1 = get4PassengersMalloc();
		Person** p2 = get4PassengersMalloc();
		Person** p3 = get2PassengersMalloc();
		Person** p4 = get4PassengersMalloc();
		Person** p5 = get4PassengersMalloc();

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(ap.AddPassenger(p1[i]));
		}

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(b.AddPassenger(p2[i]));
		}

		for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
		{
			assert(m.AddPassenger(p3[i]));
		}

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(s.AddPassenger(p4[i]));
		}

		for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
		{
			assert(ub.AddPassenger(p5[i]));
		}

		// Airplane
		{
			ap = ap;

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(ap.GetPassenger(i) == p1[i]);
			}
		}

		// Boat
		{
			b = b;

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(b.GetPassenger(i) == p2[i]);
			}
		}
		
		// Motorcycle
		{
			m = m;

			for (size_t i = 0; i < MAX_MOTORCYCLE_NUM; ++i)
			{
				assert(m.GetPassenger(i) == p3[i]);
			}
		}

		// Sedan
		{
			s = s;

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(s.GetPassenger(i) == p4[i]);
			}
		}

		// UBoat
		{
			ub = ub;

			for (size_t i = 0; i < MAX_PASSENGERS_NUM; ++i)
			{
				assert(ub.GetPassenger(i) == p5[i]);
			}
		}

		delete[] p1;
		delete[] p2;
		delete[] p3;
		delete[] p4;
		delete[] p5;
	}
	
	Person** get4PassengersMalloc()
	{
		Person* p1 = new Person("Ja", 84);
		Person* p2 = new Person("Andrew", 85);
		Person* p3 = new Person("John", 88);
		Person* p4 = new Person("Alex", 73);

		Person** passengers = new Person * [4] { p1, p2, p3, p4 };

		return passengers;
	}

	Person** get2PassengersMalloc()
	{
		Person* p1 = new Person("Ja", 84);
		Person* p2 = new Person("Andrew", 85);
		
		Person** passengers = new Person * [2] { p1, p2 };

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
