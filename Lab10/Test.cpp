#include "Test.h"

namespace lab10
{
	void TestOfficial()
	{
	}

	void TestInsert()
	{
		int list1[] = { 1, 3, 4 };
		int list2[] = { 0, 1, 3, 4 };
		int list3[] = { 0, 1, 2, 3, 4 };
		DoublyLinkedList<int> list;

		list.Insert(std::make_unique<int>(1));
		assert(list.GetLength() == 1);

		list.Insert(std::make_unique<int>(3));
		assert(list.GetLength() == 2);

		list.Insert(std::make_unique<int>(4));
		assert(list.GetLength() == 3);
		list.PrintList(); // 1 -> 3 -> 4
		list.CheckList(list1);

		list.Insert(std::make_unique<int>(0), 0);
		assert(list.GetLength() == 4);
		list.PrintList(); // 0 -> 1 -> 3 -> 4
		assert(list.CheckList(list2));

		list.Insert(std::make_unique<int>(2), 2);
		assert(list.GetLength() == 5);
		list.PrintList(); // 0 -> 1 -> 2 -> 3 -> 4
		assert(list.CheckList(list3));
	}

	void TestDelete()
	{
		int list1[] = { 1, };
		int list2[] = { 1, 3 };
		DoublyLinkedList<int> list;

		list.Insert(std::make_unique<int>(1));
		assert(list.GetLength() == 1);
		assert(!list.Delete(-1));

		assert(list.Delete(1));
		assert(list.GetLength() == 0);

		list.Insert(std::make_unique<int>(1));
		list.Insert(std::make_unique<int>(2));
		assert(list.GetLength() == 2);

		assert(list.Delete(2));
		assert(list.GetLength() == 1);
		assert(list.CheckList(list1));

		list.Insert(std::make_unique<int>(2));
		list.Insert(std::make_unique<int>(3));
		assert(list.GetLength() == 3);

		assert(list.Delete(2));
		assert(list.GetLength() == 2);
		assert(list.CheckList(list2));
	}
}
