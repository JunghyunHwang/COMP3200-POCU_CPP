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

		checkStackCount();
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

		checkStackCount();

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
		double squareAverage = static_cast<double>(mSquareSum) / mMainStack.size();

		return (squareAverage - pow(GetAverage(), 2));
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
		return (mMainStack.size() + 1 == mMaxStack.size() && mMaxStack.size() == mMinStack.size() && mMinStack.size() == mMainStack.size() + 1);
	}
}
