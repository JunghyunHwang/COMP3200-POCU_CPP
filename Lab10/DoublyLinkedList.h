#pragma once

#include <cassert>
#include <memory>
#include <iostream>

namespace lab10
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
		void PrintList() const;
		bool CheckList(int* listArray) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		unsigned int mSize;
		std::shared_ptr<Node<T>> mHead;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mSize(0)
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
		if (mSize == 0)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			++mSize;
			return;
		}
		else if (index == 0)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
			
			newNode->Next = mHead;
			mHead->Previous = newNode;
			mHead = newNode;

			++mSize;
			return;
		}

		std::shared_ptr<Node<T>> pNode = mHead;

		if (index >= mSize)
		{
			while (pNode->Next != nullptr)
			{
				pNode = pNode->Next;
			}

			auto newNode = std::make_shared<Node<T>>(std::move(data), pNode);

			pNode->Next = newNode;
			++mSize;
			return;
		}

		unsigned int nodeCount = 0;

		while (nodeCount++ < index)
		{
			assert(pNode != nullptr);
			pNode = pNode->Next;
		}

		std::shared_ptr<Node<T>> prevNode = pNode->Previous.lock();
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), prevNode);

		prevNode->Next = newNode;
		newNode->Next = pNode;
		pNode->Previous = newNode;
		++mSize;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mSize == 0)
		{
			return false;
		}

		std::shared_ptr<Node<T>> pNode = mHead;

		while (pNode != nullptr)
		{
			if (*pNode->Data == data)
			{
				break;
			}

			pNode = pNode->Next;
		}

		if (pNode == nullptr)
		{
			return false;
		}

		if (pNode == mHead)
		{
			if (pNode->Next == nullptr)
			{
				mHead = nullptr;
				goto DECREASE_SIZE;
			}

			std::shared_ptr<Node<T>> nextNode = pNode->Next;

			mHead = nextNode;
			pNode = nullptr;
			goto DECREASE_SIZE;
		}

		if (pNode->Next == nullptr)
		{
			std::shared_ptr<Node<T>> prevNode = pNode->Previous.lock();

			prevNode->Next = nullptr;
		}
		else
		{
			std::shared_ptr<Node<T>> prevNode = pNode->Previous.lock();
			std::shared_ptr<Node<T>> nextNode = pNode->Next;

			assert(prevNode->Next == pNode);
			assert(nextNode->Previous.lock() == pNode);

			prevNode->Next = nextNode;
			nextNode->Previous = prevNode;
			pNode = nullptr;
		}

	DECREASE_SIZE:
		--mSize;

		return true;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> pNode = mHead;

		while (pNode != nullptr)
		{
			if (*pNode->Data == data)
			{
				return true;
			}

			pNode = pNode->Next;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mSize)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> pNode = mHead;
		unsigned int count = 0;

		while (count++ < index)
		{
			assert(pNode != nullptr);
			pNode = pNode->Next;
		}

		return pNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}

	template<typename T>
	void DoublyLinkedList<T>::PrintList() const
	{
		std::shared_ptr<Node<T>> pNode = mHead;

		while (pNode != nullptr)
		{
			std::cout << *pNode->Data << " -> ";
			pNode = pNode->Next;
		}

		std::cout << std::endl;
	}

	template<typename T>
	bool DoublyLinkedList<T>::CheckList(int* listArray) const
	{
		unsigned int index = 0;

		std::shared_ptr<Node<T>> pNode = mHead;

		while (pNode != nullptr)
		{
			if (*pNode->Data != listArray[index++])
			{
				return false;
			}

			pNode = pNode->Next;
		}

		return true;
	}
}