#pragma once

#include <cassert>
#include <memory>

namespace test
{
	template<typename T>
	class MyArray
	{
	public:
		MyArray();
		MyArray(unsigned int capacity);
		~MyArray() = default;

		MyArray(const MyArray& other);
		MyArray<T>& operator=(const MyArray& rhs);

		MyArray(MyArray&& other);
		MyArray<T>& operator=(MyArray&& rhs);

		const T& operator[](unsigned int i) const;

		void Add(const T data);
		inline unsigned int GetSize() const;
		inline unsigned int GetCapacity() const;

	private:
		enum { DEFAULT_CAPACITY = 10 };
		unsigned int mSize;
		unsigned int mCapacity;
		std::unique_ptr<T[]> mData;
	};

	template<typename T>
	MyArray<T>::MyArray()
		: mSize(0)
		, mCapacity(DEFAULT_CAPACITY)
		, mData(std::make_unique<T[]>(mCapacity))
	{
	}

	template<typename T>
	MyArray<T>::MyArray(unsigned int capacity)
		: mSize(0)
		, mCapacity(capacity)
		, mData(std::make_unique<T[]>(mCapacity))
	{
	}

	template<typename T>
	MyArray<T>::MyArray(const MyArray& other)
		: mSize(other.mSize)
		, mCapacity(other.mCapacity)
		, mData(std::make_unique<T[]>(mCapacity))
	{
		memcpy(mData.get(), other.mData.get(), sizeof(T) * mSize);
	}

	template<typename T>
	MyArray<T>& MyArray<T>::operator=(const MyArray& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mSize = rhs.mSize;
		mCapacity = rhs.mCapacity;
		
		mData = nullptr;
		mData = std::make_unique<T[]>(mCapacity);

		memcpy(mData.get(), rhs.mData.get(), sizeof(T) * mSize);
	}

	template<typename T>
	MyArray<T>::MyArray(MyArray&& other)
		: mSize(other.mSize)
		, mCapacity(other.mCapacity)
		, mData(std::move(other.mData))
	{
		other.mSize = 0;
		other.mCapacity = 0;
	}

	template<typename T>
	MyArray<T>& MyArray<T>::operator=(MyArray&& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mSize = rhs.mSize;
		mCapacity = rhs.mCapacity;
		mData = std::move(rhs.mData);

		rhs.mSize = 0;
		rhs.mCapacity = 0;
	}

	template<typename T>
	void MyArray<T>::Add(const T data)
	{
		if (mSize >= mCapacity)
		{
			mCapacity *= 2;
			auto tmp = std::make_unique<T[]>(mCapacity);

			memcpy(tmp.get(), mData.get(), sizeof(T) * mSize);
			mData = std::move(tmp);
		}

		mData[mSize++] = data;
	}

	template<typename T>
	const T& MyArray<T>::operator[](unsigned int i) const
	{
		if (i >= mSize)
		{
			assert(false);
		}

		return mData[i];
	}

	template<typename T>
	unsigned int MyArray<T>::GetSize() const
	{
		return mSize;
	}

	template<typename T>
	unsigned int MyArray<T>::GetCapacity() const
	{
		return mCapacity;
	}
}