#pragma once

#include <cassert>
#include <queue>
#include <memory>

namespace lab9
{
	template<typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool& rhs) = delete;

		T* Get();
		void Return(T* object);
		inline size_t GetFreeObjectCount() const;
		inline size_t GetMaxFreeObjectCount() const;

	private:
		size_t mSize;
		size_t mMaxPoolSize;
		std::queue<T*> mObjectPool;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mSize(0)
		, mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			delete mObjectPool.front();
			mObjectPool.pop();
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mSize == 0)
		{
			return new T();
		}

		assert(mObjectPool.size() != 0);

		T* result = mObjectPool.front();
		mObjectPool.pop();
		--mSize;

		return result;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (mSize == mMaxPoolSize)
		{
			delete object;
			return;
		}

		mObjectPool.push(object);
		++mSize;
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mSize;
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}
