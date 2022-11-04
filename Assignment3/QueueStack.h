#pragma once

#include <cassert>
#include <queue>
#include <stack>

#include "SmartStack.h"

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		void Enqueue(const T number);
		T Peek() const;
		T Dequeue();

		T GetMin() const;
		T GetMax() const;
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;

		inline unsigned int GetStackCount() const;

	private:
		void addStack();
		void removeStack();

	private:
		unsigned int mMaxStackSize;
		unsigned int mTotalElementCount;
		T mSum;
		std::queue<SmartStack<T>> mQueueStack;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mTotalElementCount(0)
		, mSum(0)
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(const T number)
	{
		if (mQueueStack.size() == 0 || mQueueStack.back().GetCount() >= mMaxStackSize)
		{
			addStack();
		}

		mQueueStack.back().Push(number);
		++mTotalElementCount;
		mSum += number;
	}

	template<typename T>
	T QueueStack<T>::Peek() const
	{
		return mQueueStack.front().Peek();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		if (mQueueStack.size() == 0)
		{
			assert(false);
		}

		T result = mQueueStack.front().Pop();
		--mTotalElementCount;
		mSum -= result;

		if (mQueueStack.front().GetCount() == 0)
		{
			removeStack();
		}

		return result;
	}

	template<typename T>
	T QueueStack<T>::GetMax() const
	{
		if (mQueueStack.size() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		std::queue<SmartStack<T>> copiedQueueStack = mQueueStack;
		T result = copiedQueueStack.front().GetMax();
		copiedQueueStack.pop();

		while (copiedQueueStack.size() != 0)
		{
			T value = copiedQueueStack.front().GetMax();

			if (result < value)
			{
				result = value;
			}

			copiedQueueStack.pop();
		}

		return result;
	}

	template<typename T>
	T QueueStack<T>::GetMin() const
	{
		if (mQueueStack.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		std::queue<SmartStack<T>> copiedQueueStack = mQueueStack;
		T result = copiedQueueStack.front().GetMin();
		copiedQueueStack.pop();

		while (copiedQueueStack.size() != 0)
		{
			T value = copiedQueueStack.front().GetMin();

			if (result > value)
			{
				result = value;
			}

			copiedQueueStack.pop();
		}

		return result;
	}

	template<typename T>
	double QueueStack<T>::GetAverage() const
	{
		return mSum / static_cast<double>(mTotalElementCount);
	}

	template<typename T>
	T QueueStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return mTotalElementCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mQueueStack.size();
	}

	template<typename T>
	void QueueStack<T>::addStack()
	{
		assert(mQueueStack.size() == 0 || mQueueStack.back().GetCount() == mMaxStackSize);

		SmartStack<T> tmp;
		mQueueStack.push(tmp);
	}

	template<typename T>
	void QueueStack<T>::removeStack()
	{
		assert(mQueueStack.size() != 0 || mQueueStack.front().GetCount() == 0);
		mQueueStack.pop();
	}
}
