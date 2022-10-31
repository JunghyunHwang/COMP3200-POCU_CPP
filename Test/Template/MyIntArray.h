#pragma once
#include "Vector.h"

namespace practice
{
    template <typename T>
    class MyIntArray
    {
    public:
        MyIntArray();
        bool Add(const T& data);
        unsigned int GetSize() const;
        T& operator[](unsigned int i);

    private:
        enum { MAX = 3 };
        unsigned int mSize;
        T mArray[MAX];
    };

    template <typename T>
    MyIntArray<T>::MyIntArray()
        : mSize(0)
    {
    }

    template <typename T>
    unsigned int MyIntArray<T>::GetSize() const
    {
        return mSize;
    }

    template <typename T>
    bool MyIntArray<T>::Add(const T& data)
    {
        if (mSize >= MAX)
        {
            return false;
        }

        mArray[mSize++] = data;

        return true;
    }

    template <typename T>
    T& MyIntArray<T>::operator[](unsigned int i)
    {
        return mArray[i];
    }
}