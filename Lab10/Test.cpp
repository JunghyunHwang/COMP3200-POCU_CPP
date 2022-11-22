#include "Test.h"

namespace lab10
{
	void TestOfficial()
	{
		DoublyLinkedList<int> list;

		list.Insert(std::make_unique<int>(1));
		list.Insert(std::make_unique<int>(2));
		list.Insert(std::make_unique<int>(3));
		list.Insert(std::make_unique<int>(4));
		list.Insert(std::make_unique<int>(5));
		list.Insert(std::make_unique<int>(6));
		list.Insert(std::make_unique<int>(7));

		bool bSearched = list.Search(4);
		assert(bSearched);

		bSearched = list.Search(10);
		assert(!bSearched);

		unsigned int size = list.GetLength();
		assert(size == 7);

		bool bDeleted =  list.Delete(3);
		assert(bDeleted);

		bDeleted = list.Delete(3);
		assert(!bDeleted);

		size = list.GetLength();
		assert(size == 6);

		std::shared_ptr<Node<int>> node = list[2];
		assert(*node->Data == 4);

		list.Insert(std::make_unique<int>(10), 2);
		
		node = list[2];
		assert(*node->Data == 10);
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

	void TestSearch()
	{
		DoublyLinkedList<int> list;

		assert(!list.Search(1));

		list.Insert(sdt::make_unique<int>(1));
		list.Insert(sdt::make_unique<int>(2));
		list.Insert(sdt::make_unique<int>(3));
		list.Insert(sdt::make_unique<int>(4));
		list.Insert(sdt::make_unique<int>(5));

		assert(list.Search(1));
		assert(list.Search(2));
		assert(list.Search(3));
		assert(list.Search(4));
		assert(list.Search(5));
		assert(!list.Search(-1));
		assert(!list.Search(0));

		list.Insert(sdt::make_unique<int>(0), 0);
		assert(list.Search(0));
	}

	void TestIndex()
	{
		DoublyLinkedList<int> list;

		list.Insert(sdt::make_unique<int>(1));
		list.Insert(sdt::make_unique<int>(2));
		list.Insert(sdt::make_unique<int>(3));
		list.Insert(sdt::make_unique<int>(4));
		list.Insert(sdt::make_unique<int>(5));

		assert(list[0].use_count() == 1);
		assert(list[1].use_count() == 1);
		assert(list[2].use_count() == 1);
		assert(list[3].use_count() == 1);
		assert(list[4].use_count() == 1);

		std::shared_ptr<Node<T>> node1 = list[0];
		assert(node1.use_count() == 2);
	}
}
