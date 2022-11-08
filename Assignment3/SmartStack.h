#pragma once

#include <cassert>
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
		inline double GetVariance() const;
		inline double GetStandardDeviation() const;
		inline unsigned int GetCount() const;

	private:
		bool checkStackCount() const;

	private:
		double mSum;
		double mSquareSum;
		std::stack<T> mMainStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0)
		, mSquareSum(0)
	{
	}

	template<typename T>
	void SmartStack<T>::Push(const T number)
	{
		mMainStack.push(number);
		mSum += number;
		mSquareSum = mSquareSum + number * number;

		const T MAX = mMaxStack.size() == 0 || mMaxStack.top() < number ? number : mMaxStack.top();
		const T MIN = mMinStack.size() == 0 || mMinStack.top() > number ? number : mMinStack.top();

		mMaxStack.push(MAX);
		mMinStack.push(MIN);

		checkStackCount();
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		if (mMainStack.size() == 0)
		{
			assert(false);
		}

		T result = mMainStack.top();

		mMainStack.pop();
		mMaxStack.pop();
		mMinStack.pop();

		mSum -= result;
		mSquareSum = mSquareSum - result * result;

		checkStackCount();

		return result;
	}

	template<typename T>
	T SmartStack<T>::Peek() const
	{
		if (mMainStack.size() == 0)
		{
			assert(false);
		}

		return mMainStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax() const
	{
		if (mMaxStack.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		if (mMinStack.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		return mMinStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		return mSum / mMainStack.size();
	}

	template<typename T>
	double SmartStack<T>::GetVariance() const
	{
		return (mSquareSum / mMainStack.size() - pow(GetAverage(), 2));
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation() const
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mMainStack.size();
	}
	
	template<typename T>
	bool SmartStack<T>::checkStackCount() const
	{
		return (mMainStack.size() == mMaxStack.size() && mMaxStack.size() == mMinStack.size() && mMinStack.size() == mMainStack.size());
	}
}
