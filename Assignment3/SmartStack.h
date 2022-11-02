#pragma once
#include <limits>
#include <stack>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();

		void Push(const T number);
		T Pop();
		T Peek() const;

		inline T GetMax() const;
		inline T GetMin() const;
		inline T GetSum() const;
		inline double GetAverage() const;

	private:
		T mMax;
		T mMin;
		T mSum;
		std::stack<T> mMainStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mMax(std::numeric_limits<T>::min())
		, mMin(std::numeric_limits<T>::max())
		, mSum(0)
	{
	}

	template<typename T>
	void SmartStack<T>::Push(const T number)
	{
		mMainStack.push(number);

		if (mMax < number)
		{
			mMax = number;
		}

		if (mMin > number)
		{
			mMin = number;
		}

		mMaxStack.push(mMax);
		mMinStack.push(mMin);
		mSum += number;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T result = mMainStack.top();

		mMainStack.pop();
		mMaxStack.pop();
		mMinStack.pop();
		mSum -= result;

		return result;
	}

	template<typename T>
	T SmartStack<T>::Peek() const
	{
		return mMainStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax() const
	{
		return mMax;
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		return mMin;
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		return mSum / static_cast<double>(mMainStack.size());
	}
}
