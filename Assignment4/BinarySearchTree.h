#pragma once

#include <cassert>
#include <memory>
#include <vector>

#include "TreeNode.h"

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree() = default;
		BinarySearchTree(const BinarySearchTree& other) = default;
		~BinarySearchTree() = default;
		BinarySearchTree& operator=(const BinarySearchTree& other) = default;

		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		void insertRecursive(std::shared_ptr<TreeNode<T>> rootNode, std::unique_ptr<T> data);
		std::shared_ptr<TreeNode<T>> searchOrNullRecursive(std::shared_ptr<TreeNode<T>> rootNode, const T& data);
		std::shared_ptr<TreeNode<T>> getSmallerLeafNodeRecursive(std::shared_ptr<TreeNode<T>> startNode);
		std::shared_ptr<TreeNode<T>> getGreaterLeafNodeRecursive(std::shared_ptr<TreeNode<T>> startNode);
		
		static void traverseRecursive(std::vector<T>& outNodes, const std::shared_ptr<TreeNode<T>> currentNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;

	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			std::shared_ptr<TreeNode<T>> node = std::make_shared<TreeNode<T>>(std::move(data));
			mRoot = node;
			return;
		}

		insertRecursive(mRoot, std::move(data));
	}

	template<typename T>
	void BinarySearchTree<T>::insertRecursive(std::shared_ptr<TreeNode<T>> rootNode, std::unique_ptr<T> data)
	{
		if (*rootNode->Data >= *data)
		{
			if (rootNode->Left == nullptr)
			{
				auto newNode = std::make_shared<TreeNode<T>>(rootNode, std::move(data));
				rootNode->Left = newNode;
				return;
			}

			return insertRecursive(rootNode->Left, std::move(data));
		}

		if (*rootNode->Data < *data)
		{
			if (rootNode->Right == nullptr)
			{
				auto newNode = std::make_shared<TreeNode<T>>(rootNode, std::move(data));
				rootNode->Right = newNode;
				return;
			}

			return insertRecursive(rootNode->Right, std::move(data));
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (searchOrNullRecursive(mRoot, data) == nullptr)
		{
			return false;
		}

		return true;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::searchOrNullRecursive(std::shared_ptr<TreeNode<T>> rootNode, const T& data)
	{
		if (rootNode == nullptr)
		{
			return nullptr;
		}
		else if (*rootNode->Data == data)
		{
			return rootNode;
		}

		if (*rootNode->Data > data)
		{
			return searchRecursive(rootNode->Left, data);
		}

		if (*rootNode->Data < data)
		{
			return searchRecursive(rootNode->Right, data);
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> foundNode = searchOrNullRecursive(mRoot, data);

		if (foundNode == nullptr)
		{
			return false;
		}
		else if (foundNode->Left == nullptr && foundNode->Right == nullptr)
		{
			std::shared_ptr<TreeNode<T>> parentNode = foundNode->Parent.lock();

			if (parentNode->Left >= foundNode)
			{
				parentNode->Left = nullptr;
			}
			else
			{
				parentNode->Right = nullptr;
			}

			return true;
		}

		std::shared_ptr<TreeNode<T>> parentNode = foundNode->Parent.lock();
		std::shared_ptr<TreeNode<T>> leafNode;

		if (foundNode->Left != nullptr)
		{
			leafNode = getSmallerLeafNodeRecursive(foundNode->Left); // return 하기 전에 부모 노드에 return
			assert(leafNode != nullptr);
			assert(*foundNode->Data >= *leafNode->Data);
		}
		else
		{
			leafNode = getGreaterLeafNodeRecursive(foundNode->Right);
			assert(leafNode != nullptr);
			assert(*foundNode->Data < *leafNode->Data);
		}
		
		assert(leafNode->Left == nullptr);
		assert(leafNode->Right == nullptr);

		leafNode->Left = foundNode->Left;
		leafNode->Right = foundNode->Right;
		leafNode->Parent = parentNode;

		if (*parentNode->Data >= *leafNode->Data)
		{
			parentNode->Left = leafNode;
		}
		else
		{
			parentNode->Right = leafNode;
		}

		return true;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getSmallerLeafNodeRecursive(std::shared_ptr<TreeNode<T>> startNode)
	{
		if (startNode->Left == nullptr && startNode->Right == nullptr)
		{
			std::shared_ptr<TreeNode<T>> parent = startNode->Parent.lock();

			if (parent->Left == startNode)
			{
				parent->Left = nullptr;
			}
			else
			{
				parent->Right = nullptr;
			}

			return startNode;
		}

		if (startNode->Right == nullptr)
		{
			return getSmallerLeafNodeRecursive(startNode->Left);
		}
		else
		{
			return getSmallerLeafNodeRecursive(startNode->Right);
		}
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getGreaterLeafNodeRecursive(std::shared_ptr<TreeNode<T>> startNode)
	{
		if (startNode->Left == nullptr && startNode->Right == nullptr)
		{
			if (parent->Left == startNode)
			{
				parent->Left = nullptr;
			}
			else
			{
				parent->Right = nullptr;
			}
			
			return startNode;
		}

		if (startNode->Left == nullptr)
		{
			return getGreaterLeafNodeRecursive(startNode->Right);
		}
		else
		{
			return getGreaterLeafNodeRecursive(startNode->Left);
		}
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		traverseRecursive(v, startNode);

		return v;
	}

	template<typename T>
	void BinarySearchTree<T>::traverseRecursive(std::vector<T>& outNodes, const std::shared_ptr<TreeNode<T>> currentNode)
	{
		if (currentNode == nullptr)
		{
			return;
		}

		traverseRecursive(outNodes, currentNode->Left);
		outNodes.push_back(*currentNode->Data);
		traverseRecursive(outNodes, currentNode->Right);
	}
}