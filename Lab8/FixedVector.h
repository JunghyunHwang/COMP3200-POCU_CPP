#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other);
		virtual ~FixedVector();
		FixedVector& operator=(const FixeVector& rhs);

	private:
		size_t mSize;
		size_t mCapacity;
		T* mMainArray;
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
		, mCapacity(N)
	{
		mMainArray = new T[mCapacity];
	}

	template<typename T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
		delete[] mMainArray;
	}

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector& other)
		: mSize(other.mSize)
		, mCapacity(other.mCapacity)
	{
		mMainArray = new T[mCapacity];

		for (size_t i = 0; i < other.mSize; ++i)
		{
			mMainArray[i] = other.mMainArray[i];
		}
	}
}

