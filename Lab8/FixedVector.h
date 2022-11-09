#pragma once

#include <cassert>

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other) = default;
		virtual ~FixedVector() = default;
		FixedVector<T, N>& operator=(const FixedVector<T, N>& rhs) = default;

		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(unsigned int i) const;
		T& operator[](unsigned int i);
		int GetIndex(const T& t) const;

		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		enum { NOTFOUND = -1};
		size_t mSize;
		T mMainArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			assert(false);
			return false;
		}

		mMainArray[mSize++] = t;

		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		size_t i;
		
		for (i = 0; i < mSize; ++i)
		{
			if (mMainArray[i] == t)
			{
				break;
			}
		}

		if (i == mSize)
		{
			return false;
		}

		for (; i < N - 1; ++i)
		{
			mMainArray[i] = mMainArray[i + 1];
		}

		return true;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int i) const
	{
		return mMainArray[i];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int i)
	{
		return mMainArray[i];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		for (int i = 0; i < mSize; ++i)
		{
			if (mMainArray[i] == t)
			{
				return i;
			}
		}

		return NOTFOUND;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}

