#include "Test.h"

namespace test
{
	void TestCopyConstructor()
	{
		MyArray<int> arr1(5);
		MyArray<int> arr2(arr1);
		MyArray<int> arr3;

		assert(arr1.GetCapacity() == 5);
		assert(arr2.GetCapacity() == 5);
		assert(arr3.GetCapacity() == 10);

		arr1.Add(1);
		arr1.Add(2);
		arr1.Add(3);
		arr1.Add(4);

		arr3 = arr1;

		for (size_t i = 0; i < arr3.GetSize(); ++i)
		{
			assert(arr3[i] == i + 1);
		}
	}

	void TestMoveConstructor()
	{
		MyArray<int> arr1;
		assert(arr1.GetSize() == 0);
		assert(arr1.GetCapacity() == 10);

		arr1.Add(1);
		arr1.Add(2);
		arr1.Add(3);
		arr1.Add(4);
		arr1.Add(5);

		for (size_t i = 0; i < arr1.GetSize(); ++i)
		{
			assert(arr1[i] == i + 1);
		}

		MyArray<int> arr2(std::move(arr1));
		assert(arr1.GetSize() == 0);
		assert(arr1.GetCapacity() == 0);
		assert(arr2.GetSize() == 5);
		assert(arr2.GetCapacity() == 10);

		for (size_t i = 0; i < arr2.GetSize(); ++i)
		{
			assert(arr2[i] == i + 1);
		}

		MyArray<int> arr3 = std::move(arr2);
		assert(arr2.GetSize() == 0);
		assert(arr2.GetCapacity() == 0);
		assert(arr3.GetSize() == 5);
		assert(arr3.GetCapacity() == 10);

		arr3.Add(6);
		arr3.Add(7);
		arr3.Add(8);
		arr3.Add(9);
		arr3.Add(10);
		arr3.Add(11);

		assert(arr3.GetSize() == 11);
		assert(arr3.GetCapacity() == 20);

		for (size_t i = 0; i < arr3.GetSize(); ++i)
		{
			assert(arr3[i] == i + 1);
		}
	}
}
