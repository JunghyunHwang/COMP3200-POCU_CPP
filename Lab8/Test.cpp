#include "Test.h"

namespace lab8
{
	void TestOfficial()
	{
		int i1 = 23;
		int i2 = 25;
		int i3 = 10;
		int i4 = -4;
		int i5 = 70;

		FixedVector<int, 33> iv;

		assert(iv.GetCapacity() == 33);

		iv.Add(i1);
		iv.Add(i2);
		iv.Add(i3);
		iv.Add(i4);

		assert(iv.GetSize() == 4);
		assert(iv.GetIndex(i2) == 1);
		assert(iv.Get(1) == i2);
		assert(iv[1] == i2);

		bool bRemoved = iv.Remove(i5);
		assert(!bRemoved);
		assert(iv.GetSize() == 4);

		bRemoved = iv.Remove(i2);
		assert(bRemoved);
		assert(iv.GetSize() == 3);
		assert(iv.GetIndex(i2) == -1);

		FixedVector<bool, 10> v;

		assert(v.GetCapacity() == 10);

		v.Add(true);
		v.Add(true);
		v.Add(true);
		v.Add(true);
		v.Add(false);
		v.Add(false);
		v.Add(true);

		assert(v.GetSize() == 7);
		assert(v.Get(0));
		assert(v.Get(1));
		assert(v.Get(2));
		assert(v.Get(3));
		assert(!v.Get(4));
		assert(!v.Get(5));
		assert(v.Get(6));

		v.Remove(false);

		assert(v.GetSize() == 6);
		assert(!v.Get(4));
		assert(v.Get(5));

		v.Remove(false);

		assert(v.GetSize() == 5);

		for (size_t i = 0; i < v.GetSize(); i++)
		{
			assert(v[i]);
		}

		v.Remove(true);

		assert(v.GetSize() == 4);

		for (size_t i = 0; i < v.GetSize(); i++)
		{
			assert(v[i]);
		}

		FixedVector<bool, 65> v1;

		for (int i = 0; i < 65; i++)
		{
			v1.Add(false);
		}

		assert(v1.Add(true) == false);
		assert(v1.GetSize() == 65);
		assert(v1.GetIndex(true) == -1);
	}

