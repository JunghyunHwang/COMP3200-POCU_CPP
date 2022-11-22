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

	void TestWiki()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		DoublyLinkedList<int> list;

		assert(list[0] == nullptr);
		assert(list[3] == nullptr);
		bool bEmptyDeleted = list.Delete(6);
		assert(!bEmptyDeleted);
		bool bEmptySearched = list.Search(7);
		assert(!bEmptySearched);

		list.Insert(std::make_unique<int>(1));
		list.Insert(std::make_unique<int>(2));
		list.Insert(std::make_unique<int>(3));
		list.Insert(std::make_unique<int>(4));
		list.Insert(std::make_unique<int>(5));
		list.Insert(std::make_unique<int>(6));
		list.Insert(std::make_unique<int>(7));

		bool bSearched = list.Search(4);
		assert(bSearched);

		bSearched = list.Search(1);
		assert(bSearched);

		bSearched = list.Search(7);
		assert(bSearched);

		bSearched = list.Search(10);
		assert(!bSearched);

		unsigned int size = list.GetLength();
		assert(size == 7);

		bool bDeleted = list.Delete(3);
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

		bDeleted = list.Delete(1);
		assert(bDeleted);
		assert(*list[0]->Data == 2);

		bDeleted = list.Delete(7);
		assert(bDeleted);

		list.Insert(std::make_unique<int>(11), 0);

		node = list[0];
		assert(*node->Data == 11);
		assert(list.GetLength() == 6);

		list.Insert(std::make_unique<int>(12), 6);
		assert(list.GetLength() == 7);
		node = list[6];
		assert(*node->Data == 12);

		list.Insert(std::make_unique<int>(13), 9);
		assert(list.GetLength() == 8);
		node = list[7];
		assert(*node->Data == 13);

		bDeleted = list.Delete(2);
		assert(bDeleted);
		bDeleted = list.Delete(4);
		assert(bDeleted);
		bDeleted = list.Delete(5);
		assert(bDeleted);
		bDeleted = list.Delete(6);
		assert(bDeleted);
		bDeleted = list.Delete(10);
		assert(bDeleted);
		bDeleted = list.Delete(11);
		assert(bDeleted);
		bDeleted = list.Delete(12);
		assert(bDeleted);
		bDeleted = list.Delete(13);
		assert(bDeleted);

		assert(list[0] == nullptr);
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

		list.Insert(std::make_unique<int>(1));
		list.Insert(std::make_unique<int>(2));
		list.Insert(std::make_unique<int>(3));
		list.Insert(std::make_unique<int>(4));
		list.Insert(std::make_unique<int>(5));

		assert(list.Search(1));
		assert(list.Search(2));
		assert(list.Search(3));
		assert(list.Search(4));
		assert(list.Search(5));
		assert(!list.Search(-1));
		assert(!list.Search(0));

		list.Insert(std::make_unique<int>(0), 0);
		assert(list.Search(0));
	}

	void TestIndex()
	{
		DoublyLinkedList<int> list;

		list.Insert(std::make_unique<int>(1));
		list.Insert(std::make_unique<int>(2));
		list.Insert(std::make_unique<int>(3));
		list.Insert(std::make_unique<int>(4));
		list.Insert(std::make_unique<int>(5));

		std::cout << list[0].use_count() << std::endl;
		std::cout << list[1].use_count() << std::endl;
		std::cout << list[2].use_count() << std::endl;
		std::cout << list[3].use_count() << std::endl;
		std::cout << list[4].use_count() << std::endl;

		std::shared_ptr<Node<int>> node1 = list[0];
		assert(node1.use_count() == 2);
	}
}
