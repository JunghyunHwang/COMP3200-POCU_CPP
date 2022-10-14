#include "MyString.h"

namespace test
{
    MyString::MyString(const char* str)
        : mCapacity(32)
        , mSize(0)
    {
        const char* pStrEnd = str;

        while (*pStrEnd != '\0')
        {
            ++pStrEnd;
        }

        size_t strLength = pStrEnd - str;

        if (strLength >= mCapacity)
        {
            mCapacity *= 2;
        }

        mStr = new char[mCapacity];

        for (size_t i = 0; i < strLength; ++i)
        {
            mStr[i] = str[i];
        }
    }

    MyString::MyString(const MyString& other)
        : mCapacity(other.mCapacity)
        , mSize(other.mSize)
    {
        mStr = new char[mCapacity];

        for (size_t i = 0; i < mSize; ++i)
        {
            mStr[i] = other.mStr[i];
        }
    }

    MyString::~MyString()
    {
        delete[] mStr;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        delete[] mStr;

        mCapacity = rhs.mCapacity;
        mSize = rhs.mSize;
        mStr = new char[mCapacity];

        for (size_t i = 0; i < mSize; ++i)
        {
            mStr[i] = rhs.mStr[i];
        }

        return *this;
    }

    void MyString::SetCapacity(int capacity)
    {
        mCapacity = capacity;
    }

    char* MyString::GetCString() const
    {
        return mStr;
    }
}