	void TestWiki1()
	{
		int integerArray1[] = { 23, 25, 10, -4, 70 };
		enum { INTEGER_VECTOR1_SIZE = 4 };

		FixedVector<int, 4> integerVector1;

		assert(integerVector1.GetCapacity() == INTEGER_VECTOR1_SIZE);
		assert(integerVector1.GetSize() == 0);
		std::cout << "Test FixedVector constructor: PASS" << std::endl;

		assert(integerVector1.Add(integerArray1[0]) == true);
		assert(integerVector1.Add(integerArray1[1]) == true);
		assert(integerVector1.Add(integerArray1[2]) == true);
		assert(integerVector1.Add(integerArray1[3]) == true);
		assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
		std::cout << "Test FixedVector Add(): PASS" << std::endl;
		assert(integerVector1.Add(integerArray1[4]) == false);
		assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
		std::cout << "Test FixedVector Add() - over array range: PASS" << std::endl;

		integerVector1.Add(integerArray1[0]);
		integerVector1.Add(integerArray1[1]);
		integerVector1.Add(integerArray1[2]);
		integerVector1.Add(integerArray1[3]);
		assert(integerVector1.GetIndex(integerArray1[1]) == 1);
		std::cout << "Test FixedVector GetIndex(): PASS" << std::endl;
		assert(integerVector1.Get(1) == integerArray1[1]);
		std::cout << "Test FixedVector Get(): PASS" << std::endl;
		assert(integerVector1[1] == integerArray1[1]);
		std::cout << "Test FixedVector operator[](): PASS" << std::endl;
		integerVector1[0] = integerArray1[1];
		assert(integerVector1[0] == integerArray1[1]);
		integerVector1[0] = integerArray1[0];
		assert(integerVector1[0] == integerArray1[0]);
		std::cout << "Test FixedVector operator[]() - return reference: PASS" << std::endl;

		for (size_t i = 0; i < INTEGER_VECTOR1_SIZE; ++i)
		{
			assert(integerVector1.Remove(integerArray1[i]) == true);
			assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - (i + 1));
			for (size_t j = 0; j < integerVector1.GetSize(); ++j)
			{
				assert(integerVector1[j] == integerArray1[i + j + 1]);
			}
		}
		std::cout << "Test FixedVector Remove() - order not changed after remove data: PASS" << std::endl;
		assert(integerVector1.Remove(integerArray1[4]) == false);
		assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - 4);
		std::cout << "Test FixedVector Remove() - empty array: PASS" << std::endl;

		enum { BOOL_VECTOR1_SIZE = 7 };
		bool boolArray1[] = { true,	true, true, true, false, false, true, true };
		FixedVector<bool, BOOL_VECTOR1_SIZE> boolVector1;
		assert(boolVector1.GetCapacity() == BOOL_VECTOR1_SIZE);
		assert(boolVector1.GetSize() == 0);
		std::cout << "Test FixedBoolVector constructor: PASS" << std::endl;

		std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;

		assert(boolVector1.Add(boolArray1[0]) == true);
		assert(boolVector1.Add(boolArray1[1]) == true);
		assert(boolVector1.Add(boolArray1[2]) == true);
		assert(boolVector1.Add(boolArray1[3]) == true);
		assert(boolVector1.Add(boolArray1[4]) == true);
		assert(boolVector1.Add(boolArray1[5]) == true);
		assert(boolVector1.Add(boolArray1[6]) == true);
		assert(boolVector1.GetSize() == 7);
		assert(boolVector1.Get(0) == boolArray1[0]);
		assert(boolVector1.Get(1) == boolArray1[1]);
		assert(boolVector1.Get(2) == boolArray1[2]);
		assert(boolVector1.Get(3) == boolArray1[3]);
		assert(boolVector1.Get(4) == boolArray1[4]);
		assert(boolVector1.Get(5) == boolArray1[5]);
		assert(boolVector1.Get(6) == boolArray1[6]);
		std::cout << "Test FixedBoolVector Add(): PASS" << std::endl;
		assert(boolVector1.Add(boolArray1[7]) == false);
		assert(boolVector1.GetSize() == 7);
		std::cout << "Test FixedBoolVector Add() - over array range: PASS" << std::endl;

		assert(boolVector1.Remove(false) == true);
		assert(boolVector1.GetSize() == 6);
		assert(boolVector1.Get(4) == boolArray1[5]);
		assert(boolVector1.Get(5) == boolArray1[6]);
		assert(boolVector1.Remove(false) == true);
		assert(boolVector1.GetSize() == 5);
		assert(boolVector1.Get(4) == boolArray1[6]);
		std::cout << "Test FixedBoolVector Remove(): PASS" << std::endl;
		assert(boolVector1.Remove(false) == false);
		assert(boolVector1.GetSize() == 5);
		std::cout << "Test FixedBoolVector Remove() - not found: PASS" << std::endl;

		for (size_t i = 0; i < boolVector1.GetSize(); i++)
		{
			assert(boolVector1[i]);
		}
		boolVector1.Remove(true);
		assert(boolVector1.GetSize() == 4);
		for (size_t i = 0; i < boolVector1.GetSize(); i++)
		{
			assert(boolVector1[i]);
		}
		std::cout << "Test FixedBoolVector operator[]() - read: PASS" << std::endl;

		FixedVector<bool, 65> boolVector2;

		std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;
		for (int i = 0; i < 65; i++)
		{
			boolVector2.Add(false);
		}

		assert(boolVector2.Add(true) == false);
		assert(boolVector2.GetSize() == 65);
		assert(boolVector2.GetIndex(true) == -1);
		std::cout << "Test FixedBoolVector GetIndex(): PASS" << std::endl;
	}

	void TestWiki2()
	{
		// empty vector test in primitive type
		{
			FixedVector<int, CAPACITY> v1;

			assert(!v1.Remove(10));
			assert(v1.GetIndex(10) == -1);
			assert(v1.GetSize() == 0);
			assert(v1.GetCapacity() == CAPACITY);
		}

		//empty vector test in class type
		{
			FixedVector<std::string, CAPACITY> v1;

			std::string cpu("CPU");

			assert(!v1.Remove(cpu));
			assert(v1.GetIndex(cpu) == -1);
			assert(v1.GetSize() == 0);
			assert(v1.GetCapacity() == CAPACITY);
		}

		// vector, whose capacity is one, test in primitive type
		{
			FixedVector<int, 1> v1;

			assert(v1.GetCapacity() == 1);

			assert(v1.GetSize() == 0);

			assert(v1.Add(100));
			assert(v1.GetSize() == 1);

			assert(!v1.Add(200));
			assert(v1.GetSize() == 1);

			assert(!v1.Remove(200));
			assert(v1.GetSize() == 1);

			assert(v1.Remove(100));
			assert(v1.GetSize() == 0);

			assert(v1.Add(100));
			assert(v1.GetSize() == 1);

			assert(v1.Get(0) == 100);
			assert(v1[0] == 100);

			v1[0] = 200;

			assert(v1.Get(0) == 200);
			assert(v1.GetIndex(100) == -1);
			assert(v1.GetIndex(200) == 0);
		}

		// vector, whose capacity is one, test in class type
		{
			FixedVector<std::string, 1> v1;

			std::string cpu("CPU");
			std::string cpp("C++");

			assert(v1.GetCapacity() == 1);

			assert(v1.GetSize() == 0);

			assert(v1.Add(cpu));
			assert(v1.GetSize() == 1);

			assert(!v1.Add(cpp));
			assert(v1.GetSize() == 1);

			assert(!v1.Remove(cpp));
			assert(v1.GetSize() == 1);

			assert(v1.Remove(cpu));
			assert(v1.GetSize() == 0);

			assert(v1.Add(cpu));
			assert(v1.GetSize() == 1);

			assert(v1.Get(0) == cpu);
			assert(v1[0] == cpu);

			v1[0] = cpp;

			assert(v1.Get(0) == cpp);
			assert(v1.GetIndex(cpu) == -1);
			assert(v1.GetIndex(cpp) == 0);
		}

		// example test on function details
		{
			FixedVector<int, 4> v1;

			assert(v1.Add(1));
			assert(v1.Add(2));
			assert(v1.Add(3));
			assert(v1.Add(4));
			assert(!v1.Add(5));

			assert(v1.Remove(3));
			assert(!v1.Remove(3));

			assert(v1.Get(0) == 1);
			assert(v1[0] == 1);

			assert(v1.GetIndex(2) == 1);
			assert(v1.GetIndex(5) == -1);

			assert(v1.GetSize() == 3);
			assert(v1.GetCapacity() == 4);
		}

		// example test
		{
			int i1 = 23;
			int i2 = 25;
			int i3 = 10;
			int i4 = -4;
			int i5 = 70;

			FixedVector<int, 33> iv;

			assert(iv.GetCapacity() == 33);

			iv.Add(i1);
			iv.Add(i2);
			iv.Add(i3);
			iv.Add(i4);

			assert(iv.GetSize() == 4);
			assert(iv.GetIndex(i2) == 1);
			assert(iv.Get(1) == i2);
			assert(iv[1] == i2);

			bool bRemoved = iv.Remove(i5);
			assert(!bRemoved);
			assert(iv.GetSize() == 4);

			bRemoved = iv.Remove(i2);
			assert(bRemoved);
			assert(iv.GetSize() == 3);
			assert(iv.GetIndex(i2) == -1);

			FixedVector<bool, 10> v;

			v.Add(true);
			v.Add(true);
			v.Add(true);
			v.Add(true);
			v.Add(false);
			v.Add(false);
			v.Add(true);

			assert(v.GetSize() == 7);
			assert(v.Get(0));
			assert(v.Get(1));
			assert(v.Get(2));
			assert(v.Get(3));
			assert(!v.Get(4));
			assert(!v.Get(5));
			assert(v.Get(6));

			v.Remove(false);

			assert(v.GetSize() == 6);
			assert(!v.Get(4));
			assert(v.Get(5));

			v.Remove(false);

			assert(v.GetSize() == 5);

			for (size_t i = 0; i < v.GetSize(); ++i)
			{
				assert(v[i]);
			}

			v.Remove(true);

			assert(v.GetSize() == 4);

			for (size_t i = 0; i < v.GetSize(); ++i)
			{
				assert(v[i]);
			}

			FixedVector<bool, 65> v1;

			for (int i = 0; i < 65; ++i)
			{
				v1.Add(false);
			}

			assert(!v1.Add(true));
			assert(v1.GetSize() == 65);
			assert(v1.GetIndex(true) == -1);
		}

		// vector containing many bool data tests
		{
			enum
			{
				BOOL_CAPACITY = 65
			};

			FixedVector<bool, BOOL_CAPACITY> v1;

			for (size_t i = 0; i < BOOL_CAPACITY; ++i)
			{
				assert(v1.Add(true));
				assert(v1.GetSize() == i + 1);
			}

			assert(v1.Add(true) == false);

			for (size_t i = 0; i < BOOL_CAPACITY; ++i)
			{
				assert(v1.Remove(true));
				assert(v1.GetSize() == BOOL_CAPACITY - (i + 1));
			}

			assert(v1.GetSize() == 0);

			for (size_t i = 0; i < 13; ++i)
			{
				assert(v1.Add(true));
				assert(v1.Add(true));
				assert(v1.Add(true));
				assert(v1.Add(false));
				assert(v1.Add(false));
			}

			for (size_t i = 0; i < 25; ++i)
			{
				v1.Remove(false);
			}

			assert(v1.GetIndex(false) >= 0);
		}
	}
	
	void MyTest()
	{
		FixedVector<char, 5> fvc;
		FixedVector<short, 5> fvs;
		FixedVector<int, 5> fvi;
		FixedVector<float, 5> fvf;
		FixedVector<double, 5> fvd;

		// FixedVector Char
		{
			assert(fvc.GetCapacity() == 5);
			assert(fvc.GetSize() == 0);

			assert(fvc.Add('a') == true);
			assert(fvc.GetSize() == 1);
			assert(fvc.Get(0) == 'a');
			assert(fvc[0] == 'a');

			assert(fvc.Add('b') == true);
			assert(fvc.GetSize() == 2);
			assert(fvc.Get(1) == 'b');
			assert(fvc[1] == 'b');

			assert(fvc.Add('c') == true);
			assert(fvc.GetSize() == 3);
			assert(fvc.Get(2) == 'c');
			assert(fvc[2] == 'c');

			assert(fvc.Add('d') == true);
			assert(fvc.GetSize() == 4);
			assert(fvc.Get(3) == 'd');
			assert(fvc[3] == 'd');

			assert(fvc.Add('e') == true);
			assert(fvc.GetSize() == 5);
			assert(fvc.Get(4) == 'e');
			assert(fvc[4] == 'e');

			assert(fvc.Add('f') == false);
			assert(fvc.GetSize() == 5);
			assert(fvc.Remove('f') == false);
			assert(fvc.GetSize() == 5);

			fvc[0] = 'b';
			fvc[1] = 'c';
			fvc[2] = 'd';
			fvc[3] = 'e';
			fvc[4] = 'f';

			assert(fvc.Remove('b') == true);
			assert(fvc.GetSize() == 4);
			assert(fvc.Get(0) == 'c');
			assert(fvc[0] == 'c');

			assert(fvc.Remove('c') == true);
			assert(fvc.GetSize() == 3);
			assert(fvc.Get(0) == 'd');
			assert(fvc[0] == 'd');

			assert(fvc.Remove('d') == true);
			assert(fvc.GetSize() == 2);
			assert(fvc.Get(0) == 'e');
			assert(fvc[0] == 'e');

			assert(fvc.Remove('e') == true);
			assert(fvc.GetSize() == 1);
			assert(fvc.Get(0) == 'f');
			assert(fvc[0] == 'f');

			assert(fvc.Remove('f') == true);
			assert(fvc.GetSize() == 0);
		}

		// FixedVector int
		{
			assert(fvi.GetCapacity() == 5);
			assert(fvi.GetSize() == 0);

			assert(fvi.Add(1) == true);
			assert(fvi.GetSize() == 1);
			assert(fvi.Get(0) == 1);
			assert(fvi[0] == 1);

			assert(fvi.Add(2) == true);
			assert(fvi.GetSize() == 2);
			assert(fvi.Get(1) == 2);
			assert(fvi[1] == 2);

			assert(fvi.Add(3) == true);
			assert(fvi.GetSize() == 3);
			assert(fvi.Get(2) == 3);
			assert(fvi[2] == 3);

			assert(fvi.Add(4) == true);
			assert(fvi.GetSize() == 4);
			assert(fvi.Get(3) == 4);
			assert(fvi[3] == 4);

			assert(fvi.Add(5) == true);
			assert(fvi.GetSize() == 5);
			assert(fvi.Get(4) == 5);
			assert(fvi[4] == 5);

			assert(fvi.Add(6) == false);
			assert(fvi.GetSize() == 5);
			assert(fvi.Remove(6) == false);
			assert(fvi.GetSize() == 5);

			fvi[0] = 2;
			fvi[1] = 3;
			fvi[2] = 4;
			fvi[3] = 5;
			fvi[4] = 6;

			assert(fvi.Remove(2) == true);
			assert(fvi.GetSize() == 4);
			assert(fvi.Get(0) == 3);
			assert(fvi[0] == 3);

			assert(fvi.Remove(3) == true);
			assert(fvi.GetSize() == 3);
			assert(fvi.Get(0) == 4);
			assert(fvi[0] == 4);

			assert(fvi.Remove(4) == true);
			assert(fvi.GetSize() == 2);
			assert(fvi.Get(0) == 5);
			assert(fvi[0] == 5);

			assert(fvi.Remove(5) == true);
			assert(fvi.GetSize() == 1);
			assert(fvi.Get(0) == 6);
			assert(fvi[0] == 6);

			assert(fvi.Remove(6) == true);
			assert(fvi.GetSize() == 0);
		}
	}

	void TestFixedBoolVector()
	{
		// Basic test
		{
			FixedVector<bool, 3> fvb;
			assert(fvb.GetSize() == 0);
			assert(fvb.GetCapacity() == 3);

			assert(fvb.Add(false) == true);
			assert(fvb.GetSize() == 1);
			assert(fvb.Add(false) == true);
			assert(fvb.GetSize() == 2);
			assert(fvb.Add(false) == true);
			assert(fvb.GetSize() == 3);
			assert(fvb.Add(false) == false);
			assert(fvb.GetSize() == 3);

			assert(fvb.Get(0) == false);
			assert(fvb.Get(1) == false);
			assert(fvb.Get(2) == false);

			assert(fvb.GetIndex(true) == -1);
			assert(fvb.GetIndex(false) == 0);
		}
		

		{
			FixedVector<bool, 65> fvb2;

			for (size_t i = 0; i < 64; ++i)
			{
				assert(fvb2.Add(true) == true);
			}

			assert(fvb2.Add(false) == true);
			assert(fvb2.Add(true) == false);

			assert(fvb2.GetIndex(false) == 64);

			for (size_t i = 0; i < 64; ++i)
			{
				assert(fvb2[i] == true);
			}

			assert(fvb2[64] == false);
		}

		{
			FixedVector<bool, 65> fvb3;

			for (size_t i = 0; i < 64; ++i)
			{
				assert(fvb3.Add(false) == true);
			}

			assert(fvb3.Add(true) == true);
			assert(fvb3.Add(false) == false);

			assert(fvb3.GetIndex(true) == 64);

			for (size_t i = 0; i < 64; ++i)
			{
				assert(fvb3[i] == false);
			}

			assert(fvb3[64] == true);
		}

		// Test Remove
		{
			FixedVector<bool, 64> fvb;
			
			assert(fvb.Add(true) == true);
			assert(fvb.Add(false) == true);
			assert(fvb.Add(true) == true);

			for (size_t i = 0; i < 29; ++i)
			{
				assert(fvb.Add(false) == true);
			}

			for (size_t i = 0; i < 32; ++i)
			{
				assert(fvb.Add(false) == true);
			}

			fvb.Remove(false);
			assert(fvb[31] == false);
		}
	}
}