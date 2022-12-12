#pragma once

#include <cassert>
#include <memory>

namespace test
{
    template<typename T>
    class MyStack final
    {
    public:
        MyStack();
        ~MyStack() = default;
        MyStack(const MyStack& other);
        MyStack<T>& operator=(const MyStack<T>& rhs);

        void Push(const T data);
        T Pop();
        const T& Top() const;
        void Clear();

        unsigned int GetSize() const;
        unsigned int GetCapacity() const;

    private:
        enum { DEFAULT_CAPACITY = 64 };
        unsigned int mCapacity;
        unsigned int mSize;
        std::unique_ptr<T[]> mData;
    };

    template<typename T>
    MyStack<T>::MyStack()
        : mSize(0)
        , mCapacity(DEFAULT_CAPACITY)
        , mData(std::make_unique<T[]>(mCapacity))
    {
    }

    template<typename T>
    MyStack<T>::MyStack(const MyStack& other)
        : mSize(other.mSize)
        , mCapacity(other.mCapacity)
        , mData(std::make_unique<T[]>(mCapacity))
    {
        memcpy(mData.get(), other.mData.get(), sizeof(T) * mSize);
    }

    template<typename T>
    MyStack<T>& MyStack<T>::operator=(const MyStack<T>& rhs)
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
    void MyStack<T>::Push(const T data)
    {
        if (mSize >= mCapacity)
        {
            mCapacity *= 2;

            auto tmp = std::make_unique<T[]>(mCapacity);
            memcpy(tmp.get(), mData.get(), sizeof(T) * mSize);

            mData = nullptr;
            mData = std::move(tmp);
        }

        mData[mSize++] = data;
    }

    template<typename T>
    T MyStack<T>::Pop()
    {
        if (mSize == 0)
        {
            assert(false);
            return mData[mSize];
        }

        return mData[--mSize];
    }

    template<typename T>
    const T& MyStack<T>::Top() const
    {
        if (mSize == 0)s
        {
            assert(false);
        }

        return mData[mSize - 1];
    }

    template<typename T>
    void MyStack<T>::Clear()
    {
        memset(mData.get(), 0, sizeof(T) * mSize);
        mSize = 0;
    }

    template<typename T>
    unsigned int MyStack<T>::GetSize() const
    {
        return mSize;
    }

    template<typename T>
    unsigned int MyStack<T>::GetCapacity() const
    {
        return mCapacity;
    }
}