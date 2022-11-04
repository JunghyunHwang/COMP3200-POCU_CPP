#include "Test.h"

namespace assignment3
{
	const double EPSILON = 0.0009765625;

	void TestOfficial()
	{
		const double EPSILON = 0.0009765625;

		SmartStack<float> ss;

		ss.Push(3.4999f);
		ss.Push(1.2f);
		ss.Push(4.6555f);
		ss.Push(3.3299f);
		ss.Push(10.2f);
		ss.Push(1.1f);
		ss.Push(-5.9f);
		ss.Push(1.1f);
		ss.Push(-12.4f);
		ss.Push(9.2f);

		assert(ss.GetCount() == 10U);
		assert(ss.Peek() == 9.2f);
		assert(ss.GetMax() == 10.2f);
		assert(ss.GetMin() == -12.4f);
		assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
		assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
		assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
		assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
		assert(ss.Peek() == 9.2f);

		float popped1 = ss.Pop();
		float popped2 = ss.Pop();

		assert(popped1 == 9.2f);
		assert(popped2 == -12.4f);
		assert(ss.GetCount() == 8U);
		assert(ss.Peek() == 1.1f);
		assert(ss.GetMax() == 10.2f);
		assert(ss.GetMin() == -5.9f);
		assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
		assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
		assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
		assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);
	}

	void TestWiki()
	{
	const double EPSILON = 0.0009765625;

	// test constructor
	QueueStack<int> qs(2u);
	assert(qs.GetCount() == 0u);
	assert(qs.GetStackCount() == 0u);
	assert(qs.GetSum() == 0);
	assert(qs.GetMax() == std::numeric_limits<int>::min());
	assert(qs.GetMin() == std::numeric_limits<int>::max());

	// test Enqueue()
	qs.Enqueue(0);
	assert(qs.Peek() == 0);
	assert(qs.GetMax() == 0);
	assert(qs.GetMin() == 0);
	assert(qs.GetSum() == 0);
	assert(qs.GetAverage() == 0);
	assert(qs.GetCount() == 1u);
	assert(qs.GetStackCount() == 1u);

	qs.Enqueue(4);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 4);
	assert(qs.GetMin() == 0);
	assert(qs.GetSum() == 4);
	assert(qs.GetAverage() == 2);
	assert(qs.GetCount() == 2u);
	assert(qs.GetStackCount() == 1u);

	qs.Enqueue(-3);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 4);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 1);
	assert(std::abs(qs.GetAverage() - 0.33333333) <= EPSILON);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(7);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 8);
	assert(qs.GetAverage() == 2);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(5);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 13);
	assert(qs.GetAverage() == 2.6);
	assert(qs.GetCount() == 5u);
	assert(qs.GetStackCount() == 3u);

	// test copy constructor
	QueueStack<int> qs2(qs);
	assert(qs2.Peek() == 4);
	assert(qs2.GetMax() == 7);
	assert(qs2.GetMin() == -3);
	assert(qs2.GetSum() == 13);
	assert(qs2.GetAverage() == 2.6);
	assert(qs2.GetCount() == 5u);
	assert(qs2.GetStackCount() == 3u);

	// test Dequeue()
	assert(qs.Dequeue() == 4);
	assert(qs.Peek() == 0);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 9);
	assert(qs.GetAverage() == 2.25);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 3u);

	assert(qs.Dequeue() == 0);
	assert(qs.Peek() == 7);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 9);
	assert(qs.GetAverage() == 3);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	assert(qs.Dequeue() == 7);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 2);
	assert(qs.GetAverage() == 1);
	assert(qs.GetCount() == 2u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(-6);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == -6);
	assert(qs.GetSum() == -4);
	assert(std::abs(qs.GetAverage() - (-1.33333333)) <= EPSILON);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(-8);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == -12);
	assert(qs.GetAverage() == -3);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 3u);

	qs.Enqueue(10);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == -2);
	assert(qs.GetAverage() == -0.4);
	assert(qs.GetCount() == 5u);
	assert(qs.GetStackCount() == 3u);

	assert(qs.Dequeue() == -3);
	assert(qs.Peek() == -6);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == 1);
	assert(qs.GetAverage() == 0.25);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 2u);

	assert(qs.Dequeue() == -6);
	assert(qs.Peek() == 5);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == 7);
	assert(std::abs(qs.GetAverage() - 2.33333333) <= EPSILON);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	assert(qs.Dequeue() == 5);
	assert(qs.Peek() == 10);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == 2);
	assert(qs.GetAverage() == 1);
	assert(qs.GetCount() == 2u);
	assert(qs.GetStackCount() == 1u);

	assert(qs.Dequeue() == 10);
	assert(qs.Peek() == -8);
	assert(qs.GetMax() == -8);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == -8);
	assert(qs.GetAverage() == -8);
	assert(qs.GetCount() == 1u);
	assert(qs.GetStackCount() == 1u);

	assert(qs.Dequeue() == -8);
	assert(qs.GetMax() == std::numeric_limits<int>::min());
	assert(qs.GetMin() == std::numeric_limits<int>::max());
	assert(qs.GetSum() == 0);
	assert(qs.GetCount() == 0u);
	assert(qs.GetStackCount() == 0u);

	// test assignment operator
	assert(qs2.GetMax() != std::numeric_limits<int>::min());
	assert(qs2.GetMin() != std::numeric_limits<int>::max());
	assert(qs2.GetSum() != 0);
	assert(qs2.GetCount() != 0u);
	assert(qs2.GetStackCount() != 0u);

	qs2 = qs;

	assert(qs2.GetMax() == std::numeric_limits<int>::min());
	assert(qs2.GetMin() == std::numeric_limits<int>::max());
	assert(qs2.GetSum() == 0);
	assert(qs2.GetCount() == 0u);
	assert(qs2.GetStackCount() == 0u);

	// test max stack count 0
	qs = QueueStack<int>(0);
	qs.Enqueue(1);
	qs.Enqueue(2);
	qs.Enqueue(3);

	assert(qs.GetMax() == std::numeric_limits<int>::min());
	assert(qs.GetMin() == std::numeric_limits<int>::max());
	assert(qs.GetSum() == 0);
	assert(qs.GetCount() == 0u);
	assert(qs.GetStackCount() == 0u);

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

		SmartStack<int> s;
		s.Push(6);
		s.Push(5);
		s.Push(-2);
		s.Push(5);

		assert(s.GetCount() == 4);
		assert(s.GetMax() == 6);
		assert(s.GetMin() == -2);
		s.Pop();
		assert(s.GetSum() == 9);
		assert(s.Peek() == -2);
		assert(s.GetAverage() == 3);
		assert(std::abs(s.GetVariance() - 12.667) <= EPSILON);

		stInt = s;
		assert(stInt.GetCount() == 3);
		assert(stInt.GetMax() == 6);
		assert(stInt.GetMin() == -2);
		assert(stInt.GetSum() == 9);
		assert(stInt.Peek() == -2);
		assert(stInt.GetAverage() == 3);
		assert(std::abs(stInt.GetVariance() - 12.667) <= EPSILON);

		SmartStack<int> copiedS(s);
		assert(stInt.GetCount() == 3);
		assert(stInt.GetMax() == 6);
		assert(stInt.GetMin() == -2);
		assert(stInt.GetSum() == 9);
		assert(stInt.Peek() == -2);
		assert(stInt.GetAverage() == 3);
		assert(std::abs(stInt.GetVariance() - 12.667) <= EPSILON);

		assert(s.Pop() == -2);
		assert(s.Peek() == 5);
		assert(stInt.Peek() == -2);
		assert(copiedS.Peek() == -2);
	}

	void TestSmartQueue()
	{

	}

	void TestQueueStack()
	{
		QueueStack<int> qs(2);

		assert(qs.GetMax() == std::numeric_limits<int>::min());
		assert(qs.GetMin() == std::numeric_limits<int>::max());
		assert(qs.GetCount() == 0);
		assert(qs.GetStackCount() == 0);

		qs.Enqueue(0);
		assert(qs.Peek() == 0);
		assert(qs.GetStackCount() == 1);
		assert(qs.GetMax() == 0);
		assert(qs.GetMin() == 0);
		assert(qs.GetCount() == 1);
		assert(qs.GetStackCount() == 1);

		qs.Enqueue(4);
		assert(qs.Peek() == 4);
		assert(qs.GetStackCount() == 1);
		assert(qs.GetMax() == 4);
		assert(qs.GetMin() == 0);
		assert(qs.GetCount() == 2);
		assert(qs.GetStackCount() == 1);

		qs.Enqueue(3);
		assert(qs.Peek() == 4);
		assert(qs.GetMax() == 4);
		assert(qs.GetMin() == 0);
		assert(qs.GetCount() == 3);
		assert(qs.GetStackCount() == 2);

		qs.Enqueue(2);
		assert(qs.Peek() == 4);
		assert(qs.GetMax() == 4);
		assert(qs.GetMin() == 0);
		assert(qs.GetCount() == 4);
		assert(qs.GetStackCount() == 2);

		qs.Dequeue();
		assert(qs.Peek() == 0);
		assert(qs.GetMax() == 3);
		assert(qs.GetMin() == 0);
		assert(qs.GetCount() == 3);
		assert(qs.GetStackCount() == 2);

		qs.Dequeue();
		assert(qs.Peek() == 2);
		assert(qs.GetMax() == 3);
		assert(qs.GetMin() == 2);
		assert(qs.GetCount() == 2);
		assert(qs.GetStackCount() == 1);
	}
}