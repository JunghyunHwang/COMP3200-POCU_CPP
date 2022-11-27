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

	void TestWiki()
	{
		BinarySearchTree<int> tree;

		int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };

		for (size_t i = 0; i < 9; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		//	End
		assert(!tree.Delete(9)); 	// 존재하지 않는 노드 삭제
		assert(tree.Delete(20));	// Right 노드 삭제
		assert(!tree.Search(20));	// 삭제 확인
		assert(tree.Delete(12));	// Left 노드 삭제
		assert(!tree.Search(12));	// 삭제 확인
		assert(!tree.Delete(11));	// 존재하지 않는 노드 삭제

		//	Middle
		assert(tree.Delete(19));	// Left만 있는 노드 삭제
		assert(!tree.Search(19));	// 삭제 확인
		assert(tree.Search(17));

		assert(tree.Delete(4));
		assert(tree.Delete(7));
		assert(tree.Delete(17));	// Left, Right 모두 없는 헤드 삭제
		assert(!tree.Search(17));	// 삭제 확인
		assert(!tree.Delete(17));	// 비어있는 상태에서 삭제

		assert(tree.Delete(15));	// Right만 있는 노드 삭제
		assert(!tree.Search(15));	// 삭제 확인
		assert(tree.Delete(5)); 	// Left, Right 모두 있는 노드 삭제
		assert(!tree.Search(5));
		assert(!tree.Delete(5));	// 존재하지 않는 노드 삭제

		//	Head
		assert(tree.Delete(10)); 	// Left, Right 모두 있는 헤드 삭제
		assert(!tree.Search(10));	// 삭제 확인

		for (size_t i = 0; i < 9; i++)
		{
			tree.Insert(std::make_unique<int>(arr[i]));
		}

		tree.Delete(arr[0]);
		tree.Delete(arr[1]);
		tree.Delete(arr[2]);
		tree.Delete(arr[3]);
		tree.Delete(arr[4]);
		tree.Delete(arr[5]);
		tree.Delete(arr[6]);
		tree.Delete(arr[7]);
		tree.Delete(arr[8]);
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

	void TestSearch()
	{
		BinarySearchTree<int> tree;

		assert(!tree.Search(0));
		assert(!tree.Search(1));

		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(3));
		tree.Insert(std::make_unique<int>(8));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(1));
		tree.Insert(std::make_unique<int>(11));
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(2));

		assert(tree.Search(5));
		assert(tree.Search(2));
		assert(tree.Search(8));
		assert(tree.Search(11));
		assert(!tree.Search(-1));
	}

	void TestDelete()
	{

	}

	void TestNormalTree()
	{
		BinarySearchTree<int> tree;
		std::vector<int> expected;
		std::vector<int> actual;
		std::shared_ptr<TreeNode<int>> rootNode;

		expected.reserve(64);
		expected.reserve(64);

		assert(!tree.Search(0));
		assert(!tree.Search(1));

		tree.Insert(std::make_unique<int>(11));
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(14));
		tree.Insert(std::make_unique<int>(12));
		tree.Insert(std::make_unique<int>(20));
		tree.Insert(std::make_unique<int>(2));
		tree.Insert(std::make_unique<int>(9));
		tree.Insert(std::make_unique<int>(13));
		tree.Insert(std::make_unique<int>(18));
		tree.Insert(std::make_unique<int>(1));
		tree.Insert(std::make_unique<int>(25));
		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(8));
		tree.Insert(std::make_unique<int>(10));
		tree.Insert(std::make_unique<int>(3));

		{
			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);
			expected.push_back(11);
			expected.push_back(12);
			expected.push_back(13);
			expected.push_back(14);
			expected.push_back(18);
			expected.push_back(20);
			expected.push_back(25);

			rootNode = tree.GetRootNode().lock();
			actual = tree.TraverseInOrder(rootNode);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);

			actual = tree.TraverseInOrder(rootNode->Left);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();
			
			expected.push_back(12);
			expected.push_back(13);
			expected.push_back(14);
			expected.push_back(18);
			expected.push_back(20);
			expected.push_back(25);

			actual = tree.TraverseInOrder(rootNode->Right);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(5);

			actual = tree.TraverseInOrder(rootNode->Left->Left);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);

			actual = tree.TraverseInOrder(rootNode->Left->Right);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(12);
			expected.push_back(13);

			actual = tree.TraverseInOrder(rootNode->Right->Left);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(18);
			expected.push_back(20);
			expected.push_back(25);

			actual = tree.TraverseInOrder(rootNode->Right->Right);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		assert(tree.Search(11));
		assert(tree.Search(6));
		assert(tree.Search(14));
		assert(tree.Search(12));
		assert(tree.Search(20));
		assert(tree.Search(2));
		assert(tree.Search(9));
		assert(tree.Search(13));
		assert(tree.Search(18));
		assert(tree.Search(1));
		assert(tree.Search(25));
		assert(tree.Search(5));
		assert(tree.Search(8));
		assert(tree.Search(10));
		assert(tree.Search(3));
		assert(!tree.Search(100));

		assert(tree.Delete(6));
		assert(tree.Delete(3));
		assert(tree.Delete(9));

		assert(tree.Search(11));
		assert(!tree.Search(6));
		assert(tree.Search(14));
		assert(tree.Search(12));
		assert(tree.Search(20));
		assert(tree.Search(2));
		assert(!tree.Search(9));
		assert(tree.Search(13));
		assert(tree.Search(18));
		assert(tree.Search(1));
		assert(tree.Search(25));
		assert(tree.Search(5));
		assert(tree.Search(8));
		assert(tree.Search(10));
		assert(!tree.Search(3));

		assert(tree.Delete(20));
		assert(tree.Delete(10));
		assert(tree.Delete(12));
		assert(tree.Delete(11));

		assert(!tree.Search(11));
		assert(!tree.Search(6));
		assert(tree.Search(14));
		assert(!tree.Search(12));
		assert(!tree.Search(20));
		assert(tree.Search(2));
		assert(!tree.Search(9));
		assert(tree.Search(13));
		assert(tree.Search(18));
		assert(tree.Search(1));
		assert(tree.Search(25));
		assert(tree.Search(5));
		assert(tree.Search(8));
		assert(!tree.Search(10));
		assert(!tree.Search(3));

		{
			expected.clear();
			actual.clear();

			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(5);
			expected.push_back(8);
			expected.push_back(13);
			expected.push_back(14);
			expected.push_back(18);
			expected.push_back(25);

			rootNode = tree.GetRootNode().lock();

			actual = tree.TraverseInOrder(rootNode);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}
	}

	void TestOnlyRightTree()
	{
		BinarySearchTree<int> tree;
		std::vector<int> expected;
		std::vector<int> actual;
		std::shared_ptr<TreeNode<int>> rootNode;

		expected.reserve(64);
		actual.reserve(64);

		tree.Insert(std::make_unique<int>(1));
		tree.Insert(std::make_unique<int>(2));
		tree.Insert(std::make_unique<int>(3));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(7));
		tree.Insert(std::make_unique<int>(8));
		tree.Insert(std::make_unique<int>(9));
		tree.Insert(std::make_unique<int>(10));

		rootNode = tree.GetRootNode().lock();

		{
			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(4);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(7);
			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);

			actual = tree.TraverseInOrder(rootNode);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(4);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(7);
			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);

			actual = tree.TraverseInOrder(rootNode->Right);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(3);
			expected.push_back(4);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(7);
			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);

			actual = tree.TraverseInOrder(rootNode->Right->Right);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		assert(tree.Search(10));
		assert(tree.Search(9));
		assert(tree.Search(8));
		assert(tree.Search(7));
		assert(tree.Search(6));
		assert(tree.Search(5));
		assert(tree.Search(4));
		assert(tree.Search(3));
		assert(tree.Search(2));
		assert(tree.Search(1));
		assert(!tree.Search(-1));

		assert(tree.Delete(1));
		assert(tree.Delete(10));
		assert(tree.Delete(5));

		assert(!tree.Search(1));
		assert(!tree.Search(10));
		assert(!tree.Search(5));
	}

	void TestOnlyLeftTree()
	{
		BinarySearchTree<int> tree;
		std::vector<int> expected;
		std::vector<int> actual;
		std::shared_ptr<TreeNode<int>> rootNode;

		expected.reserve(64);
		actual.reserve(64);

		tree.Insert(std::make_unique<int>(10));
		tree.Insert(std::make_unique<int>(9));
		tree.Insert(std::make_unique<int>(8));
		tree.Insert(std::make_unique<int>(7));
		tree.Insert(std::make_unique<int>(6));
		tree.Insert(std::make_unique<int>(5));
		tree.Insert(std::make_unique<int>(4));
		tree.Insert(std::make_unique<int>(3));
		tree.Insert(std::make_unique<int>(2));
		tree.Insert(std::make_unique<int>(1));

		rootNode = tree.GetRootNode().lock();

		{
			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(4);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(7);
			expected.push_back(8);
			expected.push_back(9);
			expected.push_back(10);

			actual = tree.TraverseInOrder(rootNode);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(4);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(7);
			expected.push_back(8);
			expected.push_back(9);

			actual = tree.TraverseInOrder(rootNode->Left);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		{
			expected.clear();
			actual.clear();

			expected.push_back(1);
			expected.push_back(2);
			expected.push_back(3);
			expected.push_back(4);
			expected.push_back(5);
			expected.push_back(6);
			expected.push_back(7);
			expected.push_back(8);

			actual = tree.TraverseInOrder(rootNode->Left->Left);

			for (size_t i = 0; i < expected.size(); ++i)
			{
				assert(expected[i] == actual[i]);
			}
		}

		assert(tree.Search(10));
		assert(tree.Search(9));
		assert(tree.Search(8));
		assert(tree.Search(7));
		assert(tree.Search(6));
		assert(tree.Search(5));
		assert(tree.Search(4));
		assert(tree.Search(3));
		assert(tree.Search(2));
		assert(tree.Search(1));
		assert(!tree.Search(-1));

		assert(tree.Delete(1));
		assert(tree.Delete(10));
		assert(tree.Delete(5));

		assert(!tree.Search(1));
		assert(!tree.Search(10));
		assert(!tree.Search(5));
	}
}