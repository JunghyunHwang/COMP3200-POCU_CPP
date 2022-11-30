#include "Test.h"

namespace lab11
{
	void TestOfficial()
	{
		const unsigned int SIZE = 10000;

		Storage<int> storage1(SIZE);
		const std::unique_ptr<int[]>& data1 = storage1.GetData();

		for (int i = 0; i < SIZE; ++i)
		{
			assert(data1[i] == 0);
		}


		Storage<int> storage2(SIZE, 100);
		const std::unique_ptr<int[]>& data2 = storage2.GetData();

		for (int i = 0; i < SIZE; ++i)
		{
			assert(data2[i] == 100);
		}

		// using move constructor
		Storage<int> storage3(SIZE, 50);
		const std::unique_ptr<int[]>& data3 = storage3.GetData();

		assert(storage3.GetSize() == SIZE);

		for (int i = 0; i < SIZE; ++i)
		{
			assert(data3[i] == 50);
		}

		Storage<int> storage3Copy(std::move(storage3));
		const std::unique_ptr<int[]>& data3Copy = storage3Copy.GetData();

		assert(storage3Copy.GetSize() == SIZE);
		for (int i = 0; i < SIZE; ++i)
		{
			assert(data3Copy[i] == 50);
		}

		assert(storage3.GetData() == nullptr);
		assert(storage3.GetSize() == 0);

		Storage<char> storage4(SIZE, 'f');
		const std::unique_ptr<char[]>& data4 = storage4.GetData();

		assert(storage4.GetSize() == SIZE);

		for (int i = 0; i < SIZE; ++i)
		{
			assert(data4[i] == 'f');
		}

		Storage<char> storage4Copy = std::move(storage4);
		const std::unique_ptr<char[]>& data4Copy = storage4Copy.GetData();

		assert(storage4Copy.GetSize() == SIZE);

		for (int i = 0; i < SIZE; ++i)
		{
			assert(data4Copy[i] == 'f');
		}

		assert(storage4.GetData() == nullptr);
		assert(storage4.GetSize() == 0);

		const unsigned int SIZE2 = 5000;

		Storage<int> storage5(SIZE2);
		const std::unique_ptr<int[]>& data5 = storage5.GetData();

		for (int i = 0; i < SIZE2; ++i)
		{
			storage5.Update(i, SIZE2 - i - 1);
			assert(data5[i] == SIZE2 - i - 1);
		}
	}

	void MyTest()
	{
		const double EPSILON = 0.0009765625;

		// int storage
		{
			Storage<int> s(5, 100);

			const std::unique_ptr<int[]>& data = s.GetData();
			const size_t SIZE = s.GetSize();

			for (size_t i = 0; i < SIZE; ++i)
			{
				assert(data[i] == 100);
				assert(s.Update(i, 200));
			}

			assert(!s.Update(8, -1));

			for (size_t i = 0; i < SIZE; ++i)
			{
				assert(data[i] == 200);
			}
		}

		// float storage
		{
			Storage<float> s(5, 0.5);

			const std::unique_ptr<float[]>& data = s.GetData();
			const size_t SIZE = s.GetSize();

			for (size_t i = 0; i < SIZE; ++i)
			{
				assert(data[i] == 0.5);
				assert(s.Update(i, static_cast<float>(3.14)));
			}

			assert(!s.Update(SIZE, -1));

			for (size_t i = 0; i < SIZE; ++i)
			{
				assert(std::abs(data[i] - 3.14) <= EPSILON);
			}
		}
		
		// string storage
		{
			Storage<std::string> s(5, "Hi");
			const std::unique_ptr<std::string[]>& data = s.GetData();
			const size_t SIZE = s.GetSize();

			for (size_t i = 0; i < SIZE; ++i)
			{
				assert(data[i] == "Hi");
				assert(s.Update(i, "bye"));
			}

			assert(!s.Update(SIZE, "good"));

			for (size_t i = 0; i < SIZE; ++i)
			{
				assert(data[i] == "bye");
			}
		}
	}

	void TestMoveConstructor()
	{
		Storage<int> sInt(5, 200);
		const std::unique_ptr<int[]>& data1 = sInt.GetData();
		const unsigned int SIZE = sInt.GetSize();

		Storage<int> copied(sInt);
		const std::unique_ptr<int[]>& data2 = copied.GetData();

		for (size_t i = 0; i < SIZE; ++i)
		{
			assert(data1[i] == data2[i]);
		}

		Storage<int> moveCopied(std::move(sInt));
		const std::unique_ptr<int[]>& moveCopiedData = moveCopied.GetData();
		assert(sInt.GetData() == nullptr);

		for (size_t i = 0; i < SIZE; ++i)
		{
			assert(moveCopiedData[i] == data2[i]);
		}

		Storage<int> moveAssign = std::move(copied);
		const std::unique_ptr<int[]>& moveAssignData = moveAssign.GetData();
		assert(copied.GetData() == nullptr);

		for (size_t i = 0; i < SIZE; ++i)
		{
			assert(moveAssignData[i] == moveCopiedData[i]);
		}
	}
}
