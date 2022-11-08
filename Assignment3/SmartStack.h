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
		T mSum;
		T mSquareSum;

		std::stack<T> mMainStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0)
		, mSquareSum(0)
	{
		mMaxStack.push(std::numeric_limits<T>::lowest());
		mMinStack.push(std::numeric_limits<T>::max());
	}

	template<typename T>
	void SmartStack<T>::Push(const T number)
	{
		mMainStack.push(number);
		mSum += number;
		mSquareSum = mSquareSum + number * number;

		const T MAX = mMaxStack.top() < number ? number : mMaxStack.top();
		const T MIN = mMinStack.top() > number ? number : mMinStack.top();

		mMaxStack.push(MAX);
		mMinStack.push(MIN);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T result = mMainStack.top();

		mMainStack.pop();
		mMaxStack.pop();
		mMinStack.pop();

		mSum -= result;
		mSquareSum = mSquareSum - result * result;

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
		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		return mMinStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		return static_cast<double>(mSum) / mMainStack.size();
	}

	template<typename T>
	double SmartStack<T>::GetVariance() const
	{
		const double SQUARE_AVERAGE = pow(GetAverage(), 2);

		return static_cast<double>(mSquareSum) / mMainStack.size() - SQUARE_AVERAGE;
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
}
