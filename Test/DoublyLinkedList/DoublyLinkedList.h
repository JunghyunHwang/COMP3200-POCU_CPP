#pragma once

#include <cassert>
#include <memory>

#include "Node.h"

namespace test
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> getNodeOrNull(unsigned int index) const;
		std::shared_ptr<Node<T>> getNodeOrNull(const T& data) const;

	private:
		unsigned int mSize;
		std::shared_ptr<Node<T>> mHead;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mSize(0)
		, mHead(nullptr)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		Insert(std::move(data), mSize);
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

		if (mHead == nullptr)
		{
			mHead = newNode;
		}
		else if (index >= mSize)
		{
			std::shared_ptr<Node<T>> lastNode = getNodeOrNull(mSize - 1);
			lastNode->Next = newNode;
			newNode->Previous = lastNode;
		}
		else
		{
			std::shared_ptr<Node<T>> targetNode = getNodeOrNull(index);
			std::shared_ptr<Node<T>> prev = targetNode->Previous.lock();

			if (prev == nullptr)
			{
				mHead = newNode;
				targetNode->Previous = newNode;
			}
			else
			{
				newNode->Previous = prev;
				newNode->Next = targetNode;
				targetNode->Previous = newNode;
				prev->Next = newNode;
			}
		}

		++mSize;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> deleteNode = getNodeOrNull(data);

		if (deleteNode == nullptr)
		{
			return false;
		}

		std::shared_ptr<Node<T>> prev = deleteNode->Previous.lock();
		std::shared_ptr<Node<T>> next = deleteNode->Next;

		if (prev == nullptr)
		{
			mHead = next;
		}
		else if (next == nullptr)
		{
			prev->Next = nullptr;
		}
		else
		{
			prev->Next = next;
			next->Previous = prev;
		}

		--mSize;

		return true;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		return (getNodeOrNull(data) != nullptr);
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mSize)
		{
			return nullptr;
		}

		return getNodeOrNull(index);
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::getNodeOrNull(unsigned int index) const
	{
		std::shared_ptr<Node<T>> head = mHead;

		for (uint32_t i = 0; i < index; ++i)
		{
			head = head->Next;
		}

		return head;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::getNodeOrNull(const T& data) const
	{
		std::shared_ptr<Node<T>> head = mHead;

		while (head != nullptr)
		{
			if (*head->Data == data)
			{
				break;
			}

			head = head->Next;
		}

		return head;
	}
}