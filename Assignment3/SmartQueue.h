#pragma once

#include <cassert>
#include <limits>
#include <queue>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		inline void Enqueue(const T number);
		inline T Peek() const;
		inline T Dequeue();
		inline T GetMax() const;
		inline T GetMin() const;
		inline double GetAverage() const;
		inline T GetSum() const;
		inline double GetVariance() const;
		inline double GetStandardDeviation() const;
		inline unsigned int GetCount() const;

	private:
		bool checkPostcondition() const;

	private:
		T mSum;
		T mSquareSum;
		std::queue<T> mMainQueue;
		std::queue<T> mMaxQueue;
		std::queue<T> mMinQueue;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSquareSum(0)
	{
		mMaxQueue.push(std::numeric_limits<T>::max());
		mMinQueue.push(std::numeric_limits<T>::min());
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(const T number)
	{
		mMainQueue.push(number);
		mSum += number;
		mSquareSum = mSquareSum + number * number;

		const T MAX = mMaxQueue.back() < number ? number : mMaxQueue.back();
		const T MIN = mMinQueue.back() > number ? number : mMinQueue.back();

		mMaxQueue.push(MAX);
		mMinQueue.push(MIN);

		assert(checkPostcondition());
	}

	template<typename T>
	T SmartQueue<T>::Peek() const
	{
		return mMainQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		if (mMainQueue.size() == 0)
		{
			assert(false);
		}

		T result = mMainQueue.front();
		
		mMainQueue.pop();
		mMaxQueue.pop();
		mMinQueue.pop();

		mSum -= result;
		mSquareSum = mSquareSum - result * result;

		assert(checkPostcondition());
		return result;
	}

	template<typename T>
	T SmartQueue<T>::GetMax() const
	{
		if (mMainQueue.size() == 0)
		{
			assert(mMaxQueue.back() == std::numeric_limits<T>::min());
		}

		return mMaxQueue.back();
	}

	template<typename T>
	T SmartQueue<T>::GetMin() const
	{
		if (mMainQueue.size() == 0)
		{
			assert(mMinQueue.back() == std::numeric_limits<T>::max());
		}

		return mMinQueue.back();
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		return mSum / static_cast<double>(mMainQueue.size());
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		double AVERAGE = GetAverage();
		return mSquareSum / static_cast<double>(mMainQueue.size()) - AVERAGE * AVERAGE;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mMainQueue.size();
	}

	template<typename T>
	bool SmartQueue<T>::checkPostcondition() const
	{
		return mMaxQueue.size() == mMinQueue.size()
			&& mMainQueue.size() == mMaxQueue.size() - 1
			&& mMainQueue.size() == mMinQueue.size() - 1;
	}
}
