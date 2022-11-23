#pragma once

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
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return false;
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