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
	
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& other);
		virtual ~FixedVector() = default;
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& rhs);

		bool Add(const bool value);
		bool Remove(const bool value);
		bool Get(unsigned int i) const;
		bool operator[](unsigned int i);
		int GetIndex(const bool value) const;

		void Clear();

		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		enum 
		{ 
			NOT_FOUND = -1,
			BIT_SIZE = 32
		};
		size_t mSize;
		size_t mArrayCapacity;
		unsigned int mMainArray[(N + 31) / BIT_SIZE] = { 0, };
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mArrayCapacity((N + 31) / BIT_SIZE)
	{
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& other)
		: mSize(other.mSize)
	{
		for (size_t i = 0; i < mArrayCapacity; ++i)
		{
			mMainArray[i] = other.mMainArray[i];
		}
	}

	template<size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mSize = rhs.mSize;

		for (size_t i = 0; i < mArrayCapacity; ++i)
		{
			mMainArray[i] = rhs.mMainArray[i];
		}

		return *this;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool value)
	{
		if (mSize >= N)
		{
			return false;
		}

		if (value)
		{
			unsigned int mask = mMainArray[mSize / BIT_SIZE];
			mask = mask | (1 << mSize % BIT_SIZE);

			mMainArray[mSize / BIT_SIZE] = mask;
		}

		++mSize;

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool value)
	{
		int bitIndex = GetIndex(value);

		if (static_cast<int>(bitIndex) == NOT_FOUND)
		{
			return false;
		}

		unsigned int arrayIndex = bitIndex / BIT_SIZE;
		unsigned int origin = mMainArray[arrayIndex];

		unsigned int lBits = (0xffffffff << bitIndex % BIT_SIZE);
		unsigned int rBits = ~(0xffffffff << bitIndex % BIT_SIZE);

		lBits &= origin;
		rBits &= origin;
		lBits = lBits >> 1;

		if (bitIndex != 0)
		{
			unsigned int mask = ~(1 << (bitIndex % BIT_SIZE - 1));
			lBits &= mask;
		}

		origin = lBits | rBits;

		mMainArray[arrayIndex] = origin;

		for (size_t i = arrayIndex; i < mArrayCapacity - 1; ++i)
		{
			unsigned int overBit = 1;
			overBit = (overBit & mMainArray[i + 1]) << 31;
			mMainArray[i + 1] = mMainArray[i + 1] >> 1;

			if (overBit == 0)
			{
				overBit = ~overBit >> 1;
				mMainArray[i] &= overBit;
			}
			else
			{
				mMainArray[i] |= overBit;
			}
		}

		--mSize;

		return true;
	}

	template<size_t N>
	void FixedVector<bool, N>::Clear()
	{
		mSize = 0;

		for (size_t i = 0; i < mArrayCapacity; ++i)
		{
			mMainArray[i] = 0;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(unsigned int i) const
	{
		unsigned int bitflag = mMainArray[i / BIT_SIZE];

		bitflag &= (1 << i % BIT_SIZE);

		return bitflag;
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int i)
	{
		return Get(i);
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool value) const
	{
		for (size_t i = 0; i <= mSize / BIT_SIZE; ++i)
		{
			unsigned int bitflag = mMainArray[i];

			for (size_t j = 0; j < BIT_SIZE; ++j)
			{
				if (i * BIT_SIZE + j >= mSize)
				{
					return NOT_FOUND;
				}

				bool result = (bitflag | 1 << j) == mMainArray[i];

				if (result == value)
				{
					return i * BIT_SIZE + j;
				}
			}
		}

		return NOT_FOUND;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}

