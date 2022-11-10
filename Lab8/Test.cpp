#include "Test.h"

namespace lab8
{
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
	}
}