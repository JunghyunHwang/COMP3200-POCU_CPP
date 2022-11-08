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
		T mSum;
		T mSquareSum;
		std::queue<T> mMainQueue;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSquareSum(0)
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(const T number)
	{
		mMainQueue.push(number);
		mSum += number;
		mSquareSum = mSquareSum + number * number;
	}

	template<typename T>
	T SmartQueue<T>::Peek() const
	{
		if (mMainQueue.size() == 0)
		{
			assert(false);
		}

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

		mSum -= result;
		mSquareSum = mSquareSum - result * result;

		return result;
	}

	template<typename T>
	T SmartQueue<T>::GetMax() const
	{
		if (mMainQueue.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		std::queue<T> copied = mMainQueue;
		T max = copied.front();
		copied.pop();

		while (copied.size() != 0)
		{
			T tmp = copied.front();
			copied.pop();

			if (max < tmp)
			{
				max = tmp;
			}
		}

		return max;
	}

	template<typename T>
	T SmartQueue<T>::GetMin() const
	{
		if (mMainQueue.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		std::queue<T> copied = mMainQueue;
		T min = copied.front();
		copied.pop();

		while (copied.size() != 0)
		{
			T tmp = copied.front();
			copied.pop();

			if (min > tmp)
			{
				min = tmp;
			}
		}

		return min;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		return static_cast<double>(mSum) / static_cast<double>(mMainQueue.size());
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		double squareAverage = static_cast<double>(mSquareSum) / static_cast<double>(mMainQueue.size());

		return (squareAverage - pow(GetAverage(), 2));
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
}
