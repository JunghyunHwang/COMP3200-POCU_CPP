#include "Test.h"

namespace assignment4
{
	void TestOfficial()
	{
		BinarySearchTree<int> tree;

		tree.Insert(std::make_unique<int>(10));
		tree.Insert(std::make_unique<int>(15));
		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(19));
		tree.Insert(std::make_unique<int>(20));
		tree.Insert(std::make_unique<int>(17));
		tree.Insert(std::make_unique<int>(12));

		std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

		assert(v.size() == 8);
		assert(v[0] == 4);
		assert(v[1] == 5);
		assert(v[2] == 10);
		assert(v[3] == 12);
		assert(v[4] == 15);
		assert(v[5] == 17);
		assert(v[6] == 19);
		assert(v[7] == 20);

		bool bSearched = tree.Search(15);
		assert(bSearched);

		bool bDeleted = tree.Delete(6);
		assert(!bDeleted);

		bDeleted = tree.Delete(100);
		assert(!bDeleted);

		bDeleted = tree.Delete(15);
		assert(bDeleted);

		v = tree.TraverseInOrder(tree.GetRootNode().lock());

		assert(v.size() == 7);
		assert(v[0] == 4);
		assert(v[1] == 5);
		assert(v[2] == 10);
		assert(v[3] == 12);
		assert(v[4] == 17);
		assert(v[5] == 19);
		assert(v[6] == 20);

		bSearched = tree.Search(15);
		assert(!bSearched);
	}

	void TestInsert()
	{
		BinarySearchTree<int> tree;
		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(3));
		tree.Insert(std::make_unique<int>(8));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(1));
		tree.Insert(std::make_unique<int>(11));
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(2));

		std::vector<int> expected;
		expected.push_back(1);
		expected.push_back(2);
		expected.push_back(3);
		expected.push_back(4);
		expected.push_back(5);
		expected.push_back(6);
		expected.push_back(8);
		expected.push_back(11);

		std::weak_ptr<TreeNode<int>> rootNode = tree.GetRootNode();

		std::vector<int> actual = tree.TraverseInOrder(rootNode.lock());

		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(expected[i] == actual[i]);
		}
	}
}