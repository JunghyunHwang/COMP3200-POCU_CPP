#include "Test.h"

namespace assignment3
{
	const double EPSILON = 0.0009765625;

	void TestOfficial()
	{
		return;
	}

	void TestSmartStack()
	{
		SmartStack<int> stInt;
		stInt.Push(1);
		stInt.Push(3);
		stInt.Push(2);
		stInt.Push(4);
		stInt.Push(3);

		assert(stInt.GetMax() == 4);
		assert(stInt.GetMin() == 1);
		assert(stInt.Peek() == 3);
		assert(stInt.Pop() == 3);
		assert(stInt.Peek() == 4);
		assert(stInt.GetSum() == 10);
		assert(std::abs(stInt.GetAverage() - 2.5) <= EPSILON);
	}
}