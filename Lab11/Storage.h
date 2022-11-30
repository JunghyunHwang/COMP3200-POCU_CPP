#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		~Storage() = default;

		Storage(const Storage<T>& other);
		Storage& operator=(const Storage<T>& rhs);
		Storage(Storage<T>&& other);
		Storage& operator=(Storage<T>&& rhs);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		unsigned int mCapacity;
		std::unique_ptr<T[]> mDatas;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mCapacity(length)
	{
		mDatas = std::make_unique<T[]>(mCapacity);

		memset(mDatas.get(), 0, mCapacity * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mCapacity(length)
	{
		mDatas = std::make_unique<T[]>(mCapacity);

		for (size_t i = 0; i < mCapacity; ++i)
		{
			mDatas[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		:  mCapacity(other.mCapacity)
	{
		mDatas = std::make_unique<T[]>(mCapacity);
		memcpy(mDatas.get(), other.mDatas.get(), mCapacity * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(Storage&& other)
		: mCapacity(other.mCapacity)
	{
		mDatas = std::move(other.mDatas);

		other.mDatas = nullptr;
		other.mCapacity = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mCapacity = rhs.mCapacity;

		mDatas = nullptr;
		mDatas = std::make_unique<T[]>(mCapacity);
		memcpy(mDatas.get(), rhs.mDatas.get(), mCapacity * sizeof(T));

		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mCapacity = rhs.mCapacity;

		mDatas = nullptr;
		mDatas = std::move(rhs.mDatas);

		rhs.mCapacity = 0;
		rhs.mDatas = nullptr;

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mCapacity)
		{
			return false;
		}

		mDatas[index] = data;

		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mDatas;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mCapacity;
	}
}