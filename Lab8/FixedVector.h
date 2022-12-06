#pragma once

#include <cassert>

namespace lab8
{
	template<class T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<T, N>& other);
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
		enum { NOT_FOUND = -1};
		size_t mSize;
		T mMainArray[N];
	};

	template<class T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<class T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector<T, N>& other)
		: mSize(other.mSize)
	{
		
	}

	template<class T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			return false;
		}

		mMainArray[mSize++] = t;

		return true;
	}

	template<class T, size_t N>
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

		--mSize;

		return true;
	}

	template<class T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int i) const
	{
		return mMainArray[i];
	}

	template<class T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int i)
	{
		return mMainArray[i];
	}

	template<class T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mMainArray[i] == t)
			{
				return i;
			}
		}

		return NOT_FOUND;
	}

	template<class T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<class T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}

